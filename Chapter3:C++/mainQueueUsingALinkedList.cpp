// Implement A Queue Using A Linked List
// The function that we need to implement are:  push(item), pop(), top(), isEmpty().										

#include <iostream>

class QueueNode {
public:
	int data;
	QueueNode* next;
	static int nodeCounter;

	//Custom Constructor for the QueueNode
	QueueNode(int val) {
		++QueueNode::nodeCounter;

		data = val;
		next = nullptr;
	}

};
int QueueNode::nodeCounter = 0;


class MyQueue {
public:
	static int nodeCounter;
	QueueNode* root;

	//MyStack constructor
	MyQueue(){
		root = nullptr;
	}

	//We need to implement four functions
	bool isEmpty() {
		if (!root) {
			return true;
		}
		else {
			return false;
		}
	}

	int top() {
		//SAfety check
		if (this->isEmpty()) {
			return false;
		}
		else {
			return root->data;
		}
	}

	//Now implement pop
	void pop() {
		if (this->isEmpty()) {
			std::cout << "\n\nThis stack is already empty\n";
		}
		else {
			root = root->next;
		}
		--QueueNode::nodeCounter;
	}

	//Now implement the push function
	void push(int item) {
		//First create the node
		QueueNode* theNewNode = new QueueNode(item);


		if (!root)
		{
			//We have an empty linked list so place the first node inot the root
			root = theNewNode;
		} 
		else
		{
			//Traverse to the end of the linked list and then place this new node here
			QueueNode* current = root;
			while (current->next) {
				current = current->next;
			}
			//Our next pointer is null, so place our newer node there
			current->next = theNewNode;
		}
	}


	//print all function
	void printAll() {
		QueueNode* current = root;
		if (!current) {
			std::cout << "\nEMPTY\n";
		}

		while (current) {
			std::cout << current->data << "  ";
			current = current->next;
		}
		return;
	}

};




int main()
{	

	MyQueue theQueue;

	theQueue.push(23);
	theQueue.push(55);
	theQueue.push(87);
	theQueue.push(11);
	theQueue.push(76);
	theQueue.push(8453);
	theQueue.push(43);
	theQueue.push(23); 
	theQueue.push(77);
	theQueue.push(189);
	theQueue.push(7878);

	

	std::cout << "Node Counter: " <<QueueNode::nodeCounter << "\n";
	std::cout << "Original Queue: \n";
	theQueue.printAll();

	std::cout << "\n\n";


	//lets print and pop the elements
	while (!theQueue.isEmpty()) {
		
		std::cout << "Node Counter: " << QueueNode::nodeCounter << "\n";
		theQueue.printAll();
		std::cout << "\n";
		//Pop
		theQueue.pop();
	}
	std::cout << "\n";


	std::cout << "The Queue is empty: " << theQueue.isEmpty() << "\n\n";




    return 0;
}


