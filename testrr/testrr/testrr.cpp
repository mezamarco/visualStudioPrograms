// testrr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string> 


class GameCharacter{
public:
	//Data memebers
	std::string name;
	int capacity;
	int used;
	std::string* toolHolder;


	static const int DEFAULT_CAPACITY = 5;
	//Overloaded insertion operator, this is a friend function
	friend std::ostream& operator<<(std::ostream& os, const GameCharacter& gc);



	//Default Constructor
	GameCharacter(std::string name = "John" , int capacity = DEFAULT_CAPACITY);
	
	//Copy Constructor
	GameCharacter(const GameCharacter& source);

	//Overloaded Assignment
	GameCharacter& operator=(const GameCharacter& source);

	//Desstructor
	~GameCharacter();

	//Insert a new tool into thte tool handler
	void insert(const std::string& toolName);

	

};


//Define our custom constructor
GameCharacter::GameCharacter(std::string n, int cap) {
	name = n;
	capacity = cap;
	used = 0;
	toolHolder = new std::string[cap];
}

//Define our Copy Constructor
GameCharacter::GameCharacter(const GameCharacter& source) {
	std::cout << "Copy constructor has been called." << std::endl;

	//Take in the name of the source and place it into this copied object
	name = source.name;
	used = source.used;
	capacity = source.capacity;

	toolHolder = new std::string[source.capacity];
	//We need to populate this toolHolder with the same content as the source
	//THerefore, we must use a copy function
	//This function take in three parameters
	//The begginning, the end, and where we will place this contents
	//copy(source.toolHolder, source.toolHolder + used, toolHolder);
	//Even better lets use a for loop to copy all the elements
	for (int i = 0; i < used; i++) {
		toolHolder[i] = source.toolHolder[i];
	}
}

//Lets define our overloaded assignment operator
GameCharacter& GameCharacter::operator=(const GameCharacter& source)
{
	//Note that there should exist an object so we can copy the data from another object
	std::cout << "Overloaded Assignment called." << std::endl;
	
	//Check for self assignment
	//gc1 = gc1; //Do not allow this because we are just wasting time
	//Note: this is an pointer and the *this is the actual object
	if (this != &source) {
		//We do not have self assignment so continue with deep copy
		name = source.name;
		used = source.used;
		capacity = source.capacity;
		for (int i = 0; i < used; i++) {
			toolHolder[i] = source.toolHolder[i];
		}
	}
	return *this;
}


//Lets define the deconstructor
GameCharacter::~GameCharacter() {
	std::cout << "The deconstructor has been called\n";

	//Delete what we allocated into the heap
	delete[] toolHolder;

}

//We need to define the insert function
void GameCharacter::insert(const std::string& toolName) {
	if (used == capacity) {
		std::cout << "Tool holder is full\n";
	}
	else {
		toolHolder[used] = toolName;
		used++;
	}
}

//Define our friend function
std::ostream& operator<<(std::ostream& os, const GameCharacter& gc) {
	os << "Game Character: " << gc.name << "\nhas the following: \n" << "| ";
	
	for (int i = 0; i < gc.used; i++) {
		os << gc.toolHolder[i] + " | ";
	}
	return os;
}

/*

//Assignment overloaded
MyClass& operator=(cont MyClass& rhs);
//Look at this example to further understand this.
x = y;
//But in the backgroud this is runnning.
x.operator=(y);
//operator x is being invoked on the object x
*/
 




int main()
{
	//Lets create a game character and then insert some tools.

	GameCharacter playerOne;

	playerOne.insert("Potion");

	playerOne.insert("Crossbow");
	playerOne.insert("Sword");
	

	std::cout << playerOne << "\n\n";


    return 0;
}



//I should learn how to overload other operators



std::unordered_map<int, int> myMap;
int counter = 0;
//SOlviing for an unsorted array
for (int i = 0; i < arr.length(); i++) {
		for (int m = 0; m < arr.length(); m++) {
			
			int value = arr[i][m];
			
			if (myMap.find[value]) {

				int complement = k - value;

				if (myMap.find(complement) != myMap.end()) {
					//Only place the smaller num on the vector array
					int smaller = (value < complement) ? value : complement;

					if (smaller <= (k / 2)) {
						//place in vector
						myVect.push_back(smaller);
					}
				}
				bt yn=o
				myMap[value] = i;

			}

		}
	}


}