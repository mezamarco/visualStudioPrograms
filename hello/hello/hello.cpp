// hello.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

bool isValid(std::string & str, bool neg);
int main()
{
	std::string a = "hi";
	std::string b = "hi";

	std::cout << (a == b) << "\n";
    
	
	std::string numString = "3424896786866876835";
	if (numString.length > 10) {
		return 0;
	}
	bool negativeNum = false;
	
	if (numString.length() == 10) {
		if (!isValid(numString, negativeNum)) {
			return 0;
		}
	}

	int num = stoi(numString);

	std::cout << num << "\n\n";

	
	
	return 0;


}

bool isValid(std::string & str, bool neg) 
{
	if (!neg) {
		//Range   [0 to 2147483647]
		std::string theLimit = "2147483647";

	}
	
}

