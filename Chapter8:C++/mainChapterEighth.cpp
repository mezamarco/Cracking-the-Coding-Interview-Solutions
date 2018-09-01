// Chapter8  Dynamic Programming

#include <iostream>
#include <vector> 
#include <ctime>
#include <set>
#include <iterator>

//Function Prototypes


//Triple step problem. 
//A child is running up a staircase with n steps.
//THe child can hop 1 step, 2 steps, or 3 steps.
//Write a function that can count the number of ways that the child can go up the stairs.
int bruteForceTripleStep(int n);

//Dynamic programming solution
//Count steps, using dynamic programming
int stepCount(int n);
//Helper function
int stepCount(int n, std::vector<int>& myVect);


//NOte that we have magic index, if A[i] = i.
void magicSlow(std::set<int>& mySet);
void printAll(std::set<int>& mySet);


int magicFast(int arr[], int size); 
int magicFast(int arr[], int start, int end);



int main()
{
	std::cout << "We will solve the triple step problem.\n\nHow big will the staircase be: ";
	int n;
	std::cin >> n;

	int answer = bruteForceTripleStep(n);
	std::cout << "If the staircase has " << n << " steps\nThere exists: " 
		<< answer << " possible ways to up the staircase\n\n";
	

	answer = stepCount(n);
	std::cout << "If the staircase has " << n << " steps\nThere exists: " 
		<< answer << " possible ways to up the staircase\n\n";

	srand(time(NULL));

	//we will now solve the magic index problem,
	//A magic index is when arr[i] = i,  
	//for this problem assume that the vector has values that are sorted.
	//Build a vector with random elements
	std::cout << "We will now solve the magic index problem.\n";
	std::cout << "To build the sorted array, how big will the size of the array be: ";
	int theSize;
	std::cin >> theSize;

	//Lets populate the vector with random values
	std::set<int> mySet;
	for (int i = 0; i < theSize; i++) {
		int random = rand() % 51;
		//The range of the random value is [0 - 50]
		mySet.insert(random);
	}


	//Print out the element in our vector to see what we have.
	std::cout << "Printing the set with random values: \n";
	printAll(mySet);
	std::cout << "\n\n";

	//Solve the problem using the magicSlow function
	magicSlow(mySet);



    return 0;
}



//This solution is not using recursive programming, therefore the run time is O(3^n)
int bruteForceTripleStep(int n) {
	//The time complexity to run get an answer will be: O(3^n)
	if (n < 0) {
		return 0;
	}
	else if(n == 0){
		return 1;
	}
	else {
		return bruteForceTripleStep(n - 1) + bruteForceTripleStep(n - 2) 
			+ bruteForceTripleStep(n - 3);
	}

}



//Count steps, using dynamic programming
int stepCount(int n) {

	//Initialize a vector with size: n+1, and every element should be -1.
	std::vector<int> myVect(n+1, -1);
	return stepCount(n,myVect);
}


int stepCount(int n, std::vector<int>& myVect){

	if(n<0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else if(myVect[n] > -1){
		return myVect[n];
	}
	else{
		myVect[n] = stepCount(n-1, myVect) + stepCount(n-2, myVect) + stepCount(n-3, myVect);
		return myVect[n];
	}
}



void magicSlow(std::set<int>& mySet) {
	//We will solve this problem using brute force,
	//Simply thaverse the vector and check if the is index is equal to the given element.
	std::set<int> answerSet;
	
	int count = 0;
	for (int i : mySet) {
		if (count == i) {
			//Place the given index into our answerSet
			answerSet.insert(i);
		}
		
		++count;
	}

	//We have the solution in our set.
	if (answerSet.size() == 0) {
		std::cout << "\n\nWe have no solution.\n\n";
	}
	else {
		//Print our the results
		for (int m : answerSet) {
			std::cout << m << "   ";
		}
	}
	std::cout << "\n\n";
}

void printAll(std::set<int>& mySet) {
	//Simmply print out all the element in our vector
	for (int m : mySet) {
		std::cout << m << "  ";
	}
	std::cout << std::endl;
}


//This will be the dynamic programming function for the magic Index problem
int magicFast(int arr[], int size) {
	//Simply use the helper function to solve the problem
	//This recursice function must be given more information. 
	
	int lastIndex = size - 1;
	
	
	return magicFast(arr, 0, lastIndex);
}
//This is the helper function that will do the recursion.
int magicFast(int arr[], int start, int end) {

	//Note: that we will solve this problem as we where doing binary search
	if(end < start){
		return -1;
	}

	//Get the middle element, this will give us the floor 
	int middle = (start + end) / 2;

	//Note we will have three cases for the binary search

	//Now we can check if the middle element has the same index and same element
	if (middle == arr[middle]) {
		//We solve the problem and return this index
		return middle;
	}
	else if (arr[middle] < middle) {
		//We need to take a look at the right side of the array
		return magicFast(arr, middle + 1, end);
	}
	else //For the case the middle index > than the element in the middle 
	{
		return magicFast(arr, start, middle - 1);
	}
	

}

