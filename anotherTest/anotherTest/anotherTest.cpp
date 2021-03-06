// anotherTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 

int fact(int num);

int main()
{


	//Arrays (Arrays are just boxes)
	double numOfBoxes[5] = { 6,7,8,9,10 };   //Note that every double box is 8 bytes => 5 boxes * 8  = 40 bytes
	int arr[5] = { 4,5,6,7,8 };             //Note that every int box is 4 bytes => 5 boxes * 4 = 20 bytes
	char charArr[5] = { 'a','b','c','d','e' };   //Note that every char box is 1 byte => 5 boxes * 1 byte = 5 bytes

	std::cout << "\nHellow World.\n";

	std::cout << "\n\n\nAn array of 5 character boxes has the size of: " << sizeof(charArr) << " bytes." << std::endl; //Prints: 5 bytes

	std::cout << "An array of 5 integer boxes has the size of: "
		<< sizeof(arr) << " bytes." << std::endl; //Prints: 20 bytes

	std::cout << "An array of 5 double boxes has the size of: "
		<< sizeof(numOfBoxes) << " bytes." << std::endl; //Prints: 40 bytes

														 //This part is not being printed, Why?


	std::cout << "\n\n" <<  fact(6) << "\n\n";

    return 0;
}


int fact(int num) {

	if (num == 0 || num == 1) {
		return  1;
	}

	int sum;
	sum = num * fact(num - 1);

	return sum;
}
