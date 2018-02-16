#include <stdio.h>
#include<limits.h>

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


void print2Smallest(int arr[], int size)
{
	// Variables to keep 2 min elements in array
	int smallest = INT_MAX, second_smallest = INT_MAX;
	
	/* Array should have at least two elements*/
	if(size < 2)
	{
		printf("Invalid Input");
		return;
	}
	
	for (int i = 0; i<size-1; i++)
	{
		if (arr[i] < smallest)
		{
			second_smallest = smallest;
			smallest = arr[i];
		}
	}
	printf("\nThe two smallest elements are %d and %d\n", smallest, second_smallest);
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {1, 60, 10, 70, -80, 85, -80};
	
	int m = sizeof(arr)/sizeof(arr[0]);
	
	printf("Array : ");
	printArray(arr, m);
	
	print2Smallest(arr, m);
}


/*
Find the smallest and second smallest element in an array
Write an efficient C program to find smallest and second smallest element in an array.
Example:
	Input: arr[] = {12, 13, 1, 10, 34, 1}
	Output: The smallest element is 1 and
	second Smallest element is 10

A Simple Solution is to sort the array in increasing order. The first two elements in sorted array would be two smallest elements. Time complexity
of this solution is O(n Log n).

A Better Solution is to scan the array twice. In first traversal find the minimum element. Let this element be x. In second traversal, find the
smallest element greater than x. Time complexity of this solution is O(n).
The above solution requires two traversals of input array.

An Efficient Solution can find the minimum two elements in one traversal. Below is complete algorithm.
	Algorithm:
		1) Initialize both first and second smallest as INT_MAX
			first = second = INT_MAX
		2) Loop through all the elements.
			a) If the current element is smaller than first , then update first and second .
			b) Else if the current element is smaller than second then update second

The same approach can be used to find the largest and second largest elements in an array.
Time Complexity: O(n)

Output:
puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 1 60 10 70 -80 85 -80 

The two smallest elements are -80 and 1

*/