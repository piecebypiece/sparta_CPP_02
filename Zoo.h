#pragma once
#include "Animal.h"
#define MAX_ANIMALS 10
class Zoo 
{
private:
    Animal* animals[MAX_ANIMALS]; // 동물 객체를 저장하는 포인터 배열
	int count = 0; // 현재 동물의 수를 저장하는 변수 
public:
    // 동물을 동물원에 추가하는 함수
    // - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
    // - 같은 동물이라도 여러 번 추가될 수 있습니다.
    // - 입력 매개변수: Animal* (추가할 동물 객체)
    // - 반환값: 없음
    bool addAnimal(Animal* animal);

    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    // - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    void performActions();

    // Zoo 소멸자
    // - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
    // - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    ~Zoo();
	Zoo() = default; // 기본 생성자
};
