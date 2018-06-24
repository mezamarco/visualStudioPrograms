// testerfive.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Animal {

private:
	static int animalCounter;


public:
	//Static function
	static void incrementCounter() {
		std::cout << "Count " << ++animalCounter << "\n";
	}
};

int Animal::animalCounter; //Tell the compiler that we are using a static variable

int main()
{
	Animal theAnimal;

	//Calling a static method properly
	Animal::incrementCounter();

    return 0;
}

