#pragma once
#include "Node.h"

class LinkedList {
public:
	int nodeCounter;
	Node* rootPtr;
	Node* mid;

	LinkedList();

	//Insert function prototype
	void insert(int value);

	void printAll();


	void removeDuplicates();
	void getKthToLast(int n);
	void deleteMiddleNode(Node* mid);

	//The sum of two linked lists
	//Look at the leetcode answer

	bool isPalindrome();






};