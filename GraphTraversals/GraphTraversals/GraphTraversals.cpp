// GraphTraversals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <limits>
#include <iostream>


//Traverse the graph appropiately and place the elements in a vector
preOrderTrav(Node* temp, std::vector<int> & myVect);
inOrderTrav(Node* temp, std::vector<int> & myVect);
postOrderTrav(Node* temp, std::vector<int> & myVect);

void BFS(Node* root);


int main()
{

	//Place the function into my BST project in the house.



    return 0;
}

preOrderTrav(Node* temp, std::vector<int> & myVect) {
	//Base case
	if (temp == nullptr) {
		return;
	}
	
	//NOTE:   VLR

	//Place the given node into the vector
	myVect.push_back(temp->data);
	//Do recursion on left subtree
	preOrderTrav(temp->left);
	//Do recursion on right subtree
	preOrderTrav(temp->right);


}
inOrderTrav(Node* temp, std::vector<int> & myVect) {
	//Base case
	if (temp == nullptr) {
		return;
	}

	//NOTE:   LVR
=
	//Do recursion on left subtree
	inOrderTrav(temp->left);
	//Place the given node into the vector
	myVect.push_back(temp->data);
	//Do recursion on right subtree
	inOrderTrav(temp->right);
}
postOrderTrav(Node* temp, std::vector<int> & myVect) {
	//Base case
	if (temp == nullptr) {
		return;
	}

	//NOTE:   LRV

	
	//Do recursion on left subtree
	postOrderTrav(temp->left);
	//Do recursion on right subtree
	postOrderTrav(temp->right);
	//Place the given node into the vector
	myVect.push_back(temp->data);
}

//How do I do BFS?
void BFS(Node* root) {


	//REQUIREMENT: All our nodes require that we have a 
	//int dist = infinity
	//Node* prev = nullptr;
	//A vector that points to all its children
	//Ex. std::vector<int> adjacentChildrenVector;


	//Initialize a queue of Node Pointers
	std::queue<Node*> myQueue;


	//Add the current Node into our Queue
	myQueue.push(root);
	//Set the current Node distance to zero
	root->dist = 0;


	//We need a tracking node pointer
	Node* current;

	//While my queue is not empty
	while (!myQueue.empty()) {
	
		//Place the current Node from the queue and pop this node
		current = myQueue.front();
		myQueue.pop();

		//For all of its children, 
		//Iterate through its vector of children
		//Access the current node and focus on the vector
		std::vector<int>::iterator it = current->adjVect.begin();

		for (; it != current->adjVect.end(); ++it) {
		
			//Using the Container that point to all the node
			//We will now look at this child node
			Node* neighborPtr = nodePointerVector[*it];

			//If this neighbor node has not been visited, 
			//which means that we have a distance of infity
			// Then we have to do a few things

			if (neighborPtr == std::numeric_limits<int>::max()) {
			
				//We need to do three things
				
				//Update the distance from the current node to this node
				neighborPtr->dist = current->dist + 1;
				//Update the prev Value
				neighborPtr->dist = current->label;
	
				//Push all its children into the queue.
				myQueue.push(neighborPtr);

			}
		
		
		}






	}





}
