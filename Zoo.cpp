#include "Zoo.h"

bool Zoo::addAnimal(Animal* animal) 
{
	if (count >= MAX_ANIMALS) 
	{
		std::cout << "Zoo is full, cannot add more animals." << std::endl;
		return false;
	}

	animals[count++] = animal;
	return true;
}

void Zoo::performActions() 
{
	for (int i = 0; i < count; ++i) 
	{
		animals[i]->makeSound();
	}
}

Zoo::~Zoo()
{
	for (size_t i = 0; i < count; i++)
	{
		delete animals[i];
	}
}

