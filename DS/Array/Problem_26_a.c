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

/* Function to print product array for a given array arr[] of size n */
void productArray(int arr[], int n)
{
	/* Allocate memory for temporary arrays left[] and right[] */
	int *left = (int *)malloc(sizeof(int)*n);
	int *right = (int *)malloc(sizeof(int)*n);

	/* Allocate memory for the product array */
	int *prod = (int *)malloc(sizeof(int)*n);
	
	int i, j;
	
	/* Left most element of left array is always 1 */
	left[0] = 1;
	
	/* Rightmost most element of right array is always 1 */
	right[n-1] = 1;
	
	/* Construct the left array */
	for(i=1; i<n; i++)
		left[i] = left[i-1]*arr[i-1];
	
	/* Construct the right array */
	for(j=n-2; j>=0; j--)
		right[j] = right[j+1]*arr[j+1];
	
	/* Construct the prod array usinf left and right array*/
	for(i=0; i<n; i++)
		prod[i] = left[i]*right[i];
	
	/* Print product Array */
	printf("Product ");
	printArray(prod, n);
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {10, 3, 5, 6, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	/* Print original Array */
	printf("Original ");
	printArray(arr, n);
	
	/* Created product array */
	productArray(arr, n);
	
	return 0;
}


/*
A Product Array Puzzle
Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal to the product of all the elements of
arr[] except arr[i]. Solve it without division operator and in O(n).

Example:
	arr[] = {10, 3, 5, 6, 2}
	prod[] = {180, 600, 360, 300, 900}

Algorithm:
	1) Construct a temporary array left[] such that left[i] contains product of all elements on left of arr[i] excluding arr[i].
	2) Construct another temporary array right[] such that right[i] contains product of all elements on on right of arr[i] excluding arr[i].
	3) To get prod[], multiply left[] and right[].

Time Complexity: O(n)
Space Complexity: O(n)
Auxiliary Space: O(n)

Output: 

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Original Array : 10 3 5 6 2 
Product Array : 180 600 360 300 900 

*/