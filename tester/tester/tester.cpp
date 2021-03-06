// tester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

int BFSshortestPath(Node* start, Node* end);

int getKthLargest(std::vector<int> & myVect);

int main()
{

}

int BFSshortestPath(Node* start, Node* end) {

	//initialize a queue
	std::queue<Node*> myQueue;

	//Push the starting node into the queue, but first give it the distance of zero.
	start->distance = 0;
	myQueue.push(start);

	while (!myQueue.empty()) {
		//Get the front element form the queue and then pop it from the queue
		Node* current = myQueue.front();

		myQueue.pop();
		
		//Get the distance of the current node
		int currentDistance = current->distance;

		//Check if we already arrived to the end node
		if (start == end) {
			return currentDistance;
		}

		//Get the size of the adjacency vector
		int childrenSize = current->adjVect.size();
		//For all the children of the current node
		for (int i = 0; i < childrenSize; i++) {
			//Check if the given child is not visited
			//First get the child
			Node* child = allNodeVect[current->element];

			if (child->isVisited == false) {
				//If this child has not been visited then I have update the child distance and then place this child into my queue
				child->distance = currentDistance + 1;
				//Place this node into my queue
				myQueue.push(child);
			}
		}

		//If we reach here then no path exists, therefore return -999.
		return -999;
	}


	//DFS function to search for a given node in the graph

	//BFS function to search for a given node in the graph









}



int getKthLargest(std::vector<int> & myVect) {


	//To solve this problem we can build a min heap and then
	//Traverse the top element in the heap k times and that will be the kth largest element

}




