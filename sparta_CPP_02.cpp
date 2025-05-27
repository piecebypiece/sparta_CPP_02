// sparta_CPP_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Zoo.h"
#include <cstdlib>
#include <ctime>

// 랜덤 동물을 생성하는 함수
// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
// - 입력 매개변수: 없음
// - 반환값: Animal* (생성된 동물 객체의 포인터)
Animal* createRandomAnimal()
{
	Animal* animal = nullptr; // Animal 포인터 초기화

	int rand = std::rand() % 3; // 0, 1, 2 중 하나의 난수 생성

	switch (rand)
	{
	case 0:
		animal = new Dog(); 
		break;
	case 1:
		animal = new Cat(); 
		break; 
	case 2:
		animal = new Cow(); 
		break;
	
	}

	return animal;
}



int main()
{
	srand(time(NULL)); // 시드 설정
	Animal* animal[] = 
	{
		new Dog(),
		new Dog(),
		new Cat(),
		new Cow(),
		new Cat(),
		new Cow(),
		new Cow(),
		new Dog(),
	};
	const int animalCount = 8;
	for (size_t i = 0; i < animalCount; i++)
		animal[i]->makeSound(); // 
	
	// 위에서 같이 해제해도 되지만 명시적인 제거와 중간의 처리 추가가 있을 수 있음으로 로직을 분리함
	// 컴파일된 코드의 양은 크게 다르지 않음.
	for (size_t i = 0; i < animalCount; i++)
		delete animal[i]; // 동적 할당된 메모리 해제
	
	std::cout << "------------------------" << std::endl;
	Zoo zoo; // Zoo 객체 생성
	for (size_t i = 0; i < MAX_ANIMALS; i++)
	{
		Animal* randomAnimal = createRandomAnimal(); // 랜덤 동물 생성
		if (zoo.addAnimal(randomAnimal) == false) // Zoo에 동물 추가
			//동물원의 최대 동물 크기를 초과했음.
			delete randomAnimal;
	}
	zoo.performActions(); 
	// 할당된 Animal 들은 지역변수 zoo가 제거되면서 호출되는 zoo 소멸자에 의해 모두 제거됨
}

