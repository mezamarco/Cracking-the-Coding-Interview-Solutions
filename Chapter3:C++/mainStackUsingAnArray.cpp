
// Implement A Stack Using An Array 
// we need to implement four functions,    isEmpty, push(item), pop(), top(), 

#include <iostream>

class MyStack {

public:
	int* arr;
	int* firstPtr;
	int* lastPtr;

	int max;


	//Custom Constructor
	MyStack(int size) {
		//Initially the array hold garbage integers
		arr = new int[size];

		firstPtr = arr;
		max = size;

		//Place the lastPtr in the last position
		int* current = arr;
		int counter = 0;
		//Make everything null and then place the last ptr in the correct index
		for (int i = 0; i < size; i++) {

			*current = 0;

			if (i != (size - 1)) {
				++current;
			}
			//This is the last index and therefore place the lastptr to this index
			lastPtr = current;
		}


	}

	void printAll() {

		if (this->isEmpty()) {
			std::cout << "\nWe cannot print we have an empty Stack\n\n";
			return;
		}
		int* current = lastPtr;

		while (current != firstPtr)
		{
			std::cout << *current << "  ";
			--current;
		}
		//FInally, print out the last element
		std::cout << *current << "\n\n\n";


	}


	bool isEmpty() {

		if (*lastPtr == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	void clearAll() {
		arr = new int[max];

		firstPtr = arr;


		//Place the lastPtr in the last position
		int* current = arr;

		//Make everything null and then place the last ptr in the correct index
		for (int i = 0; i < max; i++) {

			*current = 0;

			if (i != (max - 1)) {
				++current;
			}
			//This is the last index and therefore place the lastptr to this index
			lastPtr = current;
		}

	}


	void pop() {

		if (lastPtr == firstPtr) {
			//We delete this node by starting a new array
			this->clearAll();
		}
		else {
			//Move down one index
			--lastPtr;
		}

	}

	void push(int data) {
		if (*lastPtr == 0) {
			std::cout << "Node is empty\n";

			*lastPtr = data;
			return;
		}

		std::cout << "The last node is not empty\n";
		int* current = lastPtr;
		int counter = 0;

		while (*current != 0) {
			++counter;
			--current;
			if (current == arr) {
				if (*current != 0) {
					std::cout << "The Stack is full we cannot insert anymore.\n\n";
				}
				return;
			}
		}
		std::cout << "\nPushing at : " << counter;
		//This index is null, so place the data here.
		*current = data;
	}

	int top()
	{
		if (this->isEmpty()) {
			return -999;
		}

		return *lastPtr;

	}

};



int main()
{
	MyStack theStack(3);
	

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
	theStack.push(23);
	theStack.push(77);
	theStack.push(189);



	std::cout << "Original Stack: \n";
	theStack.printAll();
	std::cout << "\nWhat is in the top: " << theStack.top() << "\n";
	std::cout << "\n\n";



	//lets print and pop the elements
	while (!theStack.isEmpty()) {

		theStack.printAll();
		std::cout << "\n";
		//Pop
		theStack.pop();
	}
	std::cout << "\n";


	std::cout << "The Queue is empty: " << theStack.isEmpty() << "\n\n";


	std::cout << "\nWhat is in the top: " << theStack.top() << "\n";

	theStack.printAll();
	std::cout << "\n";
	std::cout << "\nDo we have an empty Stack: " << theStack.isEmpty() << "\n\n";

    return 0;
}


