//C program to sort a binary array in one pass

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



/*Function to put all 0s on left and all 1s on right*/
void segregate0and1(int arr[], int low, int high)
{
	while(low < high)
	{
		while(arr[low] == 0 && low < high)
			low++;
		while(arr[high] == 1 && low < high)
			high--;
		
		if(low < high)
		{
			arr[low] = 0;
			arr[high] = 1;
			low++; high--;
		}
	}
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {0, 1, 0, 1, 1, 1, 0, 1, 0, 0};
	int m = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, m);
	
	printf("segregating 0 and 1\n");
	segregate0and1(arr, 0, m-1);
	
	printArray(arr, m);
	
	return 0;
}


/*
Segregate 0s and 1s in an array

You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. Traverse array only once.

Input array = [0, 1, 0, 1, 0, 0, 1, 1, 1, 0]
Output array = [0, 0, 0, 0, 0, 1, 1, 1, 1, 1]
Method 1 (Count 0s or 1s)
	1) Count the number of 0s. Let count be C.
	2) Once we have count, we can put C 0s at the beginning and 1s at the remaining n C positions in array.

Time Complexity: O(n)
The method 1 traverses the array two times. Method 2 does the same in a single pass.

Method 2 (Use two indexes to traverse)
	Maintain two indexes. Initialize first index left as 0 and second index right as n-1.
	Do following while left < right
	a) Keep incrementing index left while there are 0s at it
	b) Keep decrementing index right while there are 1s at it
	c) If left < right then exchange arr[left]=0 and arr[right]=1 Implementation:

Time Complexity: O(n)

Output:

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 0 1 0 1 1 1 0 1 0 0 
segregating 0 and 1
Array : 0 0 0 0 0 1 1 1 1 1 

*/