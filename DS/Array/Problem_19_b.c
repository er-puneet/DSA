#include <stdio.h>
#include<limits.h>

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
	printf("Array : ");
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/*Method to find first occurance of element in arr[]*/
int binSearch(int arr[], int left, int right, int element)
{
	
	if(left > right)
		return -1;
	
	int mid = (right + left)/2;
	
	if ((mid == 0 || element > arr[mid-1]) && (arr[mid] == element))
		return mid;
	
	if (element <= arr[mid])
		return binSearch(arr, left, mid-1, element);
	else
		return binSearch(arr, mid+1, right, element);
}

int isMajority(int arr[], int size, int element)
{
	int ele_index = binSearch(arr, 0, size-1, element);
	
	if(ele_index == -1)
	{
		printf("Element %d not found in array\n", element);
		return 0;
	}
	printf("First occurance of %d found in array at %d\n", element, ele_index);
	
	if(ele_index + (size/2) < size &&  arr[ele_index + (size/2)] == element)
		return 1;
	
	return 0;
	
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {1, 2, 3, 3, 3, 3, 10};
	int m = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, m);
	
	int x = 3;
	
	if (isMajority(arr, m, x))
		printf("%d appears more than %d times in arr[]\n", x, m/2);
	else
		printf("%d does not appear more than %d times in arr[]\n",x, m/2);
	
	return 0;
}


/*
Check for Majority Element in a sorted array
Question: Write a C function to find if a given integer x appears more than n/2 times in a sorted array of n integers.

Basically, we need to write a function say isMajority() that takes an array (arr[] ), arrays size (n) and a number to be searched (x) as parameters
and returns true if x is a majority element (present more than n/2 times).

METHOD 1 (Using Linear Search)
Linearly search for the first occurrence of the element, once you find it (let at index i), check element at index i + n/2. If element is present at i+n/2
then return 1 else return 0.

Time Complexity: O(n)

METHOD 2 (Using Binary Search)
Use binary search methodology to find the first occurrence of the given number. The criteria for binary search is important here.

Time Complexity: O(Logn)
Algorithmic Paradigm: Divide and Conquer

Output:

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 1 2 3 3 3 3 10 
First occurance of 3 found in array at 2
3 appears more than 3 times in arr[]



*/