// Chapter3.cpp : Defines the entry point for the console application.
// Bit Manipulation

#include <iostream>
#include <string>
#include <algorithm>    // std::max


//Function prototypes to set bits, get bits.


//Get the bit at position i
bool getBit(int num, int i);

//In position i, set the given bit
void setBit(int& num, int i, int bit);

//Print all the bits of the given number
void printInBits(int number);

//At position i, clear the bit
int clearBit(int& num, int i);

//At position i of numOne, get the bit
//At position j of numTwo, get the bit
//Now compare both bits, Are they equal?
bool bitEqual(int numOne, int i, int numTwo, int j);

//Convert the bits of a number, into string.
void integerToString(int val); 

//Do the sum algorithm, but only using bit manipulation
int binarySum(int a, int b);

//You have an integer and you can flip exactly one bit
//Write code to find the length of the longest sequence 
//of 1s you could create
int flipToWin(int number);

//Challenge, Insert a bits into a bigger bits
//We take in two 32 bit integer, 
//int M, int N, We need to place all the N bits into the M, 
//Starting at position j and ending at position i.
int insertion(int M, int N, int j, int i);


int main()
{

	int number = 45;

	std::cout << "What is our original value: " << number << "\n";
	printInBits(number);


	//We will now test the set bit function;
	setBit(number, 3, 0);
	std::cout << "What is the new value: " << number << "\n";
	printInBits(number);

	//We will now test the set bit function;
	setBit(number, 2, 0);
	std::cout << "What is the new value: " << number << "\n";
	printInBits(number);

	//We will now test the set bit function;
	setBit(number, 3, 1);
	std::cout << "What is the new value: " << number << "\n";
	printInBits(number);
	

	//Test out the clearBit function and then test out bitEqual function

	clearBit(number, 5);
	std::cout << "What is the new value: " << number << "\n\n\n";
	printInBits(number);

	int numberTwo = 40;
	std::cout << "Second value: " << numberTwo << "\n";
	printInBits(numberTwo);


	std::cout << "Compare:(9 pos 3 with 40 pos 5)\n";
	std::cout << "Are the bits the same: " << bitEqual(number, 3, numberTwo, 5) << "\n";

	std::cout << "\nCompare:(9 pos 5 with 40 pos 5)\n";
	std::cout << "Are the bits the same: " << bitEqual(number, 5, numberTwo, 5) << "\n";

	std::cout << "\nCompare:(9 pos 7 with 40 pos 0)\n";
	std::cout << "Are the bits the same: " << bitEqual(number, 7, numberTwo, 0) << "\n";

	std::cout << "\nCompare:(9 pos 0 with 40 pos 3)\n";
	std::cout << "Are the bits the same: " << bitEqual(number, 0, numberTwo, 3) << "\n\n\n";
	
	int  valM = 5434325;
	int  valN = 35432;

	insertion(valM, valN, 19,0);

	std::cout << "\n\n";
	int v = 55;
	integerToString(v);
	std::cout << "\n\n";

	return 0;
}

bool getBit(int num, int i) {
	//We will get the bit at position

	//AND the number with (1<<i), that will gives us the bit
	num = num & (1 << i);

	//If the modified value is zero, then we have a zero, otherwise we have a one.
	if (num == 0) {
		return 0;
	}
	else{
		return 1;
	}
}


//Define the function that will set a bit for us
void setBit(int & num, int i, int bit) {

	//We need to use or, in order to modify the specific bit position

	//Move the bit into a the correct position
	int temp = (bit << i);

	//We need to mask the original number by AND with ~(1<<i)

	int mask = ~(1 << i);
	num = num & mask;

	//Now use OR in order to modify this specific bit position
	num = num | temp;

	//We have updated the original number, so we just need to return it
	return;
}


void printInBits(int number) {

	//Lets create a string for our bit representation
	std::string myBitRepresentation = "";


	for (int i = 31; i >= 0; i--) {
		
		
		if (getBit(number, i))
		{
			myBitRepresentation = myBitRepresentation + "1";

		}
		else {

			myBitRepresentation = myBitRepresentation + "0";

		}
	}

	std::cout << myBitRepresentation << "\n\n";


}


int clearBit(int& num, int i) {
	//We just need to mask the specific bit position
	int mask = ~(1 << i);
	num = num & mask;
	return num;
}


bool bitEqual(int numOne, int i, int numTwo, int j)
{
	//DEtermine if we have equal bits in a given position
	//What is numOne, position i?
	int temp1 = numOne & (1 << i);
	int bitOne;
	if (temp1 == 0) {
		bitOne = 0;
	}
	else
	{
		bitOne = 1;
	}


	//What is in numTwo at j?
	int tempTwo = numTwo & (1 << j);
	int bitTwo;
	if (tempTwo == 0) {
		bitTwo = 0;
	}
	else{
		bitTwo = 1;
	}

	//Check bitOne and bitTwo
	if (bitOne == bitTwo) {
		return 1;
	}
	else {
		return 0;
	} 


}



int insertion(int M, int N, int j, int i) {

	//Lets print out the contents of M and N
	//Every integer is 4 bytes, therefore print all the 32 bits of the integers
	std::string mbits;
	std::string nbits;

	int nSize = 0;

	for (int i = 31; i >= 0; i--) {
		//Get every single digit and then make it into a character
		int bitM = getBit(M, i);
		int bitN = getBit(N, i);

		//Convert the integer into a characte and then add it to the string of bits
		if (bitM == 0) {
			mbits = mbits + "0";
		}
		else {
			mbits = mbits + "1";
		}

		if (bitN == 0) {
			nbits = nbits + "0";
		}
		else {
			//For the case that we see a one, then we can determine that nSize is larger ,
			//So we need to update the nSize.
			if (nSize < i) {
				nSize = i;
			}
			nbits = nbits + "1";
		}


	}
	std::cout << "M: " << mbits << "\nN: " <<nbits << "\n\n";
	//So how will we insert the Nbit into the Mbits
	std::cout << "The size of N is : " << nSize << "\n\n";
	//We need to insert nSize elements into the M.

	while (j >= i)
	{
		//Starting at position j, we need to insert all the way to position i
		//On M, we need to get to index j
		//On N, we need to get to index nSize
	
		int val = getBit(N, nSize);
		setBit(M, j, val);
		--nSize;
		if (nSize < 0) {
		
			break;
		}
		--j;
	}

	printInBits(M);




	return 1;
}




void integerToString(int val) {
	for (int i = 31; i >= 0; i--) {
		//Get under the correct position
		int temp = (val >> i);

		//Clear all the element except for the first digit
		temp = temp & 1;

		std::cout << temp;
	
	}
}

int flipToWin(int number) {
	//You can flip exactly one bit from 0 to 1.
	//Find the length of the largest sequence of 1s that you can create.

	if (number == 0) {
		return 1;
	}

	//When we have more than two bits that are one, then we have a several issues.
	
	//Bad solution, Turn a single digit into a 1 and then get the largest sequence of 1s			//Do this to every index, which means to from index [31 to 0]

	//Better Solution, 
	
	//Check if we already have the largest solution
	if (~number == 0)
	{
		return (sizeof(number) * 8);
	}

	int currentLength = 0;
	int prevLength = 0;
	int maxLength = 1;   //It is guranteed that we can always find a length of 1.

	//While there exists 1s in our 32 bits.
	while (number != 0) {

		//Get the current bit.
		int bit = (number & 1);

		//If bit is 1 
		if ( bit == 1)
		{
			//Increment the current length
			++currentLength;
		}
		else if (bit == 0) {
			//Look at the next bit and then update the data properly
			int secondBit = (number & 2);

			prevLength = secondBit == 0 ? 0 : currentLength;
			currentLength = 0;
		}

		maxLength = std::max(currentLength + prevLength + 1, maxLength);

		//In C++ we cannot use a logical shift:  >>>    
		//to gurantees us that we are padding with a zero, after the shift.
		number = number >> 1;
		//We have to shift and then clear this given bit which is the most significant bit, 
		//the 31's bit
		clearBit(number, 31);
	}
	return maxLength;
}


//To get the sum, we will use recursion
int binarySum(int a, int b) {
	if (b == 0) {
		return 0;
	}

	int partialSum = a ^ b;
	int carry = (a&b) << 1;

	return binarySum(partialSum, carry);
}
