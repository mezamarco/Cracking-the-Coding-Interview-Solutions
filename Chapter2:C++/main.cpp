
#include "LinkedList.h"
#include <iostream>
#include <ctime>

int main(){
LinkedList theList;
	
	srand(time(NULL));
	
	//Place random elements into our linkedList
	for (int i = 0; i < 20; i++) {
		int randomVal = rand() % 10 + 1;
		theList.insert(randomVal);
	}
	std::cout << "\n\n";
	theList.printAll();

	std::cout << "\n\n";
 
	
	
	theList.removeDuplicates();
	std::cout << "\n\n";
	theList.printAll();





	LinkedList theSecondList;

	for (int i = 0; i < 20; i++) {
		int randomVal = rand() % 10 + 1;
		theSecondList.insert(randomVal);
	}
	std::cout << "\n\n";
	theSecondList.printAll();
	
	Node* tracker = theSecondList.getKthToLast(6);
	std::cout << "Data: " << tracker->data;
	tracker = theSecondList.getKthToLast(2);
	std::cout << "Data: " << tracker->data;
	 tracker = theSecondList.getKthToLast(1);
	 std::cout << "Data: " << tracker->data;
	 tracker = theSecondList.getKthToLast(21);


 	std::cout <<"\n\n";	 
	
	LinkedList theThirdList;
	theThirdList.insert(2);
	theThirdList.insert(4);	
	theThirdList.insert(6);
	theThirdList.insert(8);
	theThirdList.insert(10);

	theThirdList.printAll();
	std::cout << "\n\n";

	Node* mid = theThirdList.mid;

	theThirdList.deleteMiddleNode(mid);

	theThirdList.printAll();
	std::cout << "\n\n";



	//THe sum of two linked list



	//We will now check if a given Linked List is palindrome
	LinkedList fourthList;

	fourthList.insert(3);
	fourthList.insert(7);
	fourthList.insert(8);
	fourthList.insert(222);
	fourthList.insert(4444);
	fourthList.insert(4444);
	fourthList.insert(222);
	fourthList.insert(8);
	fourthList.insert(7);
	fourthList.insert(3);
	//This fourth list is a palindrome
	fourthList.printAll();
	std::cout << "\n\nIs the first list a palidrome? " << theList.isPalindrome() << "\n";
	std::cout << "Is the second list a palidrome? " << theSecondList.isPalindrome() << "\n";
	std::cout << "Is the third list a palidrome? " << theThirdList.isPalindrome() << "\n";
	std::cout << "Is the fourth list a palidrome? " << fourthList.isPalindrome() << "\n\n" ;





	std::cout << "\n\n";
	return 0;
}
