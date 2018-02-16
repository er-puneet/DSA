#include <stdio.h>
#include<limits.h>	

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


void minAbsSumPair(int arr[], int n)
{
	// Variables to keep track of current sum and minimum sum
	int sum, min_sum = INT_MAX;
	
	// left and right index variables
	int l = 0, r = n-1;
	
	// variable to keep track of the left and right pair for min_sum
	int min_l = l, min_r = r;
	
	/* Array should have at least two elements*/
	if(n < 2)
	{
		printf("Invalid Input");
		return;
	}
	
	selectionSort(arr, n);
	
	while(l<r)
	{
		sum = arr[l] + arr[r];
		
		/*If abs(sum) is less then update the result items*/
		if(abs(sum) < abs(min_sum))
		{
			min_sum = sum;
			min_l = l;
			min_r = r;
		}
		
		if(sum < 0)
			l++;
		else
			r--;	
	}
	printf("\nThe two elements whose sum is minimum are %d and %d\n", arr[min_l], arr[min_r]);
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {1, 60, -10, 70, -80, 85};
	
	int m = sizeof(arr)/sizeof(arr[0]);
	
	printf("Array : ");
	printArray(arr, m);
	
	minAbsSumPair(arr, m);
}


/*
Two elements whose sum is closest to zero
Question: An Array of integers is given, both +ve and -ve. You need to find the two elements such that their sum is closest to zero.

For the below array, program should print -80 and 85.
	{1, 60, -10, 70, -80, 85}
	
METHOD 1 (Simple)
	For each element, find the sum of it with every other element in the array and compare sums. Finally, return the minimum sum.
Time complexity: O(n^2)

METHOD 2 (Use Sorting)

Algorithm
	1) Sort all the elements of the input array.
	2) Use two index variables l and r to traverse from left and right ends respectively. Initialize l as 0 and r as n-1.
	3) sum = a[l] + a[r]
	4) If sum is -ve, then l++
	5) If sum is +ve, then r
	6) Keep track of abs min sum.
	7) Repeat steps 3, 4, 5 and 6 while l < r Implementation

Time Complexity: complexity to sort + complexity of finding the optimum pair = O(n*n) + O(n) = O(n*n)

Compile : gcc -Wall ../../Algorithms/SelectionSort.c Problem_17_b.c		(main removed from SelectionSort.c)

Output:

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 1 60 -10 70 -80 85 
Sorting array
1 60 -10 70 -80 85 
Sorted array pass 0
-80 60 -10 70 1 85 
Sorted array pass 1
-80 -10 60 70 1 85 
Sorted array pass 2
-80 -10 1 70 60 85 
Sorted array pass 3
-80 -10 1 60 70 85 
Sorted array pass 4
-80 -10 1 60 70 85 
Sorted array
-80 -10 1 60 70 85 

The two elements whose sum is minimum are -80 and 85

*/