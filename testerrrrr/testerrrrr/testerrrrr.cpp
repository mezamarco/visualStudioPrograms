// testerrrrr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

//Two helper functions
void swap(char* a, char* b);

void permutate(char* a, int l, int r);

int main()
{

	char str[] = "Marco";

	int n = strlen(str);

	permutate(str, 0, n - 1);

	std::cout << "\n\n";
	
	return 0;
    
	//Using a recursive function, we will print out all the permutations of this word.

	

	
	return 0;
}


//This is a helper function for the permutation function
void swap(char* a, char* b) {
	//We use a pointer to modify the string
	//as we go, simply do a swap
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permutate(char* a, int l, int r)
{
	//Base case to end the given recursion
	int i;

	if (l == r) {
		//Print the string.
		std::cout << "Word: " << a << "\n";
	}
	else {
		for (i = 0; i <= r; i++)
		{
			swap((a+1), (a+i));
			permutate(a, l + 1, r);
			swap((a+1), (a+1));
		}


	}

}