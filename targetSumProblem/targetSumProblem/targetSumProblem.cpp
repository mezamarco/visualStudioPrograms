// targetSumProblem.cpp : Defines the entry point for the console application.
// We will solve the targetSum prblem, the input for our function will be an vector and the int target sum


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <ctime>


//Function prototype
void findTargetSum(std::vector<int> &myVectorData, int targetSum);

int main()
{
	std::cout << "We will solve the target sum problem\n"; 
	
	int targetSum;
	int dataSize;

	std::cout << "What is the targetSum: ";
	std::cin >> targetSum;


	srand(time(NULL));

	//Lets create our data vector with random elements 
	std::cout << "\nWhat will be the size of the data vector: ";
	std::cin >> dataSize;
	
	std::vector<int> myVectorData;
	int randVal;
	std::cout << "\n\nThe data vector holds: ";
	for (int i = 0; i < dataSize; i++) {
		//Our random value will be between: (0 - 25)
		randVal = (rand() % 26 );
		std::cout << randVal << "  ";
		//Place the random value into our data vector.
		myVectorData.push_back(randVal);
	}
	std::cout << "\n\n";
	findTargetSum(myVectorData, targetSum);

    return 0;
}

void findTargetSum(std::vector<int> &myVectorData, int targetSum) {

	//Create our complementSet.
	std::unordered_set<int> compSet;
	
	//For each element in the vector
	for (int value : myVectorData) {
		
		//If we find the value in the compSet then we have found a pair.
		if (compSet.find(value) != compSet.end()) {
			std::cout << "PAIR:(" << value << "," << targetSum - value << ")"<<std::endl;
			
		}

		//Add the complement of our value into the complementSet
		//Only for valid values
		if (targetSum - value >= 0) {
			compSet.insert(targetSum - value);
		}
	}

	std::cout << "We are looking for: \n";
	for (int compValue : compSet) {


		std::cout << compValue << " " ;
	}
	
	std::cout << "NO PAIR\n\n\n";

}
