// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

int main()
{

	std::cout << "What happens when shifting the number integer 3\n";
		
	int number = 4;
	int numOfBits = sizeof(number)*8;
	
	//number = number >> 2;
	std::cout << "How many bits in the integer: " << numOfBits << "\n";
	
	for (int i = 1; i <= numOfBits; i++) {
		//Place a one in the correct position and  then We will get the binary in that position, 
		//but we have to shift back this bit into the rightmost side to get the actual bit.
		int bitTracker = (number & (int)pow(2,numOfBits-i) ) >> (numOfBits-i);


		//CHeck if the xponnent function in c++
		
		std::cout << bitTracker;
	}
	std::cout << "\n\n\n";
		return 0;
}

