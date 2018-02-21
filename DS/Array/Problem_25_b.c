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

int ceilSearch(int arr[], int low, int high, int x)
{
	
	if(arr[low] >= x)
		return low;
	
	if(arr[high] < x)
		return -1;
	
	int mid = (high + low)/2;
	
	if(arr[mid] == x)
		return mid;
	
	else if(arr[mid] < x)
	{
		if(mid+1 < high && arr[mid+1] > x)
			return mid+1;
		else
			return ceilSearch(arr, mid+1, high, x);
	}
	else
	{
		if(mid-1 > low && arr[mid-1] < x)
			return mid;
		else
			return ceilSearch(arr, low, mid-1, x);
	}
}

int floorSearch(int arr[], int low, int high, int x)
{
	
	if(arr[low] > x)
		return -1;
	
	if(arr[high] <= x)
		return high;
	
	int mid = (high + low)/2;
	
	if(arr[mid] == x)
		return mid;
	
	else if(arr[mid] < x)
	{
		if(mid+1 <= high && arr[mid+1] > x)
			return mid;
		else
			return floorSearch(arr, mid+1, high, x);
	}
	else
	{
		if(mid-1 > low && arr[mid-1] < x)
			return mid-1;
		else
			return floorSearch(arr, low, mid-1, x);
	}
}


/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {1, 2, 8, 10, 10, 12, 17, 19, 20};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 3;
	
	printArray(arr, n);

	int index = ceilSearch(arr, 0, n-1, x);
	
	if(index == -1)
		printf("Ceiling of %d doesn't exist in array\n", x);
	else
		printf("Ceiling of %d is %d\n", x, arr[index]);
	
	index = floorSearch(arr, 0, n-1, x);
	if(index == -1)
		printf("Floor of %d doesn't exist in array\n", x);
	else
		printf("Floor of %d is %d\n", x, arr[index]);
	
	return 0;
}


/*
Floor and Ceiling in a sorted array

Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x, and the floor is the greatest element
smaller than or equal to x. Assume than the array is sorted in non-decreasing order. Write efficient functions to find floor and ceiling of x.

Method 1 (Linear Search)
	Algorithm to search ceiling of x:
	1) If x is smaller than or equal to the first element in array then return 0(index of first element)
	2) Else Linearly search for an index i such that x lies between arr[i] and arr[i+1].
	3) If we do not find an index i in step 2, then return -1

Time Complexity: O(n)

Method 2 (Binary Search)
Instead of using linear search, binary search is used here to find out the index. Binary search reduces time complexity to O(Logn).

Time Complexity: O(Logn)

Output:

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 1 2 8 10 10 12 17 19 20 
Ceiling of 3 is 8
Floor of 3 is 2

*/