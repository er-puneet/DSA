//C program to find k largest elements in an array

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



/*Function to find k largest elements in an array*/
void findKlargest(int arr[], int size, int k)
{
	int temp;
	for(int i = 0; i < k; i++)
	{
		for(int j = k; j < size; j++)
		{
			if(arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {0, 1, 2, 90, 10, 110, 12, 15, 80};
	int m = sizeof(arr)/sizeof(arr[0]);
	int k = 4;
	
	printArray(arr, m);
	
	//printf("Finding %d largest element in array....\n", k);
	findKlargest(arr, m, k);
	
	printf("%d largest element in array....\n", k);
	printArray(arr, k);
	
	return 0;
}


/*
k largest(or smallest) elements in an array | added Min Heap method

Write an efficient program for printing k largest elements in an array. Elements in array can be in any order.

For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the largest 3 elements i.e., k = 3 then your program should print 50,
30 and 23.

Method 1 (Use Bubble k times)

	1) Modify Bubble Sort to run the outer loop at most k times.
	2) Print the last k elements of the array obtained in step 1.

Time Complexity: O(nk)
Like Bubble sort, other sorting algorithms like Selection Sort can also be modified to get the k largest elements.

Method 2 (Use temporary array)
	K largest elements from arr[0..n-1]
	1) Store the first k elements in a temporary array temp[0..k-1].
	2) Find the smallest element in temp[], let the smallest element be min.
	3) For each element x in arr[k] to arr[n-1]
	If x is greater than the min then remove min from temp[] and insert x.
	4) Print final k elements of temp[]

Time Complexity: O((n-k)*k). If we want the output sorted then O((n-k)*k + klogk)


Method 3(Use Sorting)
	1) Sort the elements in descending order in O(nLogn)
	2) Print the first k numbers of the sorted array O(k).

Time complexity: O(nlogn)

Output:

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 0 1 2 90 10 110 12 15 80 
4 largest element in array....
Array : 110 80 15 90 

*/