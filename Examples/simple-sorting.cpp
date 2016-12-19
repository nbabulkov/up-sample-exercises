#include <iostream>
#include <time.h>
#include <stdlib.h> 


//
// Help Functions:
//

void swap(int* pLeft, int* pRight)
{
	int temp = *pRight;
	*pRight = *pLeft;
	*pLeft = temp;
}


// randomly generates an array with a limit on the elements
void genArray(int* arr, const int size, int limit)
{
	// seeding the random generator
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{	
		// taking a random value from '0' to 'limit - 1'
		arr[i] = rand() % limit;
	}
}

// prints the elements of an array with their position
void print(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << ") " << arr[i] << std::endl;
	}
}

// checks if an array is sorted
bool isSorted(int* arr, const int size)
{
	// 'size - 1' because we don't want get out of bounds 
	// when accessing the 'i + 1'-th position
	for (int i = 0; i < size - 1; i++)
	{
		// if the next element is smaller than
		// the current element - the array isn't sorted
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}


//
// Basic Sorting Algorithms:
//

void bubleSort(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		bool isSorted = true;

		// the limit is 'size - i' because
		// the last 'i' elements are already sorted
		// and '- 1' because we don't want get out of bounds 
		// when swaping on the 'j + 1'-th position
		for (int j = 0; j < size - i - 1; j++)
		{
			// the swap pushes the max element last
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				isSorted = false;
			}
		}

		// if no change was made then 
		// the array is sorted
		if(isSorted)
			return;
	}
}

void selectionSort(int* arr, const int size)
{
	// Array of one or no elements is already sorted
	if (size == 1 || size == 0)
		return;

	for (int i = 0; i < size - 1; i++)
	{
		// finding the index of the max element
		int maxIdx = 0,
			idx = 1;
		while(idx < size - i)
		{
			if (arr[idx] > arr[maxIdx])
				maxIdx = idx;
			idx++;
		}

		// swaping it with the last element
		swap(&arr[maxIdx], &arr[size - i - 1]);

		// now the last 'i' elements are sorted
	}

}

void insertionSort(int* arr, const int size)
{
	// Array of one or no elements is already sorted
	if (size == 1 || size == 0)
		return;


	// we choose the 'i'-th element as current element
	for (int i = 1; i < size; i++) 
	{
		// find where the current element must be inserted
		// in the sorted part of the array so it can be
		// sorted again after the opeation

		// idx is the position where we want to insert
		int idx = 0; 
		while (arr[idx] < arr[i] && idx < i)
		{
			idx++;
		}

		// if the insert position gets out of the bounds 
		// it means that the element is the biggest of those in the sorted part
		// and can leave it in the end
		if (idx != i)
		{
			// if the position is in the sorted part then
			// we must move every element forward from the position
	 		// to make a place to insert the element there
			int element = arr[i];
			for (int j = i; j > idx; j--) 
			{
				arr[j] = arr[j - 1];
			}
			arr[idx] = element;
		}
	}
}

int main()
{
	const int size = 100;
	int arr[size];
	genArray(arr, size, 1000);
	bubleSort(arr, size);
	selectionSort(arr, size);
	insertionSort(arr, size);

	std::cout << (isSorted(arr, size)? "True\n": "Else\n");
	print(arr, size);
	return 0;
}