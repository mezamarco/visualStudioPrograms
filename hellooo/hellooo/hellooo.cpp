// hellooo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream> 

class Car {

protected:
	int id;
	int year;
	int doors;
	std::string model;
	static int carCounter;
public:
	virtual void run() = 0;
};

int Car::carCounter = 0;


class Toyota : public Car {


public:
	Toyota() {
		id = Car::carCounter;
		year = 2000;
		doors = 4;
		model = "Toyota";

		++Car::carCounter;
	}
	void run() {
		std::cout << "the car is running";
	}
	void toString(){
		std::cout << "\n\nThis is a : " << model << "\n\n";
	}

};


int main()
{

	Toyota myCar;
	myCar.run();
	myCar.toString();
    return 0;
}

