// testingpart.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>


void print(std::vector<int> & myVect) {

	for (int i = 0; i < myVect.size(); i++) {
		for(int  j = i+1 ; j < myVect.size(); j++){
			std::cout << "i = " << i << "  and   j = " << j << std::endl;
		}
	}

}

bool isPrime(int n)
{ 
	//TO check if the value is prime
	//Then check that values: 2,3,4,..., sqrt(n) do not divide the number
	for (int i = 2; i <= sqrt(n); i++) {
		if (n% i == 0) {
			return false;
		}
	}
	return true;
}

int nFact(int n) {
	//Edgecase
	if (n < 0) {
		return -1;
	}
	else if ( n == 0) {
		return 1;
	}
	else {
		return n * nFact(n - 1);
	}

}


//We will have an overloaded function.
void permutations(std::string str);
void permutations(std::string str, std::string prefix);



int main()
{
	std::vector<int> myVect = { 1,2,3,4,5,6 };
	print(myVect);
	
	std::cout << "\n\nWhat is the square root of 64: " << sqrt(64) << std::endl;
	std::cout << "\n\n";
	
	// We will now solve the problem of checking if a number is prime
	std::cout << "Check if it is prime: ";
	int value;
	std::cin >> value;
	std::cout << "The value: " << value << " is prime? " << isPrime(value) << std::endl;
	std::cout << "\n\n";

	//We will now get the n factorial of a given number.
	std::cout << "What is the n factorial of: ";
	int number;
	std::cin >> number;

	std::cout << "The n-factorial of: " << " is = " << nFact(number) << "\n\n";
	
	//A leading whitespace will be passed to our getline
	//So we must tell our program to ignore it.
	std::cin.ignore();

	//we will now count all the permutations a single string
	std::cout << "Enter a string and we will find all its permutataions:";
	std::string myString;
	getline(std::cin, myString);

	//We have stored the string, now call the permutation function in order to get all the permutations
	permutations(myString);

	return 0;

}


void permutations(std::string str) {
	permutations(str, "");
}
void permutations(std::string str, std::string prefix) {
	if (str.length() == 0) {
		std::cout << prefix << std::endl;
	}
	else 
	{
		//For every character in our string
		for (int i = 0; i < str.length(); i++) {
			std::string remaining = str.substr(0, i) + str.substr(i + 1);

			permutations(remaining, prefix + str.at(i));
		}
	}
}