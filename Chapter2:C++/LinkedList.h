#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:
	int nodeCounter;
	Node* rootPtr;
	Node* mid;

	LinkedList();

	//Insert function prototype
	void insert(int value);

	//Print the elemenents of all the nodes in the linked list
	void printAll();

	//Remove all the duplicates from our Linked list
	void removeDuplicates();

	//Get the kth to last node
	Node* getKthToLast(int n);

	//Delete the node that is in the middle of a linked list
	void deleteMiddleNode(Node* mid);

	//Is the data of the linked list a palidrome?
	bool isPalindrome();

	//Given Two Linked Lists, find the node where the intersect
	Node* intersection(Node* p, Node* q);

	//Get the size of a linked list
	int getSize(Node* root);

	//Move along the linked list n times to the right
	Node* moveRight(Node* current, int n);

	//Get the last node of the linked list
	Node* getLastNode(Node* root);

	//Determine if we have a loop in our linked list
	bool hasCycle(Node* root);

	//Sum both linked lists
	Node* sumLists(Node* p, Node* q);
};
#endif
