// simpleProblems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

int findMissing(std::vector<int> & myVect);
int main()
{
	//We will solve the find the missing number problem,
	//note that we can get the total sum at the begginining and then subtract until we ge the result


    return 0;
}


int findMissing(std::vector<int> & myVect) {
	
	//Determine is the last number is even or odd to get the total value

	int total;

	if (n % 2 == 0)
	{
		//We have an even number, implies we can form an even amount of pair, but the sum of each pair is plus 1
		total = (n / 2) * (n + 1);
	}
	else {
		//We have an odd number, implies we can for an even amount of pairs by adding the value zero
		//therefore (n+1 /2) pairs, but then the sum of each pair is n
		total = (n+1/2) * n
	}

}


