// myGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map> 
#include <ctime>
#include <queue> 
#include <iterator>
#include <stack>


class Node {
public: 
	int data;
	std::unordered_map<int, int> adjacencyMap;
	static int nodeCounter;

	int dist;
	int prev;

	//Custom Constructor
	Node(int val) {
		++Node::nodeCounter;
		data = val;

		//Set distance to infinity
		dist = std::numeric_limits<int>::max();
		prev = -1;
	}
};

int Node::nodeCounter = 0;


class Graph {

public:
	std::vector<Node*>nodeVector;


	//We need an insert function to insert nodes into our graph.
	void insert(int value, std::vector<int> & theChildren) {
		//Create the Node object
		Node* theNode = new Node(value);
		
		//For this node place the children into the hashMap
		for (int i = 0; i < theChildren.size(); i++) {
				
			int number = theChildren[i];
			theNode->adjacencyMap[number] = i;
		}

		//The node is ready to be inserted into the vector
		this->nodeVector.push_back(theNode);
	}

	

	bool isEmpty(){
		if (this->nodeVector.size() == 0) {
			return 1;
		}
		return 0;
	}


	std::stack<int> isConnectedBFS(int a, int b)
	{
		//For BFS we have to use a queue.
		std::queue<Node*> toExploreQueue;

		Node* start = this->nodeVector[a];
		Node* end = this->nodeVector[b];

		if (start == end) {
			std::stack<int> theStack;
			theStack.push(10000);
			return theStack;
		}

		//Set distance zero for the starting node
		start->dist = 0;
		//Push the start node into the queue
		toExploreQueue.push(start);

		//Continue while loop, until queue is empty
		while (!toExploreQueue.empty()) {
		
			//Get the front node from our queur and then pop it
			Node* current = toExploreQueue.front();
			toExploreQueue.pop();

			//Iterate through its adjacenecy list
			std::unordered_map<int, int>::iterator myItr = current->adjacencyMap.begin();

			for (; myItr != current->adjacencyMap.end(); ++myItr)
			{
				Node* neighbor = this->nodeVector[myItr->first];

				//If this node has a distance of infinity then we have not visited this node.
				if (neighbor->dist == std::numeric_limits<int>::max()) {
				
					//Update the distance from the current node to this node
					//and also update the prev value
					neighbor->dist = current->dist + 1;
					neighbor->prev = current->data;
					//push all its children into the queue
					toExploreQueue.push(neighbor);


				}


			}
		}



		//Our nodes have been modified and now traverse from the end node to the start node.
		//Save the traversal using a stack
		std::stack<int> myStackPath;

		//Recall the name of our end node: end
		Node* tracker = end;
		myStackPath.push(b);

		//Keep on adding the traversal path into our stack until we reach our begin pointer
		while(tracker != start){
			if (tracker->prev != -1) {
			
				tracker = this->nodeVector[tracker->data];
				myStackPath.push(tracker->data);
			}
			else {
				//Clear our stack path
				while (!myStackPath.empty()) {
					myStackPath.pop();
				}
				break;
			}

		}

		//WE NEED TO RESET OUR DISTANCES AND PREV IN ORDER TO DO BFS AGAIN
		//
		//
		//


		//Our stack Path now holds the path.
		return myStackPath;


	
	}


	void printPath(std::stack<int>& a) {
		
		if(a.empty()){
			std::cout << "\n\nNO PATH FOUND\n\n";
		}

		std::cout << "\n\nPrinting path:\n";
		while (!a.empty()) {
			std::cout << a.top() << "    ";
			a.pop();
		}


	}



};

int main()
{

	//Create our graph
	Graph myGraph;




	srand(time(NULL));


	std::cout << "\nIs my graph empty: " << myGraph.isEmpty() << "\n\n";

	std::cout << "We will create a graph for you.\n";

	std::cout << "How many Nodes do you want in the graph: ";
	int numOfNodes;
	std::cin >> numOfNodes;
	
	std::vector<int> theChildren;

	for (int i = 0; i < numOfNodes; i++) {
	
		std::cout << "\nNode: " << i << "   has the following Children:\t";

		//For every Node, we need to deternime its value and its children
		//Get random children, for every node place 5 children.
		for (int j = 0; j < 5; j++) {
			

			//THe random range is: [0-7]
			int random = rand() % 8 ;
			std::cout << random << "\t";

			theChildren.push_back(random);

		}


		myGraph.insert(i, theChildren);

	}

	std::cout << "\n\n\nIs my graph empty: " << myGraph.isEmpty() << "\n\n\n";
	std::cout << "\nHow many nodes do we have in our graph: " << Node::nodeCounter << "\n\n\n";


	std::stack<int> path = myGraph.isConnectedBFS(2, 5);
	
	myGraph.printPath(path);





    return 0;
}

