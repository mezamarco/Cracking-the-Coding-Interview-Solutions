// Implement A Stack Using A Linked List.cpp
// The function that we need to implement are:  push(item), pop(), top(), isEmpty().										

#include <iostream>

class StackNode {
public:
	int data;
	//Every node will have a next pointer and prev pointer
	StackNode* next;
	StackNode* prev;

	static int nodeCounter;

	//Custom Constructor for the QueueNode
	StackNode(int val) {
		++StackNode::nodeCounter;

		data = val;
		next = nullptr;
		prev = nullptr;
	}

};
int StackNode::nodeCounter = 0;


class MyStack {
public:
	StackNode* root;
	StackNode* tail;

	//MyStack constructor
	MyStack() {
		root = nullptr;
		tail = nullptr;
	}

	//We need to implement four functions
	bool isEmpty() {
		if (!tail) {
			return true;
		}
		else {
			return false;
		}
	}

	int top() {
		//Safety check
		if (this->isEmpty()) {
			std::cout << "We have an empty stack and therefore there is nothing at the top";
			return false;
		}
		else {
			return tail->data;
		}
	}

	//Now implement pop
	void pop() {
		if (this->isEmpty()) {
			std::cout << "\n\nThis stack is already empty\n";
		}
		else if(root ==tail){
			std::cout << "We have deleted the last Node";
			root = nullptr;
			tail = nullptr;
		}
		else {
			tail = tail->prev;
		}
		--StackNode::nodeCounter;
	}

	//Now implement the push function
	void push(int item) {
		//First create the node
		StackNode* theNewNode = new StackNode(item);

		if (!root)
		{
			//We have an empty linked list so place the first node inot the root
			root = theNewNode;
			tail = theNewNode;
		}
		else
		{
			//Traverse to the end of the linked list and then place this new node here
			StackNode* current = root;
			while (current->next) {
				current->next->prev = current;
				current = current->next;

				
			}
			//Our next pointer is null, so place our newer node there
			current->next = theNewNode;
			theNewNode->prev = current;
			tail = theNewNode;

		}
	}


	//print all function
	void printAll() {
		StackNode* current = tail;
		if (!current) {
			std::cout << "\nEMPTY\n";
		}

		while (current) {
			std::cout << current->data << "  ";
			current = current->prev;
		}
		return;
	}

};








int main()
{

	MyStack theStack;

	theStack.push(23);
	theStack.push(55);
	theStack.push(87);
	theStack.push(11);
	theStack.push(76);
	theStack.push(8453);
	theStack.push(43);
	theStack.push(23);
	theStack.push(77);
	theStack.push(189);
	theStack.push(7878);



	std::cout << "Node Counter: " << StackNode::nodeCounter << "\n";
	std::cout << "Original Queue: \n";
	theStack.printAll();
	std::cout << "\nWhat is in the top: " << theStack.top() << "\n";
	std::cout << "\n\n";



	//lets print and pop the elements
	while (!theStack.isEmpty()) {

		std::cout << "Node Counter: " << StackNode::nodeCounter << "\n";
		theStack.printAll();
		std::cout << "\n";
		//Pop
		theStack.pop();
	}
	std::cout << "\n";


	std::cout << "The Queue is empty: " << theStack.isEmpty() << "\n\n";


	std::cout << "\nWhat is in the top: " << theStack.top() << "\n";


	return 0;
}


