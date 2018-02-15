#include <stdio.h>

/* Utility that reverses an array */
void reverseArray(int arr[], int start, int end)
{
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int rotateArray(int arr[], int size, int d)
{
	reverseArray(arr, 0, d-1);
	reverseArray(arr, d, size-1);
	reverseArray(arr, 0, size-1);
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	//{2, 8, 21, 43, 3, 13, -21, 15, 20};
	int m = sizeof(arr)/sizeof(arr[0]);
	int d = 5;
	
	printf("Array : ");
	printArray(arr, m);
	
	rotateArray(arr, m, d);
	
	printf("Rotated Array : ");
	printArray(arr, m);
	
}


/*
Program for array rotation
Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.

*******METHOD 1 (Use temp array)*******

*******METHOD 2 (Rotate one by one)*******

*******METHOD 3 (A Juggling Algorithm)*******

*******Method 4(The Reversal Algorithm)*******

Algorithm:

Let AB are the two parts of the input array where A = arr[0..d-1] and B = arr[d..n-1]. The idea of the algorithm is:
Reverse A to get ArB.  Ar is reverse of A 
Reverse B to get ArBr. Br is reverse of B 
Reverse all to get (ArBr) r = BA.

Outout:
puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 1 2 3 4 5 6 7 8 9 10 11 12 
Rotated Array : 6 7 8 9 10 11 12 1 2 3 4 5 

*/