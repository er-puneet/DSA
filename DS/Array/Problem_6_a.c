#include <stdio.h>

int pivotSearch(int arr[], int low, int high)
{
	if (high < low)
		return -1;
	
	if(high == low)
		return low;
	
	int mid = (low + high)/2;
	if(low < mid && arr[mid] < arr[mid-1])
		return mid-1;
	
	if(high > mid && arr[mid] > arr[mid+1])
		return mid;
	
	if (arr[low] >= arr[mid])
		return pivotSearch(arr, low, mid-1);
		
	return pivotSearch(arr, mid+1, high);
}

int binarySearch(int arr[], int low, int high, int key)
{
	if (high < low)
		return -1;
	int mid = (low + high)/2; /*low + (high - low)/2;*/
	if (key == arr[mid])
		return mid;
	if (key > arr[mid])
		return binarySearch(arr, (mid + 1), high, key);
	
	return binarySearch(arr, low, (mid -1), key);
}

int pivotedBinarySearch(int arr[], int size, int key)
{
	int pivot = pivotSearch(arr, 0, size-1);
	printf("Pivot element : %d\n", pivot);
	if (arr[pivot] == key)
		return pivot;
	if (arr[0] < key)
		return binarySearch(arr, 0, pivot-1, key);
		
	return binarySearch(arr, pivot+1, size-1, key);
}

int main()
{
	// Let us search 3 in below array
	int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	int key = 1;
	printf("Element %d at Index: %d\n",key, pivotedBinarySearch(arr, n, key));
	return 0;
}

/*
Search an element in a sorted and rotated array
An element in a sorted array can be found in O(log n) time via binary search. But suppose we rotate an ascending order sorted array at some pivot
unknown to you beforehand. So for instance, 1 2 3 4 5 might become 3 4 5 1 2. Devise a way to find an element in the rotated array in O(log n)
time.

The idea is to find the pivot point, divide the array in two sub-arrays and call binary search.
The main idea for finding pivot is for a sorted (in increasing order) and pivoted array, pivot element is the only only element for which next element
to it is smaller than it.
Using above criteria and binary search methodology we can get pivot element in O(logn) time

Output: 
puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Pivot element : 5
Element 1 at Index: 6

Time Complexity: O(log n)

*/