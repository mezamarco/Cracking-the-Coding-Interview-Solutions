
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <stack>

//Remove a all instances of a specific element from a vector
void removeElement(std::vector<int>& myVect, int num);

//Find the index of two element that will sum to the target element
//Solve this problem in O(n) runtime
bool targetSum(std::vector<int>& myVect, int target);

//Do we have valid opening and closing parentheses,
//Ex: valid:  {}{}()[][], valid : {[()]}, invalid: ({[}])
bool validParentheses(std::string word);

//Recursive sum: n + n-1 + n-2 + .... + 2 + 1
int recursiveSum(int n);

//Reverse a vector
void reverseVector(std::vector<int>& myVect);

//Is the given number a prime number
bool isPrime(int num);

// a^(b) Power Algorithm
int power(int a, int b);

// a % b  Mod Algorithm
int power(int a, int b);

// a / b Division Algorithm
int division(int a, int b);

//Get the sum of all the individual digits
int sumDigits(int num);

//Get the number of common elements between the two given vectors
int numCommon(std::vector<int>& a, std::vector<int>& b);



int main()
{
    //The solutions work, but we still have to display some test cases(Do this later).
    return 0;
}




//Remove a all instances of a specific element from a vector
void removeElement(std::vector<int>& myVect, int num) {
	if (myVect.empty())
		return;

	int i = 0;
	int k = 0;
	while (i < myVect.size()) {
		if (myVect[i] != num) {
			myVect[k] = myVect[i];
			++k;
		}
		++i;
	}
	return;

} 



//Find the index of two element that will sum to the target element
//Solve this problem in O(n) runtime
bool targetSum(std::vector<int>& myVect, int target) {

	std::unordered_map<int, int> myMap;

	for (int i = 0; i < myVect.size(); i++) {
		int complement = target - myVect[i];

		if (myMap.find(complement) != myMap.end()) {
			//We found  a pair that give us the target sum
			int m = myMap[complement];
			int n = i;
			std::cout << "The index values are: " << m <<" , "<< n << std::endl;
			return true;
		}
		myMap[myVect[i]] = i;
	}
	return false;
}




//Do we have valid opening and closing parentheses,
//Ex: valid:  {}{}()[][], valid : {[()]}, invalid: ({[}])
bool validParentheses(std::string word) {

	if (word.size() % 2 != 0) {
		return false;
	}

	std::stack<char> myStack;

	for (char ch : word) {

		if (ch == '(' || ch == '[' || ch == '{')
		{
			myStack.push(ch);
		}
		else if (myStack.empty()) {
			return false;
		}
		else if (ch == ')' && myStack.top() == '('  || 
			 ch == '}' && myStack.top() == '{'  || 
			 ch == ']' && myStack.top() == '['  )
		{
			myStack.pop();
		}
		else {
			return false;
		}
	}
	return true;
}




//Recursive sum: n + n-1 + n-2 + .... + 2 + 1
int recursiveSum(int n) {
	if (n <= 0) {
		return 0;
	}
	else {
		return n + recursiveSum(n - 1);
	}
}

//Reverse a vector
void reverseVector(std::vector<int>& myVect) {
	if (myVect.empty()) {
		return;
	}
	
	int i = 0;
	int j = myVect.size() - 1;

	while (i < j) {
		int temp = myVect[i];
		myVect[i] = myVect[j];
		myVect[j] = temp;
	}
	return;
}

//Is the given number a prime number
bool isPrime(int num) {

	if (num < 2) {
		return 0;
	}

	for (int i = 2; i <= sqrt(num); num++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}


// a^(b) Power Algorithm
int power(int a, int b)
{
	if (b == 0) {
		return 1;
	}
	return a * power(a, b - 1);
}

// a % b  Mod Algorithm
int mod(int a, int b)
{
	if (b <= 0)
		return -1;

	int div = a / b;
	int rem = a - (b*div);
	return rem;
}

// a / b Division Algorithm
int division(int a, int b) {

	if (b <= 0)
		return -1;

	int sum = b;
	int counter = 0;
	while (sum <= a) {
		++counter;
		sum = sum + b;
	}
	return counter;
}




//Get the sum of all the individual digits
int sumDigits(int num) {

	int sum = 0;
	while (num > 0) {
		int digit = num % 10;
		sum = sum + digit;
		num = num / 10;
	}
	return sum;
}



//Get the number of common elements between the two given vectors
int numCommon(std::vector<int>& a, std::vector<int>& b) {

	if (a.empty() || b.empty())
		return 0;

	//We will store all the elements from vector a into a hashmap
	std::unordered_map<int, int > myMap;

	for (int i = 0; i < a.size(); i++) {
		myMap[a[i]] == i;
	}

	//If an element of b is in the hashmap then increment counter
	int counter = 0;

	for (int y : b) {
		if (myMap.find(y) != myMap.end()) {
			++counter;
		}
	}
	return counter;
}
