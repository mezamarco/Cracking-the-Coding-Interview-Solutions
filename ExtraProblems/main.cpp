
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <functional>
#include <stack>
#include <math.h>

int const M = 5;
int const N = 5;

//Function Prototype

//Get the index of the first unique character.
int indexOfFirstUniqueCharacter(std::string word);
//Get the first repeated character of the given string
char firstRepeatedCharacter(std::string word);
//Do we have a pair of element where the product equals to the target
bool targetMultiplication(std::vector<int>& myVect, int target);
//In the given array, move all the zeroes to the end of the vector
void moveZeroesToEnd(std::vector<int>& nums);
//Add one to the end of the vector
std::vector<int> addOne(std::vector<int>& digits);
//Randomly shuffle the given vector
std::vector<int> randomShuffle(std::vector<int>& myVect);
//What is the most repeated character and how many time do we see it?
int consecutiveString(std::string word);
//Which sub array will give us the largest sum?
int maxSubArray(std::vector<int>& nums);
//We need to solve the numberof step problem. Recursively and using dynamic programming
//Note the a person can move up: {1,2,3} steps at a time
int countSteps(int n);
int dynamicCountSteps(int n);
int dynamicCountSteps(int n, std::vector<int>& myVect);
//Decode the data, a->1, b->2,..., k->10,...,z->26
//Note: decode("123") = {abc,aw,am}
int dataDecode(std::string word);
int helperDataDecode(std::string data, int k, std::vector<int>& myVect);
//What is the longest common substring, between the two strings
//We will solve this using brute force and then dynamic programming
int longestCommonSub(std::string a, std::string b, int m, int n);
int longestCommonSubDynamic(std::string a, std::string b, int m, int n);
int longestCommonSubDynamic(std::string a, std::string b, int m, int n, int arr[M][M]);
//Counting sort
std::vector<int> countingSort(std::vector<int>& myVect, int maxRangeNum);
//Get all the subsets of a given set
std::vector<std::vector<int>> getAllSubsets(std::vector<int>& myVect);
//Given a point, Determine the k closest point to the given point, we will get an array of points
void printKClosetsPointsToGivenPoint(int k, int x, int y, std::vector<int>xCoordinates, std::vector<int>yCoordinates);
//Get k largest element in the unsorted array, assume that we get a valid k
int getKthLargest(std::vector<int>& myVect, int k);
//What is the substring that is a valid palindrome?
int longestPalindromeSubstring(std::string s);
//Sorted matrix, how many negative elements do we have? Find a better solution than O(n^2)
int numOfNegativesInMatrix(int arr[N][M]);
//Find all the sets that add up to the given target
int findSetsThatAddToTarget(std::vector<int>& myVect, int target);
int helperFindSets(std::vector<int>&myVect, int target, int i, std::unordered_map<std::string, int>& myMap);
// A utility function that returns maximum of two integers 
int max(int a, int b);
// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, std::vector<int>& wt,std::vector<int>& val, int n);
//Top k most frequent elements
std::vector<int> topKFrequent(std::vector<int>& nums, int k);
//Find the largest restangle in the given histogram
int largestRectangularArea(std::vector<int>& myVect);
//Can we jump all the way until the last index?
bool jumpToLastIndex(std::vector<int>& nums);

//Count the number of single values subtrees
//bool universalSubtreeCount(Node* root, int & count);




int main()
{

	//Required, to get true random values
	srand(time(NULL));
	std::string a = "AGGTAB";
	std::string b = "GXTXAYB";

	int num = longestCommonSub(a, b, a.length() , b.length());
	std::cout << num << "\n\n";

	//Lets determine the most repeated character
	std::string word = "AABCDDBBBEAA"; 
	consecutiveString(word);

	//We will now decode the given string
	std::string dataString = "133245";
	int val = dataDecode(dataString);
	std::cout << "We are decoding: " << dataString << " -> " << val << "\n\n";


	//Lets check the answers for counting steps
	val = countSteps(25);
	std::cout <<"Brute for counting the steps: "  <<  val << "\n\n";
	val = dynamicCountSteps(25);
	std::cout << "Dynamic solution counting the steps: "<< val << "\n\n";

	//Get all the subset of the given vector
	std::vector<int> myVector = { 1,2,3 };
	std::vector<std::vector<int>> subsetVect = getAllSubsets(myVector);
	std::cout << "Printing all the subsets of: [1,2,3].\n";
	for (unsigned int i = 0; i < subsetVect.size(); i++)
	{
		for (int num : subsetVect[i])
			std::cout << " " << num << "   ";
		std::cout << "\n";
	}

	//Find the first 4 points that are closest to the origin
	std::vector<int> xCor = { 3,3,7,5,4,35,5,44};
	std::vector<int> yCor = { 3,9,7,5,4,45,2,7};
	printKClosetsPointsToGivenPoint(4, 5, 5, xCor, yCor);


	//Lets test out our Knapsack solution
	std::vector<int> valueVect = { 5,8,22,2,13 };
	std::vector<int> weight = { 10,15,33,4,66 };
	int capacity = 55;
	int vectSize = valueVect.size();
	int myAns = knapSack(capacity, weight, valueVect, vectSize);
	std::cout << "Knapsack problem: \nWe have a capacity of: " << capacity << "\n";
	for (int i = 0; i < valueVect.size(); i++)
		std::cout << "Weight: " << weight[i] << "\t  Value: " << valueVect[i] << "\n";
	std::cout << "The maximum value that we can get is: " << myAns << "\n\n";


	std::vector<int> dataVector = { 1,2,3,4,5,3,3,2 };
	int rectangleArea = largestRectangularArea(dataVector);
	std::cout << "The max area that we found is: " << rectangleArea << "\n\n";


	std::vector<int> myVect = { -2,1,-3,4,-1,2,1,-5,4 };

	int value = maxSubArray(myVect);
	std::cout << value << "\n\n";

    return 0;
}





//Get the index of the first unique character.
int indexOfFirstUniqueCharacter(std::string word) {
	if (word.empty())
		return -1;

	std::vector<int> myVect(256, 0);
	for (char ch : word) {
		myVect[(int)ch] += 1;
	}

	for (unsigned int i = 0; i < word.size(); i++)
	{
		if (myVect[(int)word[i]] == 1)
			return i;
	}
	return -1;
}


//Get the first repeated character of the given string
char firstRepeatedCharacter(std::string word) {
	if (word.empty())
		return '\0';

	std::unordered_map<char, int> myMap;

	for (int i = 0; i < word.length(); i++) {
		if (myMap.find(word[i]) != myMap.end())
		{
			//We have found it
			return word[i];
		}
		else {
			myMap[word[i]] = i;
		}
	}
	return '\0';
}



//Do we have a pair of element where the product equals to the target
bool targetMultiplication(std::vector<int>& myVect, int target) {
	if (myVect.size() < 1)
		return 0;

	std::unordered_map<int, int> myMap;

	for (unsigned int i = 0; i < myVect.size(); i++)
	{	
		int currNum = myVect[i];

		if (currNum != 0 && target % currNum == 0) {
			int div = target / currNum;

			if(myMap.find(div) != myMap.end() )
			{
				int m = myMap[div];
				int n = i;
				return 1;
			}
			else {
				myMap[currNum] = i;
			}
		}
	
	}
	return 0;
}




//In the given array, move all the zeroes to the end of the vector
void moveZeroesToEnd(std::vector<int>& nums) {
	if (nums.size() == 0)
		return;

	int first;
	int last;
	int lastIndex;
	for (int i = nums.size() - 1; i>0; i--)
	{
		first = i - 1;
		last = i;
		lastIndex = last;
		while (nums[first] != 0)
		{
			--first;
			--last;
			if (first == -1)
				return;
		}
		while (first != lastIndex)
		{
			int temp = nums[first];
			nums[first] = nums[last];
			nums[last] = temp;
			++first;
			++last;
		}
	}
	return;
}




//Add one to the end of the vector
std::vector<int> addOne(std::vector<int>& digits) {
	if (digits.empty())
		return digits;
	int lastDigit = digits[digits.size() - 1];
	if (lastDigit <= 8)
	{
		digits[digits.size() - 1] += 1;
		return digits;
	}
	int carry = 1;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		int sum = digits[i] + carry;
		if (sum == 10)
		{
			carry = 1;
			digits[i] = 0;
		}
		else
		{
			carry = 0;
			digits[i] = sum;
		}
	}
	if (carry == 1)
	{
		std::vector<int>::iterator it = digits.begin();
		digits.insert(it, 1);
	}
	return digits;
}

//Randomly shuffle the given vector
std::vector<int> randomShuffle(std::vector<int>& myVect) {
	if (myVect.empty())
		return myVect;

	for (int i = myVect.size() - 1; i > 0; i--)
	{
		int randIndex = (rand() % (i + 1));

		int temp = myVect[i];
		myVect[i] = myVect[randIndex];
		myVect[randIndex] = temp;
	}
	return myVect;
}




//Great solution but run time is (2^ (a+b) )
//We will solve this using brute force and then dynamic programming
int longestCommonSub(std::string a, std::string b, int m, int n) {
	if (m == 0 || n == 0) {
		return 0;
	}
	else if (a[m - 1] == b[n - 1])
		return 1 + longestCommonSub(a, b, m - 1, n - 1);
	else //(a[m - 1] != b[n - 1])  
	{		
		int tempOne = longestCommonSub(a, b, m - 1, n);
		int tempTwo = longestCommonSub(a, b, m, n-1);

		int result = std::max(tempOne, tempTwo);
		return result;
	}
}

//What is the longest common substring, between the two strings
//We the solution using dynamic programming, note that we need  helperfunction
int longestCommonSubDynamic(std::string a, std::string b, int m, int n) {

	int arr[M][M];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = -1;
		}

	}

	return longestCommonSubDynamic(a, b, m, n, arr);
}


int longestCommonSubDynamic(std::string a, std::string b, int m, int n, int arr[M][M]) {	
	if (arr[m][n] > -1)
		return arr[m][n];
	
	int result;

	if (m == 0 || n == 0) {
		result = 0;
	}
	else if (a[m - 1] == b[n - 1])
		result = 1 + longestCommonSub(a, b, m - 1, n - 1);
	else //(a[m - 1] != b[n - 1])  
	{
		int tempOne = longestCommonSub(a, b, m - 1, n);
		int tempTwo = longestCommonSub(a, b, m, n - 1);

		int result = std::max(tempOne, tempTwo);
	}
	return result;
}




//What is the most repeated character and how many time do we see it?
int consecutiveString(std::string word) {
	if (word.empty())
		return 0;

	char maxCh = word[0];
	int max = 0;

	for (int i = 0; i < word.length(); i++) {
		
		char ch = word[i];
		int counter= 1;

		if (i != word.length() - 1)
		{
			while (ch == word[i + 1])
			{
				++counter;
				++i;

				if (i == word.length() - 1) {
					break;
				}
			}
		}

		if (max < counter) {
			max = counter;
			maxCh = ch;
		}
	}
	std::cout << "The character : " <<maxCh << "  with : " << max << std::endl;
	return max;
}



int dataDecode(std::string word)
{
	std::vector<int> myVect( word.length() +1 , -1);
	return helperDataDecode(word, word.length(), myVect);
}
int helperDataDecode(std::string data, int k, std::vector<int>& myVect) {

	//Two base cases.
	if (k == 0)
		return 1;
	//Given that "" = 1


	//Check for "0332" -> '0' = 0
	//Decoding of '0' does not exists
	int temp = data.length() - k;
	if (data[temp] == '0')
		return 0;

	if (myVect[k] > -1)
		return myVect[k];



	int result = helperDataDecode(data, k - 1, myVect);

	if (k >= 2) {
		std::string tempStr = data.substr(temp, 2);
		int value = std::stoi(tempStr);
		if (value <= 26)
			result = result + helperDataDecode(data, k - 2, myVect);
	}

	myVect[k] = result;
	return result;
}


//Solve the vector problem
int maxSubArray(std::vector<int>& nums) {
	if (nums.empty())
		return 0;

	int max = nums[0];
	int localMax = nums[0];

	for (int i = 1; i < nums.size(); i++) {

		localMax = std::max(nums[i], localMax + nums[i]);

		if (localMax > max)
			max = localMax;
	}
	return max;
}

//We need to solve the numberof step problem. Recursively and using dynamic programming
//Note the a person can move up: {1,2,3} steps at a time
int countSteps(int n) {

	//To get to the 0th step, there is only one way to get there, which is simply by not moving
	//To get to the 1st step, move up one time

	if (n < 0 ) 
		return 0;
	else if (n == 0)	
		return 1;
	else 
		return countSteps(n - 1) + countSteps(n - 2) + countSteps(n - 3);
}


int dynamicCountSteps(int n) {
	//To solve this problem using dynamic programming we have to use an array to store our results
	//We will use a vector because it is easier to handle
	//We will need a helper function to help us solve this problem
	std::vector<int>myVect(n + 1, -1);
	dynamicCountSteps(n, myVect);
	return myVect[n];
}

int dynamicCountSteps(int n, std::vector<int>& myVect) {
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else if (myVect[n] > -1)
		return myVect[n];
	else
	{
		myVect[n] = dynamicCountSteps(n - 1,myVect) + dynamicCountSteps(n - 2, myVect) + dynamicCountSteps(n - 3, myVect);
		return myVect[n];
	
	}	
}



//What is the substring that is a valid palindrome?
int longestPalindromeSubstring(std::string s){
	
	std::unordered_map<char, int> myMap;

	for (char ch : s)
		++myMap[ch];

	std::unordered_map<char, int>::iterator it = myMap.begin();
	std::unordered_map<char, int>::iterator itEnd = myMap.end();

	int count = 0;
	bool usedAnOddCharacter = false;

	while (it != itEnd)
	{
		if (it->second % 2 == 0)
			count = count + it->second;
		else {
			count = count + it->second - 1;

			if (!usedAnOddCharacter)
			{
				++count;
				usedAnOddCharacter = true;
			}
		}
		++it;
	}
	return count;
}


//Counting sort
std::vector<int> countingSort(std::vector<int>& myVect, int maxRangeNum) {

	//Use the max number plus one to build the second vector
	std::vector<int> secondVect(maxRangeNum + 1, 0);
	
	//We will store our sorted vector in answerVect
	std::vector<int> answerVect(myVect.size(), 0);

	//Get a frequency vector
	for (int num : myVect)
		secondVect[num] += 1;

	//Update the frequency vector with the sum of previous and current index
	for (int i = 1; i < secondVect.size(); i++)
		secondVect[i] = secondVect[i - 1] + secondVect[i];

	//Using the main vector and the freqVect we will organize the main vector
	//Start from the back of the main vector
	for (int i = myVect.size() - 1; i >= 0; i--)
	{
		//Get the current element 
		int currentNum = myVect[i];

		//Determine the location of the current element usind the second vector
		int index = secondVect[currentNum];
		//Decrement the index of the second vector
		--secondVect[currentNum];
		
		answerVect[index-1] = currentNum;
	}

	return answerVect;
}

//Get all the subsets of a given set
std::vector<std::vector<int>> getAllSubsets(std::vector<int>& myVect) {
	
	std::vector<std::vector<int>> subs(1, std::vector<int>());

	//For every possible subset size
	for (int i = 0; i < myVect.size(); i++)
	{
		int n = subs.size();

		for (int j = 0; j < n; j++) {
			subs.push_back(subs[j]);
			subs.back().push_back(myVect[i]);
		}
	}
	return subs;
}

//Given a point, Determine the k closest point to the given point, we will get an array of points
void printKClosetsPointsToGivenPoint(int k,int x, int y, std::vector<int>xCoordinates, std::vector<int>yCoordinates) {
	
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq; //Min heap
	//std::priority_queue<int, std::vector<int>, std::less<int> > pq;//Max heap

	//Key: distance and the value: index
	std::unordered_map<int, int> myMap;
	
	std::cout << "\n\n\n";

	for (int i = 0; i < xCoordinates.size(); i++)
	{
		int distance = pow((xCoordinates[i] - x),2) + pow((yCoordinates[i] - y), 2);
		std::cout << "x:" << xCoordinates[i] << ", y: " << yCoordinates[i] << " -> distance: " << distance << "\n";

		myMap[distance] = i;
		pq.push(distance);
	}

	std::cout << "\nThe " << k << " closest points of: (" << x << "," << y << "):\n";
	for (int m = 0; m < k; m++)
	{
		int index = myMap[pq.top()];
		std::cout << "(" << xCoordinates[index] << "," << yCoordinates[index] << ") -> " << pq.top() << "\n";
		//Just in case we have repeated keys and values
		myMap.erase(pq.top());

		pq.pop();
	}
	std::cout << "\n\n\n";

}

//Get k largest element in the unsorted array, assume that we get a valid k
int getKthLargest(std::vector<int>& myVect, int k) {
	std::priority_queue<int, std::vector<int>, std::less<int>> pq;
	for (int num : myVect)
		pq.push(num);

	int answer;
	for (int i = 0; i < k; k++)
	{
		answer = pq.top();
		pq.pop();
	}
	return answer;
}

//Sorted matrix, how many negative elements do we have? Find a better solution than O(n^2)
int numOfNegativesInMatrix(int arr[N][M]) {

	//Run time : O(N + M)
	int count = 0;
	int i = 0;//Starting from the first row
	int j = M - 1;//Starting from the last column

	while (j >= 0 && i < N) {

		if (arr[i][j] < 0)
		{
			count = count + (j + 1);
			i++;
		}
		else
			--j;
	}
	return count;

}



//Find all the sets that add up to the given target
int findSetsThatAddToTarget(std::vector<int>& myVect, int target) {
	std::unordered_map<std::string, int> myMap;
	return helperFindSets(myVect, target, myVect.size() - 1, myMap);
}
int helperFindSets(std::vector<int>&myVect, int target, int i, std::unordered_map<std::string, int>& myMap) {
	std::string key = std::to_string(target) + ":" + std::to_string(i);
	int answer;

	if (myMap.find(key) != myMap.end())
		return myMap[key];

	if (target == 0)
		return 1;
	else if (target < 0)
		return 0;
	else if (i < 0)
		return 0;
	else if (target < myVect[i])
		answer = helperFindSets(myVect, target, i - 1, myMap);
	else
		answer = (helperFindSets(myVect, target - myVect[i], i - 1, myMap)
				+helperFindSets(myVect, target, i - 1, myMap));

	myMap[key] = answer;
	return answer;
}		



// A utility function that returns maximum of two integers 
int max(int a, int b) { 
	return (a > b) ? a : b; 
}

// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, std::vector<int>& wt, std::vector<int>& val, int n)
{	
	int** K = new int*[n+1];
	for (int i = 0; i < n+1; i++)
		K[i] = new int[W+1];

	// Build table K[][] in bottom up manner 
	for (int i = 0; i <= n; i++)
	{
		for (int w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	int answer = K[n][W];
	//deallocate the array
	for (int i = 0; i < n+1; i++)
		delete[] K[i];
	delete[] K;

	return answer;
}

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
	std::unordered_map<int, int> myMap;
	for (int num : nums)
		++myMap[num];


	std::vector<int> answer;
	// pair<first, second>: first is frequency,  second is number
	std::priority_queue<std::pair<int, int>> pq;

	std::unordered_map<int, int>::iterator it = myMap.begin();
	std::unordered_map<int, int>::iterator itEnd = myMap.end();

	while (it != itEnd) {
		pq.push(std::make_pair(it->second, it->first));

		if (pq.size() > (int)myMap.size() - k) {
			answer.push_back(pq.top().second);
			pq.pop();
		}
		++it;
	}
	return answer;
}




//Find the largest restangle in the given histogram
int largestRectangularArea(std::vector<int>& myVect) {
	
	if (myVect.size() == 0)
		return 0;
	if (myVect.size() == 1)
		return myVect[0];

	std::stack<int> myStack;
	int max = 0;
	unsigned int i = 0;
	int currentMax = 0;

	while (i < myVect.size()) {
	
		if(myStack.empty() || myVect[myStack.top()] <= myVect[i])
		{
			myStack.push(i);
			i++;
		}
		else {
			currentMax = myStack.top();
			myStack.pop();

			int area = myStack.empty() ? myVect[currentMax] * i : myVect[currentMax] * (myStack.empty() ? i-1: i-1-myStack.top()) ;
			if (area > max)
				max = area;
		}
	
	}
	while (!myStack.empty()) {
		currentMax = myStack.top();
		myStack.pop();

		int area = myStack.empty() ? myVect[currentMax] * i : myVect[currentMax] * (myStack.empty() ? i - 1 : i - 1 - myStack.top());
		if (area > max)
			max = area;
	}
	return max;

}


//Can we jump all the way until the last index?
bool jumpToLastIndex(std::vector<int>& nums) {
	int size = nums.size();
	int step = nums[0];

	for (int i = 1; i < size; i++) {
		--step;

		if (step < 0)
			return false;

		if (nums[i] > step)
			step = nums[i];
	}
	return true;

}


/*
// This function increments count by number of single
// valued subtrees under root. It returns true if subtree
// under root is Singly, else false.
bool universalSubtreeCount(Node* root, int &count)
{
	// Return false to indicate NULL
	if (root == NULL)
	return true;

	// Recursively count in left and right subtrees also
	bool left = countSingleRec(root->left, count);
	bool right = countSingleRec(root->right, count);

	// If any of the subtrees is not singly, then this
	// cannot be singly.
	if (left == false || right == false)
	return false;

	// If left subtree is singly and non-empty, but data
	// doesn't match
	if (root->left && root->data != root->left->data)
		return false;

	// Same for right subtree
	if (root->right && root->data != root->right->data)
		return false;

	// If none of the above conditions is true, then
	// tree rooted under root is single valued, increment
	// count and return true.
	count++;
	return true;
}
*/
