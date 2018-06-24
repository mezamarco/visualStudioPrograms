// DeckOfCards.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//We need a struct for a suit class
struct Suit {
private:
	int value;
	//Custom Constructor
	Suit(int val) {
		this->value = val;
	}

public: 

	//Getter function for the value of the suit
	int getValue() {
		return value;
	}
	
	static Suit getSuitFromValue(int value);
};



int main()
{
    return 0;
}

