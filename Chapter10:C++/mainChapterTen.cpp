
//Chapter 10: Sorting Algorithms

#include <iostream>
#include <ctime>
#include <vector>




//Function prototypes


//Print vector function
void printAll(std::vector<int>& vect);

//Selection Sort
void selectionSort(std::vector<int>& vect);

//Bubble Sort
void bubbleSort(std::vector<int>& vect);

//Insertion Sort
void insertionSort(std::vector<int>& vect);

//QuickSort Algorithm
void quickSort(std::vector<int>& vect, int left, int right);
//A helper function for the quickSort algorithm
int partition(std::vector<int>& vect, int left, int right);

//Merge sort will require two helper functions
void mergeSort(std::vector<int>&myVect);

//Helper functions 
void mergeSort(std::vector<int>&myVect, std::vector<int>&helper, int low, int high);
void merge(std::vector<int>&myVect, std::vector<int>&helper, int low, int middle, int high);

int main()
{

	//We will go over 5 sorting algorithms
	//Slection Sort
	//Bubble Sort
	//Insertion Sort
	//QuickSort
	//MergerSort

	srand(time(NULL));
	//Lets create an array with a random elements
	std::cout << "We will create an array of the given size: ";

	int size;
	std::cin >> size;

	std::vector<int> myVect;
	//Lets populate the vector with the given size.
	for (int i = 0; i < size; i++)
	{	
		//The random value will have a range between: [1 -100]
		int randomVal = (rand() % 100 + 1);
		myVect.push_back(randomVal);
	}

	//Lets print the vector to see what we have
	std::cout << "\n\nORIGINAL VECTOR:";
	printAll(myVect);

	//Save this vector in a temp vector.
	std::vector<int> tempVect = myVect;
	//Now we will sort the temp vector using the selection algorithm : O(n^2)
	selectionSort(tempVect);
	std::cout << "\nAfter Selection Sort:";
	printAll(tempVect);
	



	
	tempVect = myVect;
	//Now we will sort the temp vector using the bubble sort algorithm : O(n^2)
	bubbleSort(tempVect);
	std::cout << "\nAfter Bubble Sort:";
	printAll(tempVect);


	
	tempVect = myVect;
	//Now we will sort the temp vector using the insertion algorithm : O(n^2)
	insertionSort(tempVect);
	std::cout << "\nAfter Insertion Sort:";
	printAll(tempVect);
	


	tempVect = myVect;
	//Now we will sort the temp vector using the quickSort algorithm : O(nlogn)
	quickSort(tempVect, 0, (tempVect.size() - 1) );
	std::cout << "\nAfter Quick Sort:";
	printAll(tempVect);

	tempVect = myVect;
	//Now we will sort the temp vector using the mergeSort algorithm : O(nlogn)
	mergeSort(tempVect);
	std::cout << "\nAfter Merge Sort:";
	printAll(tempVect);

	std::cout << "\n\n\n";
    return 0;
}



void printAll(std::vector<int>& vect) {
	//Print all the elements that are in my vector
	std::cout << "\nPrinting Vector:\n";
	for (int val : vect) {
		std::cout << val << "  ";
	}
	std::cout << "\n";
	return;
}







//Selection Sort
void selectionSort(std::vector<int>& vect) {
	//Description: Select the smallest
	//Then swap accordingly 
	int smallest;
	for (int i = 0; i < vect.size()-1; i++) {
		
		//Save the current index, this will swap with the smallest value in the vector.
		int indexOne = i;
		int indexTwo = i;

		smallest = vect[i];

		for (int j = i+1; j < vect.size(); j++) {
			if (smallest > vect[j]) {
				//We found a smallest value so update the smallest index
				smallest = vect[j];
				indexTwo = j;
			}
		}
		//Do the swap
		int temp = vect[indexOne];
		vect[indexOne] = vect[indexTwo];
		vect[indexTwo] = temp;
	
	}


	return;
}


//Bubble Sort
void bubbleSort(std::vector<int>& vect) {
	//Bubble sort will do a swap through each pass and we only need to do this run n-1 times
	//Therefore we get n^2 run time
	
	bool swapOccured = 1;
	//while we are still swapping.
	while (swapOccured)
	{
		swapOccured = false;

		for (int i = 0; i < vect.size() - 1; i++) {
			
			//Check the current value and alse the next value
			if (vect[i] > vect[i + 1]) {
				//We have to do a swap
				swapOccured = 1;

				int temp = vect[i];
				vect[i] = vect[i + 1];
				vect[i + 1] = temp;
			}
		}
	
	}

	return;
}



//Insertion Sort
void insertionSort(std::vector<int>& vect) {

	//For all the elements, starting at 1.
	for (int i = 1; i < vect.size(); i++) {
		//Select the first unsorted element
		int element = vect[i];
		//And save the previous index
		int j = i-1;
		
		//We will do the shifting, while j>=0 and vect[j] > element
		while (j >= 0 && vect[j] > element) {
		
			vect[j + 1] = vect[j];
			--j;
			
		}
		//Insert the unsorted element into the correct position.
		vect[j + 1] = element;
	}


	return;
}




//QuickSort Algorithm
void quickSort(std::vector<int>& vect, int left, int right) {

	if (left < right) {
	
	
		//Use a helper function called partition
		int index = partition(vect, left, right);

		quickSort(vect, left, index - 1);
		quickSort(vect, index + 1, right);
	}

}

//A helper function for the quickSort algorithm
int partition(std::vector<int>& vect, int left, int right) {
	
	//Get a pivot element
	//Make the right most element be the pivot
	int pivot = vect[right];
	int pIndex = left;
	
	int temp;
	
	//for all the element in the given sub vector, except for the pivot element. 
	for (int i = left; i < right; i++) {

		//Is the current element smaller that pivot element?
		if (vect[i] <= pivot) {
			//We have to swap the current element and the pIndex element
			temp = vect[i];
			vect[i] = vect[pIndex];
			vect[pIndex] = temp;

			//increment the pIndex
			++pIndex;

		}
	}

	//Another swap, swapping pivot element with pIndex element
	temp = vect[pIndex];
	vect[pIndex] = vect[right];
	vect[right] = temp;

	//Note that everything before the pIndex is smaller all ready sorted
	return pIndex;
}








//Merge sort will require two helper functions
void mergeSort(std::vector<int>&myVect) {

	//We need to initialize a helper vector
	std::vector<int> helper(myVect.size(),0);
	mergeSort(myVect, helper, 0, myVect.size() - 1);
	return;
}

//Helper functions 
void mergeSort(std::vector<int>&myVect, std::vector<int>&helper, int low, int high) {

	if (low < high) {
		int middle = (low + high) / 2;
		//We need to mergeSort the left side and the right side 
		//and at the end we have to merge.
		mergeSort(myVect, helper, low, middle);
		mergeSort(myVect, helper, middle+1, high);
		merge(myVect, helper, low, middle, high);

	}


}
void merge(std::vector<int>&myVect, std::vector<int>&helper, int low, int middle, int high) {
	//Copy both halves into the helper function
	for (int i = low; i <= high; i++) {
		helper[i] = myVect[i];
	}

	//We will need to keep track of three things
	//We will focus on the first element of the left side, 
	//and also the first element of the right side.
	int helperLeft = low;
	int helperRight = middle+1;
	int current = low;


	//Compare both elements, 
	//until reaching the end of the left side and reaching the end of the right side
	while (helperLeft <= middle && helperRight <= high) {
		
		//Place the smaller element into our original vector
		if (helper[helperLeft] <= helper[helperRight]) {
			myVect[current] = helper[helperLeft];
			++helperLeft;
		}
		else {
			myVect[current] = helper[helperRight];
			++helperRight;

		}

		++current;
	}

	//We will only have remaining element from the left side, 
	//and therefore we need to copy the rest of the elements into our original vector
	int remaining = middle - helperLeft;

	for (int j = 0; j <= remaining; j++) {
		myVect[current + j] = helper[helperLeft + j];
	}

}
