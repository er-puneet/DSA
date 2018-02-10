#include <stdio.h>

int findCandidate(int arr[], int size)
{
	int maj_index = 0, count = 1;
	for (int i=1; i<size; i++)
	{
		if (arr[maj_index] == arr[i])
			count++;
		else
			count--;
		if (count == 0)
		{
			maj_index = i;
			count = 1;
		}
	}
	return arr[maj_index];
}

int isMajority(int arr[], int size, int candidate)
{
	int count = 0;
	for (int i=0; i<size; i++)
	{
		if(arr[i] == candidate)
			count++;
		if(count > size/2)
			return 1;
	}
	
	return 0;
}

void printMajority(int arr[], int size)
{
	int candidate = findCandidate(arr, size);
	
	printf("Majority element candidate: %d\n", candidate);
	
	if (isMajority(arr, size, candidate))
		printf("Majority element found: %d\n", candidate);
	else
		printf("No majority element found\n");
}

int main()
{
	int arr[] = {1, 2, 2, 3, 5, 2, 2, 6, 8, 9, 10, 2 , 2, 2, 2};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	printMajority(arr, arr_size);
}

/*

Majority Element: A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one
such element).
Write a function which takes an array and emits the majority element (if it exists), otherwise prints NONE as follows:
I/P : 3 3 4 2 4 4 2 4 4
	O/P : 4
I/P : 3 3 4 2 4 4 2 4
	O/P : NONE

METHOD (Using Moores Voting Algorithm)
This is a two step process.
	1. Get an element occurring most of the time in the array. This phase will make sure that if there is a majority element then it will return that only.
	2. Check if the element obtained from above step is majority element.

Finding a Candidate:
The algorithm for first phase that works in O(n) is known as Moores Voting Algorithm. Basic idea of the algorithm is if we cancel out each
occurrence of an element e with all the other elements that are different from e then e will exist till end if it is a majority element.

Time Complexity: O(n)
Auxiliary Space : O(1)

*/