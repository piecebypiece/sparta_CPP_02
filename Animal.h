#pragma once
#include <iostream>

class Animal
{
	
public:
	virtual void makeSound() = 0;

	virtual ~Animal() = default; // Virtual destructor for proper cleanup of derived classes
};


//Dog, Cat, Cow

class Dog : public Animal
{
public:
	void makeSound() override
	{
		std::cout << "Woof!\n" << std::endl ;
	}
};

class Cat : public Animal
{
public:
	void makeSound() override
	{
		std::cout << "Maw~\n" << std::endl;
	}
};

class Cow : public Animal
{
public:
	void makeSound() override
	{
		std::cout << "umoooo~~\n" << std::endl;
	}
};