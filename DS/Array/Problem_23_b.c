#include <stdio.h>

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
	printf("Array : ");
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}



/*Maximum difference between two elements in an array*/
int maxDiff(int arr[], int size)
{
	int max_diff = arr[1] - arr[0];
	int min_ele = arr[0];
	
	for(int i = 1; i < size; i++)
	{
		if(max_diff < arr[i] - min_ele)
			max_diff = arr[i] - min_ele;
		if(arr[i] < min_ele)
			min_ele = arr[i];
	}
	return max_diff;
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {10, 11, 2, 9, 1, 11, 12, 5, 8};
	int m = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, m);
	
	int max_diff = maxDiff(arr, m);
	
	printf("Maximum difference between two elements in array is %d\n", max_diff);
	
	return 0;
}


/*
Maximum difference between two elements such that larger element appears after the smaller number
Given an array arr[] of integers, find out the difference between any two elements such that larger element appears after the smaller number in arr[].

Examples: If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 8 (Diff between 10 and 2). If array is [ 7, 9, 5, 6, 3, 2 ] then returned 
value should be 2 (Diff between 7 and 9)

Method 1 (Simple)
Use two loops. In the outer loop, pick elements one by one and in the inner loop calculate the difference of the picked element with every other
element in the array and compare the difference with the maximum difference calculated so far.

Time Complexity: O(n^2)
Auxiliary Space: O(1)

Method 2 (Tricky and Efficient)
In this method, instead of taking difference of the picked element with every other element, we take the difference with the minimum element found
so far. 
	So we need to keep track of 2 things:
	1) Maximum difference found so far (max_diff).
	2) Minimum number visited so far (min_element).

Time Complexity: O(n)
Auxiliary Space: O(1)

Output:

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 10 11 2 9 1 11 12 5 8 
Maximum difference between two elements in array is 11

*/