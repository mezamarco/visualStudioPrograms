// graphTraversal.cpp : Defines the entry point for the console application.
//
//Implement the preorder, inorder, and postorder traversal

#include "stdafx.h"
#include <iostream>

void preorder(Node* current) {
	if (current == nullptr) {
		return;
	}
	//First visit
	std::cout << current->data << "  ";

	preorder(current->left);
	preorder(current->right);
}

void inorder(Node* current) {
	if (current == nullptr) {
		return;
	}

	inorder(current->left);

	//Visit
	std::cout << current->data << "  ";

	inorder(current->right);
}



void postorder(Node* current) {
	if (current == nullptr) {
		return;
	}
	
	
	postorder(current->left);
	postorder(current->right);
	
	// Visit last
	std::cout << current->data << "  ";

}




int main()
{
    return 0;
}

