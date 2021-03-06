// Chapter1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

bool checkUnique(std::string & myString);
bool checkPermutation(std::string a, std::string b);
std::string urlify(std::string str, int capacity);
bool checkPalindromePermutation(std::string theString);
bool oneAway(std::string a, std::string b);

//Get the permutation of a string, it will need a helper function.
void getPermutation(std::string word);
void getPermutation(std::string word, std::string prefix);



std::string stringCompression(std::string myString);
void stringReverse(std::string & a);
void printMatrix(int m[][10]);



int binarySearch(int arr[], int l, int r, int x);

//ROtate a matrix by 90 degrees to the right, value by value.
void rotateMatrix(int myMatrix[][5], int n);



int main()
{

	//How do we get the size of an array
	int myarr[3] = { 1,3,4 };
	//How do we get the length
	//We get the size of the entire array in this case we get 12 bytes then we divide by the size of the first element
	//In this case the size of the first element is an integer, therefore 12/4 = 3 element in our array.
	int mySizeArray = sizeof(myarr) / sizeof(*myarr);
	




	
	std::string myString = "carro";
	std::cout << checkUnique(myString) << "\n";

    
	std::string a = "fdasfdsafdgsasdgf";
	std::string b = "fdasfdsafdgsasgdf";

	bool checker = checkPermutation(a, b);
	std::cout << "\nIs this pair a permutation: " << a << " , " << b << " : " << checker << "\n\n";
	std::string theString = "Mr John Smith        ";

	std::cout << "\n" << urlify(theString,13) << "ENDED\n";

	theString = "Tact Cao     ";
	checkPalindromePermutation(theString);
	std::cout << "\n"; 


	//Solve the one away problem
	a = "turtle";
	b = "tutle";
	std::cout << "\n\nDo we have one away: "<<oneAway(a, b);

	std::cout << "\n";

	a = "aaabbbbbrrrxaaaaav";

	std::cout << "Compressing: " << a << "\tInto: " << stringCompression(a) << "\n\n";




	//Lets create a NXN matrix and then we will rotate it
	int arr[5][5] = { {1,2,3,4,5},{ 1,2,3,4,5 },{ 1,2,3,4,5 },{ 1,2,3,4,5 },{ 1,2,3,4,5 } };

	
	//Lets print out the 2-D array
	for (int i = 0; i < 5; i++) {
		std::cout << "\n";
		for (int j = 0; j < 5; j++) {
			std::cout << arr[i][j] << "  ";
		}
	}
	

	//Lets reverse a string
	a = "helloIamHungry";
	stringReverse(a);
	a = "helloHungry";
	stringReverse(a);

	std::cout << "\n\n";



	//Lets solve the zero matrix problem
	//Lets create our matrix with random elements and then we will print out all the values to see
	//our matrix
	int myMatrix[10][10];
	//Let give it random elements
	srand(time(NULL));
	for (int m = 0; m < 10; m++) {
		for (int n = 0; n < 10; n++) {
			//The random element range will be between:[0-50]
			int randomValue = rand() % 51;
			myMatrix[m][n] = randomValue;
		}
	}
	std::cout << "Our Matrix:\n";
	//We have populated our Matrix, lets print the matrix.
	printMatrix(myMatrix);
	std::cout << "\n\n";

	//How do we solve the Zero matrix problem? 
	//If we find a 0 in our matrix then we have to set that row and column to zero
	bool row[10] = { 0 };
	bool column[10] = { 0 };

	//Traverse the Matrix and set the row to 1 and column to 1 in the given position
	for (int m = 0; m < 10; m++) {
		for (int n = 0; n < 10; n++) {
			
			if (myMatrix[m][n] == 0) {
				row[m] = 1;
				column[n] = 1;
 			}
		}
	}

	//traverse the row array and if we have a one then we have to make all the elements in this row equal to 0  
	for (int p = 0; p < 10; p++) {
		if (row[p]) {
			//Make all the element of this row equal to zero
			for (int r = 0; r < 10; r++)
			{
				myMatrix[p][r] = 0;
			}

			
		}
	}

	//traverse the column array and if we have a one then we have to make all the elements in this column equal to 0  
	for (int p = 0; p < 10; p++) {
		if (column[p]) {
			//Make all the element of this row equal to zero
			for (int r = 0; r < 10; r++)
			{
				myMatrix[r][p] = 0;
			}

		}
	}

	//We have solve the zero matrix problem, so lets print out this new matrix
	std::cout << "\n\nThe Solution Matrix: ";
	printMatrix(myMatrix);
	std::cout << "\n\n";


	return 0;
}




//ALgorithm: Determine if a string has all unique characters
//What if you cannot use additional data structures?

bool checkUnique(std::string & myString)
{
	std::vector<bool> chFreq(256, 0);

	if (myString.length() > 256) {
		//Pigeonhole principal
		return false;
		//There exists a repeated characted.
	}


	for (char ch : myString) {

		int index = (int)ch;

		if (chFreq[index] == 1) {
			return false;
		}
		chFreq[index] = chFreq[index] + 1;
	}
	return true;


	/* We now solve it without additional data structures(Bad solutions, but they work)
	
	for(char ch: myString){
		
			compare the given character with the rest of the characters   O(n^2) time complexity
			or
			sort the string, O(n(log n)), then check previous with the current

	
	}
	
	
	*/

}


//ALgorithm: Given two string of the same length, decide if one is a permutaion of the other
bool checkPermutation(std::string a, std::string b) {

	//Check the length of the strings
	if (a.length() != b.length()) {
		return false;
	}

	//We will now create one array, one for the first string.
	//THe size of the array is 128 with all element 0;


	int theArr[128] = { 0 };

	//Traverse the first string and then modify the first Arr properly
	for (char ch : a) {
		theArr[(int)ch] = theArr[(int)ch] + 1;
	}
	//Traverse the second string and start deducing the arr properly.
	for (char element : b)
	{
		theArr[(int)element] = theArr[(int)element] - 1;
		if (theArr[(int)element] < 0){
			return false;
		}
	}
	//Becasue of the same length, since there are no negative values then there are no positive values
	//Therefore return true

	return 1;

}

//Algorithm: URL-ify a string, For every space replace with %20,   and  remove the data after the True string counter
std::string urlify(std::string str, int capacity) {

	std::string url = "";
	//traverse the string and start replacing
	for (int i = 0; i < capacity; i++) {
		//If we find a space then we have to replace it
		//ASCII of space is 32
		char ch = str.at(i);

		if ((int)ch == 32) {
			url = url + "%20";
		}
		else {
			//Insert the given character
			url = url + ch;
		}
	}

	return url;


}

//ALgorithm : Palindrome Permutatation: Given a string , Check if it is a permitation of a palindrome, it oka to ignore spaces.
bool checkPalindromePermutation(std::string theString) {

	//Get the actual number of characters(ignore spaces), and make the Uppercase values into lowerCase
	int size = 0;

	for (int i = 0; i <theString.length() ; i++){
		char ch = theString.at(i);
		int chVal = (int)ch;


		if (chVal != 32) {
			++size;
		}
		
		if (chVal < 97  && chVal != 32) 
		{
			//We need to make this uppercase into a lowercase
			theString.at(i) = int(chVal + 32);
		}

	}

	std::cout << "\nThe string is now: " << theString << "\n";
	std::cout << "\nThe actual size is:  " << size << "\n";

	//Get the frequency vector
	std::vector<int> myVect(256, 0);

	for (char theCh : theString) {
		int index = (int)theCh;

		myVect[index] = myVect[index] + 1;
	}



	//If we have an even size, then every value in our frequency vector should be modded by 2 and should equal to zero
	if (size % 2 == 0) {
	
		//All the elements in the vector must be equal to 0 and then we have a palindrome
		for (int flag : myVect)
		{
			if (flag % 2 != 0) {
				std::cout << "Even size, but no palidrome can be formed";

				return false;
			}
		}
		//All the element are zero, then we have a palidrome
		std::cout << "Even size, PALINDROME CAN BE FORMED because of the matches";

		return true;
	}
	else {
		//We have odd size

		//There can only be one odd counter
		int oddCounter = 0;
		
		//All the elements in the vector must be 0 and then we have a palindrome
		for (int flag : myVect)
		{
			if (flag % 2 == 1) {
				++oddCounter;

				if (oddCounter == 2) {
					std::cout << "Odd size, but no palidrome can be found because more than 2 odd counters";
					return false;
				}
				
			}
		}
		//All the element are zero and except one is odd, then we have a palidrome
		std::cout << "Odd size, PALINDROME CAN BE FORMED because of the only one odd";

		return true;


	}


}


//Algorithm: One Away, Three types of edits, (insert, remove,replace) ,    We get as input two strings check that string are one away
bool oneAway(std::string a, std::string b) {

	//The string size must be one away or equal in order to be valid strings
	int sizeA = a.length();
	int sizeB = b.length();

	int count = sizeA - sizeB;
	std::cout << "VOUT : "<<count;
	if (count == 0 || count == 1 || count == -1) {

		//Valid strings
		//Case where the have the same size
		if (count == 0) {
			//Then we have one replacement or no replacements

			//NO replacement, same string
			if (a == b) {
				std::cout << "\nNo change\n";

				return true;
			}
			//One replacemant
			for (int i = 0; i < sizeA; i++) {
				int diffChCounter = 0;

				if (a.at(i) != b.at(i)) {
					++diffChCounter;

					if (diffChCounter == 2) {
						std::cout << "\ntwo replacemants\n";

						return false;
					}
				}
			}


			//Conditions passed.
			return true;

		}


		//They have inserted a character or removed a character
		//Recall that a is our original string

		// a should be the small one and b should be the biggers one
		//To treat both cases as inserting an element
		if (count == 1) {
			std::string temp = a;
			a = b;
			b = temp;
		}
		//We treat both cases as insert

		unsigned int index1 = 0;
		unsigned int index2 = 0;
		while(index1 < a.length() && index2 < b.length()){
		
			if (a.at(index1) != b.at(index2)) {

				//Very important, we only allow for one: (not equal)
				if(index1 != index2)
				{
					return false;
				}

				//Increment the second index
				++index2;

			}
			else{
				//Valid comparison
				++index1;
				++index2;

			}
		
		
		}
		return true;


	}
	else
	{
		std::cout << "\n\nNO valid Size\n\n";
		return false;
	}


	return 1;

}


//Algorithm: String compression,    if aaabbcc then we should get the string a3b2c2, if compression is larger then return the original string

std::string stringCompression(std::string myString){

	std::string ansStr = "";
	for (int i = 0; i < myString.length(); i++) {

		char ch = myString.at(i);
		int count = 1;

		//Careful with the bounds, mainly we have to be careful with the last element if it is a new character.
		if( i !=myString.length()-1)
		{ 
			while(ch == myString.at(i+1))
			{
				++count;
				++i;
				if (i == myString.length()-1) {
					break;
				
				}
			}
		}
		//Convert the number into a string
		std::string numString = std::to_string(count);

		ansStr = ansStr + ch + numString;

	}

	if (myString.length() < ansStr.length()) {
		return myString;
	}

	return ansStr;
}


void stringReverse(std::string & a) {

		//Lets reverse the string and print it out
		
	int i = 0;
	int j = a.length() - 1;
	std::cout << "\nOriginal String: " << a << "\n\n";

	int temp;
	while (i < j) {
		temp = a.at(i);

		a.at(i) = a.at(j);
		a.at(j) = temp;

		++i;
		--j;
	}
	std::cout << "Reversed: " << a << "\n\n";
}


void printMatrix(int m[][10]) {
	//Use two for loops to print out all the elements in the matrix
	for (int i = 0; i < 10; i++) {
		std::cout << "\n";
		for (int j = 0; j < 10; j++)
		{
			std::cout << m[i][j] << "\t";
		}
	}
}


//Get the permutation of a string, it will need a helper function.
void getPermutation(std::string word) {
	getPermutation(word, "");
	return;
}
void getPermutation(std::string word, std::string prefix)
{
	
	//Check if the entire word is in the prefix
	if (word.length() == 0) {
		std::cout << prefix << "\n";
	}
	else {

		//Do this for every character in the string
		for (int i = 0; i < word.length(); i++) {
		
			//Get all the character from our string except for the current character
			std::string rem = word.substr(0, i) + word.substr(i + 1);
			//Call the permutation function, with (rem) and the (prefix plus the current character)
			getPermutation(rem, prefix + word.at(i));
		}
	}
	return;
}




//Binary Search algorithm, we return the index position if we find the given element 
int binarySearch(int arr[], int l, int r, int x) {

	//For the given section,index positions l to r
	while (l <= r) {

		//Get the midle index, use the ceiling instead of the floor
		int m = 1 + ((r - l) / 2);

		//Now check if the middle index value is equal to our element
		if (arr[m] == x) {
			return m;
		}


		//If x is greater than our middle value, then we focus on the right side
		if (x > arr[m]) {
			l = m + 1;
		}

		//If x is smaller that our middle value, then we focus on the left side
		if (x < arr[m]) {
			r = m - 1;
		}
	}
		//If we reach here then we did not find the given  element, therefore return -1
		return -1;
	
	

}


void rotateMatrix(int myMatrix[][5], int n) {

	//We will rotate the matrix value by value from the outside square into the inside.
	//How many inner squares we will rotate. Just divide by two. 
	for (int layer = 0; layer < n / 2; layer++) {
		
		//Determine the bounds
		int first = layer;
		int last = n - layer - 1;

		//We are ready to switch all the values, iterate thorugh all the elements of the given layer
		for (int i = 0; i < last; i++) {
			
			int offset = i - first;

			//Save the top, so now overwrite the top
			int top = myMatrix[first][i];

			//left to top 
			myMatrix[first][i] = myMatrix[last-offset][first];
			
			//bottom to left 
			myMatrix[last-offset][first] = myMatrix[last][last - offset];

			//right to bottom
			myMatrix[last][last - offset] = myMatrix[i][last];
			
			//top to right 
			myMatrix[i][last] = top;

		}

	
	}

}

