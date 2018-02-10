#include <stdio.h>

int getOddOccurrence(int arr[], int size)
{
	int res = 0;
	for (int i=0; i<size; i++)
	{
		res = res ^ arr[i];
	}
	return res;
}

int isOddExist(int arr[], int size, int candidate)
{
	for (int i=0; i<size; i++)
	{
		if(arr[i] == candidate)
			return 1;
	}
	
	return 0;
}

void printOdd(int arr[], int size)
{
	int candidate = getOddOccurrence(arr, size);
	
	printf("Element with odd occurences candidate: %d\n", candidate);
	
	if (isOddExist(arr, size, candidate))
		printf("Only element with odd occurences : %d\n", candidate);
	else
		printf("Only element with odd occurences not found\n");
}

int main()
{
	int arr[] = {1, 1, 2, 2, 3, 3, 3, 11, 8, 8, 10, 2, 2, 2, 2 ,10, 11};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	printOdd(arr, arr_size);
}

/*
Find the Number Occurring Odd Number of Times
Given an array of positive integers. All numbers occur even number of times except one number which occurs odd number of times. Find the
number in O(n) time & constant space.
Example:
	I/P = [1, 2, 3, 2, 3, 1, 3]
	O/P = 3

A Simple Solution is to run two nested loops. The outer loop picks all elements one by one and inner loop counts number of occurrences of the
element picked by outer loop. Time complexity of this solution is O(n 2 ).

A Better Solution is to use Hashing. Use array elements as key and their counts as value. Create an empty hash table. One by one traverse the
given array elements and store counts. Time complexity of this solution is O(n). But it requires extra space for hashing.

The Best Solution is to do bitwise XOR of all the elements. XOR of all elements gives us odd occurring element. Please note that XOR of two
elements is 0 if both elements are same and XOR of a number x with 0 is x.

Output: 

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Element with odd occurences candidate: 3
Only element with odd occurences : 3

Time Complexity: O(n)
*/