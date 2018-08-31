
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

//Can we find the given elmement in the given array?
//Run time: 0(log n)
bool binarySearch(int arr[],int size, int x);

//Does the given string have all unique characters?
bool checkUnique(std::string const& myString);

//Is one string a permutation of the other string?
bool checkPermutation(std::string a, std::string b);

//If the string has a space character, replace it with '%20'
std::string urlify(std::string str, int capacity);

//Does the given string have permutation that is a palindrome?
bool checkPalindromePermutation(std::string theString);

//Is string a one step away from string b. 
//A step is done by: {replacing a character, inserting a character, or removing a character}
bool oneAway(std::string a, std::string b);

//Print all the permutations of a string, we will need a use a helper function.
void getPermutation(std::string word);
void getPermutation(std::string word, std::string prefix);	

//Compress to this format:  "aabcccccaaa" -> "a2b1c5a3"
std::string stringCompression(std::string myString);

//Reverse a string
void stringReverse(std::string & a);

//Print a matrix
void printMatrix(int m[][10]);

//Rotate a matrix by 90 degrees to the right.
void rotateMatrix(int myMatrix[][5], int n);



int main()
{

	//How do we get the size of an array
	int myarr[3] = { 1,3,4 };

	//How do we get the length of an array
	//We get the size of the entire array, 
	//in this case we get 12 bytes then we divide by the size of the first element
	//In this case the size of the first element is an integer, 
	//therefore 12/4 = 3 element in our array.
	int mySizeArray = sizeof(myarr) / sizeof(*myarr);

	
	std::string myString = "carro";
	std::cout << checkUnique(myString) << "\n";

    
	std::string a = "fdasfdsafdgsasdgf";
	std::string b = "fdasfdsafdgsasgdf";

	bool checker = checkPermutation(a, b);
	std::cout << "\nIs this pair a permutation: " << a << " , " << b << " : " << checker << "\n\n";
	std::string theString = "Mr John Smith        ";

	std::cout << "\n" << urlify(theString,13) << "ENDED\n";

	theString = "Tact Cao     ";
	checkPalindromePermutation(theString);
	std::cout << "\n"; 


	//Solve the one away problem
	a = "turtle";
	b = "tutle";
	std::cout << "\n\nDo we have one away: "<<oneAway(a, b);

	std::cout << "\n";

	a = "aaabbbbbrrrxaaaaav";

	std::cout << "Compressing: " << a << "\tInto: " << stringCompression(a) << "\n\n";


	//Lets create a NXN matrix and then we will rotate it
	int arr[5][5] = { {1,2,3,4,5},{ 1,2,3,4,5 },{ 1,2,3,4,5 },{ 1,2,3,4,5 },{ 1,2,3,4,5 } };

	
	//Lets print out the 2-D array
	for (int i = 0; i < 5; i++) {
		std::cout << "\n";
		for (int j = 0; j < 5; j++) {
			std::cout << arr[i][j] << "  ";
		}
	}
	

	//Lets reverse a string
	a = "helloIamHungry";
	stringReverse(a);
	a = "helloHungry";
	stringReverse(a);

	std::cout << "\n\n";



	//Lets solve the zero matrix problem
	//Lets create our matrix with random elements and then we will print out all the values to see
	//our matrix
	int myMatrix[10][10];
	//Let give it random elements
	srand(time(NULL));
	for (int m = 0; m < 10; m++) {
		for (int n = 0; n < 10; n++) {
			//The random element range will be between:[0-50]
			int randomValue = rand() % 51;
			myMatrix[m][n] = randomValue;
		}
	}
	std::cout << "Our Matrix:\n";
	//We have populated our Matrix, lets print the matrix.
	printMatrix(myMatrix);
	std::cout << "\n\n";

	//How do we solve the Zero matrix problem? 
	//If we find a 0 in our matrix then we have to set that row and column to zero
	bool row[10] = { 0 };
	bool column[10] = { 0 };

	//Traverse the Matrix and set the row to 1 and column to 1 in the given position
	for (int m = 0; m < 10; m++) {
		for (int n = 0; n < 10; n++) {
			
			if (myMatrix[m][n] == 0) {
				row[m] = 1;
				column[n] = 1;
 			}
		}
	}

	//traverse the row array and 
	//if we have a one then we have to make all the elements in this row equal to 0  
	for (int p = 0; p < 10; p++) {
		if (row[p]) {
			//Make all the element of this row equal to zero
			for (int r = 0; r < 10; r++)
			{
				myMatrix[p][r] = 0;
			}

			
		}
	}

	//traverse the column array and 
	//if we have a one then we have to make all the elements in this column equal to 0  
	for (int p = 0; p < 10; p++) {
		if (column[p]) {
			//Make all the element of this row equal to zero
			for (int r = 0; r < 10; r++)
			{
				myMatrix[r][p] = 0;
			}

		}
	}

	//We have solve the zero matrix problem, so lets print out this new matrix
	std::cout << "\n\nThe Solution Matrix: ";
	printMatrix(myMatrix);
	std::cout << "\n\n";


	return 0;
}




//ALgorithm: Determine if a string has all unique characters
//What if you cannot use additional data structures?
bool checkUnique(std::string const & myString)
{

	if (myString.length() > 256) {
		//By the pigeonhole principle
		return 0;
	}

	//The best solution will be to use a hash map
	std::unordered_map<char, int> myMap;

	//If we can find the current character in the map, then return false
	for (int i = 0; i < myString.length(); i++) 
	{
		if (myMap.find( myString.at(i) ) != myMap.end() ) {
			return false;
		}
		else {
			myMap[myString.at(i)] = i;
		}
	}
	return 1;



	/*
	std::vector<bool> chFreq(256, 0);

	if (myString.length() > 256) {
		//Pigeonhole principal
		return false;
		//There exists a repeated characted.
	}


	for (char ch : myString) {

		int index = (int)ch;

		if (chFreq[index] == 1) {
			return false;
		}
		chFreq[index] = chFreq[index] + 1;
	}
	return true;


	/* We now solve it without additional data structures(Bad solutions, but they work)
	
	for(char ch: myString){
		
			compare the given character with the rest of the characters  
		       	O(n^2) time complexity
			or
			sort the string, O(n(log n)), then check previous with the current

	
	}
	
	
	*/

}


//ALgorithm: Given two string of the same length, decide if one is a permutaion of the other
bool checkPermutation(std::string a, std::string b) {

	//Check the length of the strings
	if (a.length() != b.length()) {
		return false;
	}

	//We will now create one array, one for the first string.
	//THe size of the array is 128 with all element 0;
	int theArr[128] = { 0 };

	//Traverse the first string and then modify the first Arr properly
	for (char ch : a) {
		theArr[(int)ch] = theArr[(int)ch] + 1;
	}
	//Traverse the second string and start deducing the arr properly.
	for (char element : b)
	{
		theArr[(int)element] = theArr[(int)element] - 1;
		if (theArr[(int)element] < 0){
			return false;
		}
	}
	//Because of the same length, 
	//since there are no negative values then there are no positive values
	//Therefore return true
	return 1;

}

//Algorithm: URL-ify a string, For every space replace with %20,   
//and remove the data after the True string counter
std::string urlify(std::string str, int capacity) {

	std::string url = "";

	for (char ch : str) {
		if ((int)ch == 32) {
			url = url + "%20";
		}
		else {
			url = url + ch;
		}
	}
	return url;
}

//ALgorithm : Palindrome Permutatation: 
//Given a string , Check if it is a permitation of a palindrome, it okay to ignore spaces.
bool checkPalindromePermutation(std::string theString) {

	if (theString.length() == 0) {
		return 1;
	}

	//We must update a vector, but only for valid entries
	std::vector<int> myVect(128, 0);


	//For all the character in the string
	for (char ch : theString) {
		
		//We will ignore the space character
		if ((int)ch != 32) {
			
			//If we have an uppercase then we have must update the lower case version
			if ((int)ch < 96) {
				//Update the vector but make sure to add 32
				myVect[(int)ch + 32] += 1;
			}
			else{
				myVect[(int)ch] += 1;
			}
		}
	}

	//We have the vector that we want and make sure that at most one element is allowed to be odd
	bool flag = 0;
	for (int i : myVect) {
		
		if (i % 2 == 1) {
			//We have found an odd element
			if (flag == 1) {
				return 0;
			}
			else
			{
				flag = 1;
			}
		}
	}
	return 1;


}


//Algorithm: One Away, Three types of edits, (insert, remove,replace) ,    
//We get as input two strings check that string are one away
bool oneAway(std::string a, std::string b) {

	int delta = a.length() - b.length();

	if (delta < -1 || delta > 1)
	{
		return 0;
	}

	if (delta == 0) {
		//Same length, allow at most one error
		bool flag = 0;

		for (int i = 0; i < a.length(); i++) {
			if (a.at(i) != b.at(i)) {
				if (flag == 1) {
					return 0;
				}
				else {
					flag = 1;
				}
			}
		}
		//We have a valid one away
		return 1;

	}
	std::string smaller = (delta > 0) ? b:a ;
	std::string larger = (delta > 0) ? a:b ;

	

	int i = 0;
	int j = 0;

	bool flag = 0;
	
	while (i < smaller.length() && j < larger.length()) {
		
		if (smaller.at(i) != larger.at(j)) {			
			if (flag == 1) {
				return 0;
			}
			else
			{
				flag = 1;
				++j;
			}
		
		}
		else {
			++i;
			++j;
		}
	}
	return 1;
}


//Algorithm: String compression,    
//If aaabbcc then we should get the string a3b2c2, 
//if compression is larger then return the original string
std::string stringCompression(std::string myString){

	std::string ansStr = "";
	for (int i = 0; i < myString.length(); i++) {

		char ch = myString.at(i);
		int count = 1;

		//Careful with the bounds, 
		//mainly we have to be careful with the last element if it is a new character.
		if( i !=myString.length()-1)
		{ 
			while(ch == myString.at(i+1))
			{
				++count;
				++i;
				if (i == myString.length()-1) {
					break;
				
				}
			}
		}
		//Convert the number into a string
		std::string numString = std::to_string(count);

		ansStr = ansStr + ch + numString;

	}

	if (myString.length() < ansStr.length()) {
		return myString;
	}

	return ansStr;
}


void stringReverse(std::string & a) {

	//Lets reverse the string and print it out
		
	int i = 0;
	int j = a.length() - 1;
	std::cout << "\nOriginal String: " << a << "\n\n";

	while (i < j) {
		char temp = a.at(i);

		a.at(i) = a.at(j);  
		a.at(j) = temp;

		++i;
		--j;
	}
	std::cout << "Reversed: " << a << "\n\n";
}


void printMatrix(int m[][10]) {
	//Use two for loops to print out all the elements in the matrix
	for (int i = 0; i < 10; i++) {
		std::cout << "\n";
		for (int j = 0; j < 10; j++)
		{
			std::cout << m[i][j] << "\t";
		}
	}
}


//Get the permutation of a string, it will need a helper function.
void getPermutation(std::string word) {
	getPermutation(word, "");
	return;
}
void getPermutation(std::string word, std::string prefix)
{
	//Check if the entire word is in the prefix
	if (word.length() == 0) {
		std::cout << prefix << "\n";
	}
	else {
		//Do this for every character in the string
		for (int i = 0; i < word.length(); i++) {
		
			//Get all the character from our string except for the current character
			std::string rem = word.substr(0, i) + word.substr(i + 1);
			//Call the permutation function, 
			//with (rem) and the (prefix plus the current character)
			getPermutation(rem, prefix + word.at(i));
		}
	}
	return;
}




//Binary Search algorithm, we return the index position if we find the given element 
bool binarySearch(int arr[],int size, int x) {

	int left = 0;
	int right = size - 1;

	while(left <= right){
	
		//Get the middle index
		int mid = (left + right) / 2;

		if (arr[mid] == x) {
			return 1;
		}

		if (arr[mid] < x) {
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}

	}
	return 0; 
}


void rotateMatrix(int myMatrix[][5], int n) {

	//We will rotate the matrix value by value from the outside square into the inside.
	//How many inner squares we will rotate. Just divide by two. 
	for (int layer = 0; layer < n / 2; layer++) {
		
		//Determine the bounds
		int first = layer;
		int last = n - 1 -layer;

		//We are ready to switch all the values, 
		//iterate thorugh all the elements of the given layer
		for (int i = 0; i < last; i++) {
			
			int offset = i - first;

			//Save the top, so now overwrite the top
			int top = myMatrix[first][i];

			//left to top 
			myMatrix[first][i] = myMatrix[last-offset][first];
			
			//bottom to left 
			myMatrix[last-offset][first] = myMatrix[last][last - offset];

			//right to bottom
			myMatrix[last][last - offset] = myMatrix[i][last];
			
			//top to right 
			myMatrix[i][last] = top;

		}

	
	}

}


