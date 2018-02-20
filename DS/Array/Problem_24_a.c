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

void printUnion(int arr1[], int size1, int arr2[], int size2)
{
	printf("Union of two arrays\n");
	int i = 0, j = 0;
	
	while(i<size1 && j<size2)
	{
		if(arr1[i] < arr2[j])
			printf("%d ", arr1[i++]);
		else if(arr1[i] > arr2[j])
			printf("%d ", arr2[j++]);
		else
		{
			printf("%d ", arr2[j]);
			i++; j++;
		}
	}
	
	while(i < size1)
		printf("%d ", arr1[i++]);
	while(j < size2)
		printf("%d ", arr2[j++]);
	
	printf("\n");
}

void printIntersection(int arr1[], int size1, int arr2[], int size2)
{
	printf("Intersection of two arrays\n");
		
	int i = 0, j = 0;
	
	while(i<size1 && j<size2)
	{
		if(arr1[i] < arr2[j])
			i++;
		else if(arr1[i] > arr2[j])
			j++;
		else
		{
			printf("%d ", arr2[j]);
			i++; j++;
		}
	}
	
	printf("\n");
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr1[] = {1, 2, 4, 5, 6};
	int arr2[] = {2, 3, 5, 7};
	int m = sizeof(arr1)/sizeof(arr1[0]);
	int n = sizeof(arr2)/sizeof(arr2[0]);
	
	printf("Arr1 ");
	printArray(arr1, m);
	
	printf("Arr2 ");
	printArray(arr2, n);
	
	printUnion(arr1, m, arr2, n);
	
	printIntersection(arr1, m, arr2, n);
	
	return 0;
}


/*
Union and Intersection of two sorted arrays
Given two sorted arrays, find their union and intersection.
	For example, if the input arrays are:
	arr1[] = {1, 3, 4, 5, 7}
	arr2[] = {2, 3, 5, 6}
	Then your program should print Union as {1, 2, 3, 4, 5, 6, 7} and Intersection as {3, 5}.

Algorithm Union(arr1[], arr2[]):
	For union of two arrays, follow the following merge procedure.
	1) Use two index variables i and j, initial values i = 0, j = 0
	2) If arr1[i] is smaller than arr2[j] then print arr1[i] and increment i.
	3) If arr1[i] is greater than arr2[j] then print arr2[j] and increment j.
	4) If both are same then print any of them and increment both i and j.
	5) Print remaining elements of the larger array.

Time Complexity: O(m+n)

Algorithm Intersection(arr1[], arr2[]):
	For Intersection of two arrays, print the element only if the element is present in both arrays.
	1) Use two index variables i and j, initial values i = 0, j = 0
	2) If arr1[i] is smaller than arr2[j] then increment i.
	3) If arr1[i] is greater than arr2[j] then increment j.
	4) If both are same then print any of them and increment both i and j.

Time Complexity: O(m+n)

Output:

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Arr1 Array : 1 2 4 5 6 
Arr2 Array : 2 3 5 7 
Union of two arrays
1 2 3 4 5 6 7 
Intersection of two arrays
2 5 

*/