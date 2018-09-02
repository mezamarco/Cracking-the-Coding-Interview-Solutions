#include "LinkedList.h"
#include <iostream>
#include <unordered_map>
#include <vector>
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

//Remove all the duplicates from our Linked list
void LinkedList::removeDuplicates() {
	
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
			//We reach the map end, 
			//therefore the element does not exist in our map, so store this value
			//Move to the next node and save its value.
			current = current->nextPtr;

			myMap[current->data] = i;
			++i;
		}
		else {
			std::cout << "\nDELETING\n";
			
				current->nextPtr = current->nextPtr->nextPtr;
		}
	
	
	}

}


//Get the kth to last node
Node* LinkedList::getKthToLast(int n) {

	std::cout << "\nWhere are getting the kth:" << n << "  ";
	if (rootPtr == nullptr) {
		return nullptr;
	}

	Node* first = rootPtr;
	Node* second = rootPtr;

	for (int i = 0; i < n; i++) {
		if(first ==nullptr){
			std::cout << "You need to select a smaller kth element.";
			return nullptr;
		}
		else {
			first = first->nextPtr;
		}
	}

	while (first != nullptr) {
		first = first->nextPtr;
		second = second->nextPtr;
	}

	return second;
}



//Delete the node that is in the middle of a linked list
void LinkedList::deleteMiddleNode(Node* mid){

	if (mid == nullptr || mid->nextPtr == nullptr) {
		return;
	}

	Node* nextOne = mid->nextPtr;
	//Overwrite the current data
	mid->data = nextOne->data;
	mid->nextPtr = nextOne->nextPtr;
	return;
}


//Is the data of the linked list a palidrome?
bool LinkedList::isPalindrome() {

	//Reverse the linked List and then compare every single value.
	//or
	//Place values into a vector and compare the values using to index trackers

	std::vector<int> myVect;

	//Go all the way to the end of the original linked list and 
	//then start placing these values into our vector
	Node* current = rootPtr;

	while (current) {
		myVect.push_back(current->data);
		current = current->nextPtr;
	}

	//All the element were placed into our vector and now check  if we have a palindrome

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



//Given Two Linked Lists, find the node where the intersect
Node* LinkedList::intersection(Node* p, Node* q){
	
	if(getLastNode(p) != getLastNode(q))
	{
		return 0;
	}

	int delta = getSize(p) - getSize(q);


	Node* small = delta > 0 ? q:p;
	Node* large = delta > 0 ? p:q;


	large  = moveRight(large, abs(delta));


	//Now we have the small pointer and the large pointer in the same level
	//Note that we are guranteed an intersection so lets find it
	while(small != large){
		small = small->nextPtr;
		large = large->nextPtr;
	}

	return large;

}



//Get the size of a linked list
int LinkedList::getSize(Node* root){

	int counter = 0;

	Node* current = root;
	
	while(current){
		
		current= current->nextPtr;
		++counter;
	}
	return counter;

}

//Move along the linked list n times to the right
Node* LinkedList::moveRight(Node* current, int n){
	
	for(int i = 0; i < n ; i++){
		current = current->nextPtr;
	}

	return current;
}


//Get the last node of the linked list
Node* LinkedList::getLastNode(Node* root){

	Node* curr = root;
	while(curr != nullptr){
		curr = curr->nextPtr;
	}
	return curr;
}

//Determine if we have a loop in our linked list
bool LinkedList::hasCycle(Node* root){

	if(root == nullptr || root->nextPtr == nullptr){
		return false;
	}

	Node* slow = root;
	Node* fast = root->nextPtr;

	while(fast !=nullptr && fast->nextPtr != nullptr){
		if(slow == fast){
			return true;
		}

		slow = slow->nextPtr;
		fast = fast->nextPtr->nextPtr;
	}
	return false;
}


//Sum both linked lists
Node* LinkedList::sumLists(Node* p, Node* q){

	if(p ==nullptr){
		return q;
	}
	if(q == nullptr){
		return p;
	}

	int delta = getSize(p) - getSize(q);

	Node* small = delta > 0  ? q:p;
	Node* large = delta > 0  ? p:q;

	Node* answer = large;

	int sum = 0;
	int carry = 0;

	while(small != nullptr){
	
		sum = small->data + large->data + carry;


		//The range of the sum: [0,19]
		if(sum < 10){
			carry = 0;
			large->data = sum;
		}
		else{
			carry = 1;
			int digit = sum % 10;
			large->data = digit;
		}

		small = small->nextPtr;

		if(small != nullptr){
			large = large->nextPtr;
		}

	}


	if(large->nextPtr != nullptr)
	{
		large = large->nextPtr;

		while(large != nullptr){
			sum = large->data + carry;

			if(sum < 10){
				carry = 0;
				large->data = sum;
			}
			else{
				carry = 1;
				int digit = sum % 10;
				large->data = digit;
			}

			if(large->nextPtr == nullptr){
				break;
			}
			else{
				large = large->nextPtr;
			}
		}
	
	}

	
	
	if(carry == 1){
		Node* lastNode = new Node(1);
		large->nextPtr = lastNode;
	}


	return answer;


}



