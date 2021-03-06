// parkingLot.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>


//We will have three car types and therefore we should use a enum class
enum VehicleSize {small, medium, large};



//Build a class for the parking lot
class ParkingLot {

public:
	//This will be the parking spots 
	int parkingArr[300] = { 0 };
	bool isFull = 0;
	int startIndex = 0;.
};


//Build the abstract class, this is the vehicle class.
class Vehicle {

protected:
	VehicleSize carType;
	std::string licensePlate;
	int spotsNeeded;
	//We will have a static integer that will tell us how many vehicles we have constructed.
	static int numOfVehicles;


public:
	//No custom constructor nor a default constructor because this will be an abstract class
	//I will need getter for all the member types.
	int getSpotsNeeded() {
		return spotsNeeded;
	}
	VehicleSize getVehicleType() {
		return carType;
	}
	std::string getLicensePlate() {
		return licensePlate;
	}


	//We need a way to insert the given vehicles.
	virtual bool insert(ParkingLot& parking) = 0; 
	//We need a way to remove the given vehicles.
	virtual	bool remove(ParkingLot& parking) = 0;
	//We need a way to find the given vehicles.
	virtual bool find(ParkingLot& parking) = 0;
	//Will the given vehicle fit in the parking spot.
	virtual bool fitInSpot() = 0;
};


//Let the compiler know that we are using a static variable
int Vehicle::numOfVehicles = 0;


//We will now declare three classes, all the three classes will inherit the data and behaviors from the Vehicle class 
//Define their data members and behaviors

class Motorcycle : public Vehicle {

public:
	//Define the member variable, using a custom constructor
	Motorcycle(std::string license) {
		this->carType = small;
		this->licensePlate = license;
		this->spotsNeeded = 1;
	
		++Vehicle::numOfVehicles;
	}

	//The is the pure virtual function  that will let us know if the given vehicle will fit in the parking spot.
	bool fitInSpot() {
	
		return 1;
	}
	//We need a way to insert the given vehicles.
	bool insert(Vehicle theVehicle) {

		return 0;
	}

	//We need a way to insert the given vehicles.
	bool remove(Vehicle theVehicle) {

		return 0;
	}

	//We need a way to insert the given vehicles.
	bool find(Vehicle theVehicle) {

		return 0;
	}





};
class Car : public Vehicle {

public:
	//Define the member variable, using a custom constructor
	Car(std::string license) {
		this->carType = medium;
		this->licensePlate = license;
		this->spotsNeeded = 3;

		++Vehicle::numOfVehicles;
	}
	//The is the pure virtual function  that will let us know if the given vehicle will fit in the parking spot.
	bool fitInSpot() {

		return 1;
	}


	//We need a way to insert the given vehicles.
	bool insert(ParkingLot& parking) = {

		return 0;
	}

		//We need a way to insert the given vehicles.
		bool remove(ParkingLot& parking) {

		return 0;
	}

	//We need a way to insert the given vehicles.
	bool find(ParkingLot& parking) {

		return 0;
	}

};

class Bus : public Vehicle {

public:
	//Define the member variable, using a custom constructor
	Bus(std::string license) {
		this->carType = large;
		this->licensePlate = license;
		this->spotsNeeded = 5;

		++Vehicle::numOfVehicles;
	}

	//The is the pure virtual function  that will let us know if the given vehicle will fit in the parking spot.
	bool fitInSpot() {
	
		return 1;
	}


	//We need a way to insert the given vehicles.
	bool insert(ParkingLot& parking) = {

		return 0;
	}

		//We need a way to insert the given vehicles.
		bool remove(ParkingLot& parking) {

		return 0;
	}

	//We need a way to insert the given vehicles.
	bool find(ParkingLot& parking) {

		return 0;
	}
};









int main()
{
    return 0;
}

