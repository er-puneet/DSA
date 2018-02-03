#include <stdio.h>

void findPairs(int A[], int size, int sum)
{
	int i = 0, j = size-1;
	
	while(i<j)
	{
		if (A[i]+A[j] == sum)
		{
			printf("\nElements %d and %d sum is %d\n", A[i], A[j], sum);
			break;
		}
		else if (A[i]+A[j] < sum)
			i++;
		else
			j--;
	}
}

int main()
{
	int A[] = {1, 4, 45, 6, 10, 8};
	int sum = 16;
	int arr_size = sizeof(A)/sizeof(A[0]);
	selectionSort(A, arr_size);		//Fucction available in ../../Algorithms/SelectionSort.c
	findPairs(A, arr_size, sum);
}

/*

Given an array A[] and a number x, check for pair in A[] with sum as x

Write a C program that, given an array A[] of n numbers and another number x, determines whether or not there exist two elements in S whose
sum is exactly x.

Compile : gcc - Wall ../../Algorithms/SelectionSort.c Problem_1_a.c		(main removed from SelectionSort.c)

Output: 

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Sorting array
1 4 45 6 10 8 
Sorted array pass 0
1 4 45 6 10 8 
Sorted array pass 1
1 4 45 6 10 8 
Sorted array pass 2
1 4 6 45 10 8 
Sorted array pass 3
1 4 6 8 10 45 
Sorted array pass 4
1 4 6 8 10 45 
Sorted array
1 4 6 8 10 45 

Elements 6 and 10 sum is 16

Time Complexity: Depends on what sorting algorithm we use. 

Auxiliary Space : Again, depends on sorting algorithm.

Note: If there are more than one pair having the given sum then this algorithm reports only one. 

*/