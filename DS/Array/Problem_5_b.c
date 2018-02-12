#include <stdio.h>

int getMissingNo(int arr[], int size)
{
	int X1 = 0, X2 = 0;
	
	int i=0;
	for (i=0; i<size; i++)
	{
		X1 ^= arr[i];
		X2 ^= i+1;
	}
	
	X2 ^= i+1;
	
	return X1^X2;
}

void printMissingNo(int arr[], int size)
{
	int missingNumber = getMissingNo(arr, size);
	
	printf("Missing Number in array : %d\n", missingNumber);
	
}

int main()
{
	int arr[] = {1, 2, 4, 6, 3, 7, 8, 5, 10};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	printMissingNo(arr, arr_size);
}

/*
Find the Missing Number
You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in list. One of the integers is missing in the
list. Write an efficient code to find the missing integer.
Example:
	I/P
		[1, 2, 4, ,6, 3, 7, 8]
	O/P
		5
METHOD 1(Use sum formula)
	Algorithm:
	1. Get the sum of numbers
		total = n*(n+1)/2
	2 Subtract all the numbers from sum and
		you will get the missing number.

METHOD 2(Use XOR)
	1) XOR all the array elements, let the result of XOR be X1.
	2) XOR all numbers from 1 to n, let XOR be X2.
	3) XOR of X1 and X2 gives the missing number.

Output: 

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Missing Number in array : 9

Time Complexity: O(n)
In method 1, if the sum of the numbers goes beyond maximum allowed integer, then there can be integer overflow and we may not get correct
answer. Method 2 has no such problems.

*/