// inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Car {
private:

	int miles;
	int doors;
	int year;
	std::string model;



public:
	//Constructor
	Car() {
		miles = 0;
		doors = 4;
		model = "noMODEL";
		year = 2000;

		//Inside the class there is no need to include the class name
		Car::numOfCars++;

		std::cout << "\nCreated :  " << numOfCars;
	}


	//By default is is initialized to zero, this class and all its subclasses have access to this variable
	static int numOfCars;



	//We need getter and setters for the model car type and the year of the car.

	int getYear() {
		return this->year;
	}
	std::string getModel() {
		return this->model;
	}


	//Setters
	void setYear(int val) {
		this->year = val;

	}

	void setModel(std::string str)
	{
		this->model = str;
	}

	void toString() {
		std::cout << "\nInfo of the car: \nMile = " << miles << "\nDoors: " << doors << "\nModel: " << model << "\nYear: " << year;
		std::cout << "\n\n\n";
	}


	//Method overidding example
	void honk(){
		std::cout << "We are honking the car\n"; 
	}
};


class Honda : public Car {
	
public: 
	//Honda constructor, NOTE that all the variable in the Car class are inherited, but they are still private
	Honda() {

		this->setYear(100);
		this->setModel("Honda");
	}

	//Method overidding example
	void honk() {
		std::cout << "We are honking the Honda civic\n";
	}
};


int Car::numOfCars;


int main()
{

	//Create a Car object and then create a Honda object
	Car myCar;

	myCar.toString();

	//Create a Honda object
	Honda myHonda;
	myHonda.toString();


	std::cout << "THe number of car that we have created is: " << Car::numOfCars << "\n\n" ;


	//Method overidding example
	myCar.honk();
	myHonda.honk();



	//	
	int value = 3;
	double val = 34.22;
	std::cout << "Size of integer: " << sizeof(value) << "\n";
	std::cout << "Size of  double: " << sizeof(val) << "\n";

    return 0;
}

