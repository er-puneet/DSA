#include <stdio.h>
#include<stdlib.h>

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
	printf("Array : ");
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/* Function to print two indexes in unsorted array which makes the given array, sorted*/
void printUnsorted(int arr[], int size)
{
	int i , s, e;
	int min, max;
	
	for(i=0; i<size-1; i++)
	{
		if(arr[i+1] < arr[i])
		{
			s = i;
			break;
		}
	}
	
	if(s == size-1)
	{
		printf("Complete array is sorted");
		return;
	}

	for(i=size-1; i>=0; i--)
	{
		if(arr[i-1] > arr[i])
		{
			e = i;
			break;
		}
	}
	
	min = arr[s];
	max = arr[s];
	
	for(i=s+1; i<=e; i++)
	{
		if(arr[i] < min)
			min = arr[i];
		
		if(arr[i] > max)
			max = arr[i];
	}
	
	for(i=s-1; i>0; i--)
	{
		if(arr[i] > min)
			s=i;
		else
			break;
	}
	
	for(i=e+1; i>size; i++)
	{
		if(arr[i] < max)
			e=i;
		else
			break;
	}
	
	// step 3 of above algo
	printf("The unsorted subarray which makes the given array sorted lies between the indees %d and %d\n", s, e);
	return;
}
/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {0, 1, 4, 2, 7, 5, 2, 3, 1, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	/* Print Array */
	printArray(arr, n);
	
	printUnsorted(arr, n);
	
	return 0;
}


/*
Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] such that sorting this subarray makes the whole array
sorted.

Examples:
	1) If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], your program should be able to find that the subarray lies between the indexes 3 and 8.

Solution:
	1) Find the candidate unsorted subarray
		a) Scan from left to right and find the first element which is greater than the next element. Let s be the index of such an element. 
		In the above example 1, s is 3 (index of 30).
		b) Scan from right to left and find the first element (first in right to left order) which is smaller than the next element (next in right to left order). 
		Let e be the index of such an element. In the above example 1, e is 7 (index of 31).
	2) Check whether sorting the candidate unsorted subarray makes the complete array sorted or not. 
	If not, then include more elements in the subarray.
		a) Find the minimum and maximum values in arr[s..e]. Let minimum and maximum values be min and max. min and max for [30, 25, 40, 32, 31] are 25 and 40 respectively.
		b) Find the first element (if there is any) in arr[0..s-1] which is greater than min, change s to index of this element. 
		There is no such element in above example 1.
		c) Find the last element (if there is any) in arr[e+1..n-1] which is smaller than max, change e to index of this element. 
		In the above example 1, e is changed to 8 (index of 35)
	3) Print s and e

Time Complexity: O(n)

Output:

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 0 1 4 2 7 5 2 3 1 6 7 
The unsorted subarray which makes the given array sorted lies between the indees 2 and 8

*/