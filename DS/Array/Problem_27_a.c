#include <stdio.h>
#include<stdlib.h>

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
	printf("Array : ");
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/* Function to print segregate Odd and Even in array for a given array arr[] */
void segregateEvenOdd(int arr[], int n)
{
	
	int left = 0, right = n-1;	/* Initialize left and right indexes */
	
	while(left<=right)
	{
		while(arr[left]%2 == 0)		/* Increment left index while we see Even number at left */
			left++;
		
		while(arr[right]%2 != 0)	/* Deccrement right index while we see odd number at right */
			right--;
		
		if(left<right)				/* Swap arr[left] and arr[right]*/
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++; right--;
		}
	}
	
	
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {12, 34, 45, 9, 8, 90, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	/* Print original Array */
	printf("Original ");
	printArray(arr, n);
	
	/* Segregate Even and Odd in original array */
	segregateEvenOdd(arr, n);
	
	printf("Segregated ");
	printArray(arr, n);
	
	return 0;
}


/*
Segregate Even and Odd numbers
Given an array A[], write a function that segregates even and odd numbers. The functions should put all even numbers first, and then odd numbers.
	Example
	Input = {12, 34, 45, 9, 8, 90, 3}
	Output = {12, 34, 8, 90, 45, 9, 3}

Algorithm: segregateEvenOdd()
	1) Initialize two index variables left and right:
		left = 0, right = size -1
	2) Keep incrementing left index until we see an odd number.
	3) Keep decrementing right index until we see an even number.
	4) If lef < right then swap arr[left] and arr[right]

Time Complexity: O(n)

Output:

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Original Array : 12 34 45 9 8 90 3 
Segregated Array : 12 34 90 8 9 45 3 

*/