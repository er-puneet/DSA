#include <stdio.h>

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


void printLeaders(int arr[], int size)
{
	int max_from_right = arr[size-1];
	
	printf("Leaders : \n");
	
	printf("%d ", max_from_right);
	
	for(int i=size-2; i>=0; i--)
	{
		if(max_from_right < arr[i])
		{
			max_from_right = arr[i];
			printf("%d ", max_from_right);
		}
	}
	printf("\n");
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {16, 17, 4, 3, 5, 2};;
	
	int m = sizeof(arr)/sizeof(arr[0]);
	
	printf("Array : ");
	printArray(arr, m);
	
	printLeaders(arr, m);
}


/*
Leaders in an array
Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. And the rightmost
element is always a leader. For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.

Method 1 (Simple)
	Use two loops. The outer loop runs from 0 to size 1 and one by one picks all elements from left to right. The inner loop compares the picked
	element to all the elements to its right side. If the picked element is greater than all the elements to its right side, then the picked element is the
	leader.
Time Complexity: O(n*n)

Method 2 (Scan from right)
	Scan all the elements from right to left in array and keep track of maximum till now. When maximum changes its value, print it.
Time Complexity: O(n)

Outout:
	puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
	Array : 16 17 4 3 5 2 
	Leaders : 
	2 5 17 

*/