#include <stdio.h>

/* Method that reverses an array by recursive calls*/
void reverseArray(int arr[], int start, int end)
{
	if(start<end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++; end--;
		return reverseArray(arr, start, end);
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

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {2, 8, 21, 43, 3, 13, -21, 15, 20};
	int m = sizeof(arr)/sizeof(arr[0]);
	
	printf("Array : ");
	printArray(arr, m);
	
	reverseArray(arr, 0, m-1);
	
	printf("Reverse Array : ");
	printArray(arr, m);
	
}


/*Write a program to reverse an array or string

Output:
puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 2 8 21 43 3 13 -21 15 20 
Reverse Array : 20 15 -21 13 3 43 21 8 2 

Time Complexity: O(n)

*/