// RecursiveDojo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


int const M = 5;
int const N = 5;

//Function Prototype
int longestCommonSub(std::string a, std::string b, int m, int n);

int longestCommonSubDynamic(std::string a, std::string b, int m, int n);
int longestCommonSubDynamic(std::string a, std::string b, int m, int n, int arr[M][M]);


int consecutiveString(std::string word);

int dataDecode(std::string word);
int helperDataDecode(std::string data, int k, std::vector<int>& myVect);

int maxSubArray(std::vector<int>& nums);


int main()
{
	std::string a = "AGGTAB";
	std::string b = "GXTXAYB";


	int num = longestCommonSub(a, b, a.length() , b.length());
	std::cout << num << "\n\n";

	
	std::string word = "AABCDDBBBEAA"; 
	//There are three B's consecutively, 
	//The answer should be: B with 3
	consecutiveString(word);



	int val = dataDecode("12345");
	std::cout << val << "\n\n";

	std::vector<int> myVect = {-2,1,-3,4,-1,2,1,-5,4 };

	int value = maxSubArray(myVect);
	std::cout << value << "\n\n";



    return 0;
}



//Great solution but run time is (2^ (a+b) )

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

//We need to sove this dynamic programming
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