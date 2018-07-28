#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
#include <unordered_map>

LinkedList::LinkedList() {

	nodeCounter = 0;
	rootPtr = nullptr;
	mid = nullptr;

}

void LinkedList::insert(int value) {

	//Create our node object
	Node* newerNode = new Node(value);

	if (value == 6) {
		mid = newerNode;
	}



	//If we have no root, we need to insert the new node into our root
	if (rootPtr == nullptr) {
	
		rootPtr = newerNode;
		return;
	}


	//Root is not empty, therefore we must place this new node into the end of our list
	//use a current pointer to keep track of our position, start in the root position
	Node* current = rootPtr;
	
	while (current->nextPtr != nullptr) {
	
		current = current->nextPtr;
	}
	//The next pointer is pointing to null, so place the newer node in this position
	current->nextPtr = newerNode;
	return;

}
void LinkedList::printAll() {
	//Print all the elements in our linkedList
	//Starting in our root position
	Node* current = rootPtr;

	while (current != nullptr) {
		std::cout << current->data << "   ";
		current = current->nextPtr;

	}

}

void LinkedList::removeDuplicates() {
	//Remove all the duplicates from our Linked list
	//We will use a has map to determine if we already saw the given value
	std::unordered_map<int, int> myMap;

	//For all the element in the LinkedList
	//Starting at the root node
	Node* current = rootPtr;
	

	//Insert the first value into our map
	myMap[current->data] = 0;
	int i = 1;

	

	while (current->nextPtr != nullptr) {
		//Place the contents into our map if it is not a duplicate.

		if (myMap.find(current->nextPtr->data) == myMap.end()) {
			//We reach the map end, therefore the element does not exist in our map, so store this value
			//Move to the next node and save its value.
			current = current->nextPtr;

			myMap[current->data] = i;
			++i;
		}
		else {
			std::cout << "\nDELETING\n";
			//if the last Node is a duplicate
			if (current->nextPtr->nextPtr == nullptr) {
				current->nextPtr = nullptr;
				
			}
			else {
				//We have found a duplicate.
				//we need to make the pointer skip the next value
				current->nextPtr = current->nextPtr->nextPtr;
				
			}
		}
	
	
	}

}



void LinkedList::getKthToLast(int n) {
	//Keep track of two indeces
	int i = 1;
	

	Node* current = rootPtr;
	Node* tracker = rootPtr;

	while (i < n) {
		//Move the ith index first
		//But first check that we do not in a nullptr
		if (tracker != nullptr) {
		
			tracker = tracker->nextPtr;
			++i;
		}
		else{
			std::cout << "\nWe have reached the end of the linkedList.\nTry again with a smaller number.\n\n";
			return;
		}


	}

	//tracker is in the correct position, and now move both tracker and current, until tracker is in the last node.
	while (tracker->nextPtr != nullptr) {
		//Shift both the pointer
		current = current->nextPtr;
		tracker = tracker->nextPtr;
	}
	//Current is now were we want it be, print out the value and we are done

	std::cout << "\n\nThe " << n << "th to last element is: " << current->data << "\n\n";

}



void LinkedList::deleteMiddleNode(Node* mid){


	//W are given the middle Node, to delete the middle node we just need to overwrite the data with all the next nodes.
	Node* current = mid;
	while (current->nextPtr != nullptr) {
		current->data = current->nextPtr->data;
		
		if (current->nextPtr->nextPtr != nullptr) {
			current = current->nextPtr;
		}
		else{
			//Make this our last node
			current->nextPtr = nullptr;
		}
	}
	//We are done.

}



bool LinkedList::isPalindrome() {

	//Reverse the linked List and then compare every single value.
	//or
	//Place values into a vector and compare the values using to index trackers

	std::vector<int> myVect;

	//Go all the way to the end of the original linked list and then start placing these values into our vector
	Node* current = rootPtr;

	while (current) {
		myVect.push_back(current->data);
		current = current->nextPtr;
	}

	//All the element were placed into our vector and now check if we have a palindrome

	int i = 0;
	int j = myVect.size()-1;

	while (i < j) {
		if (myVect[i] == myVect[j]) {
			++i;
			--j;
		}
		else {
			return false;
		}
	}
	

	return 1; 

}


