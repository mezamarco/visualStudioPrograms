// testing.cpp : Defines the entry point for the console application.
//Print all the prime numbers until the user click on Ctrl+C

#include "stdafx.h"
#include <iostream>

int main()
{
	/*
	bool isPrime = true;
	int  number = 3;
	
	while (1) {
		for (int i = 2; i < number; i++)
		{
			if (number % i == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			std::cout << number << std::endl;
		}

		++number;
		isPrime = true;
	}
    return 0;
	*/


	//Lets convert the integer into its binary form
	std::cout << "We will now convert the integer into its binary form.\n"
			<< "\nWhat integer to you want to convert to Binary: ";

	unsigned int value;

	std::cin >> value;

	std::cout << "\n";
	//Now we must convert the value into binary form
	//Get the largest value that will divide the value

	unsigned int answer = 0;
	
	for (int m = 31; m >= 0; m--) {
	
		if (value / pow(2,m) >= 1) 
		{
			std::cout << "1";
			//std::cout << "\n\nThe value is: "<<value << "\tThe divider is: " << m;
			int divisor = pow(2, m);

			//std::cout << "\nTherefore the int divider is: " << divisor ;
			
			//Store the binary bit into the answer by using the or expression
			answer = answer | divisor;
			//Reduce the actual value.
			value = value - divisor;
		}
		else {
			std::cout << "0";
		}
	}
	std::cout <<"\n\n\nTHE BINARY IS:"<< answer << std::endl;



}

