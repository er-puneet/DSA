#include <stdio.h>
#define MAX 1000

void findPairs(int A[], int arr_size, int sum)
{
	int binMap[MAX] = {0};		//Initialize hash map as 0
	int temp;
	
	for (int i=0; i<arr_size; i++)
	{
		temp = sum - A[i];
		if(temp>=0 && binMap[temp] ==1)
			printf("Pair with gven sum(%d) is %d and %d\n", sum, A[i], temp);
		binMap[A[i]] = 1;
	}
}


int main()
{
	int A[] = {1, 4, 45, 6, 10, 8, 8};
	int sum = 16;
	int arr_size = sizeof(A)/sizeof(A[0]);

	findPairs(A, arr_size, sum);
}

/*

Given an array A[] and a number x, check for pair in A[] with sum as x

Write a C program that, given an array A[] of n numbers and another number x, determines whether or not there exist two elements in S whose
sum is exactly x.

Output:

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Pair with gven sum(16) is 10 and 6
Pair with gven sum(16) is 8 and 8

This method works in O(n) time if range of numbers is known.
Auxiliary Space: O(R) where R is range of integers.

*/