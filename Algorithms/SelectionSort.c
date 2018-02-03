#include <stdio.h>

void selectionSort(int *Arr, int size)
{
	//Print Array to be sorted
	printf("Sorting array\n");
	for (int i=0; i<size; i++)
		printf("%d ", Arr[i]);
	printf("\n");
	
	int key, smallest, count = 0;
	
	for (int i=0; i<size-1; i++)
	{
		key = Arr[i];
		smallest = i;
		for(int j=i+1; j<size; j++)					//Find smallest element in array [i+1 to size]
		{
			count ++;
			if(Arr[j] < Arr[smallest])
				smallest = j;
		}
		
		Arr[i] = Arr[smallest];						//Swap element i with smallest in array [i to size]
		Arr[smallest] = key;
		
		printf("Sorted array pass %d\n", i);		//Print Array after one sort pass completed
		for (int i=0; i<size; i++)
			printf("%d ", Arr[i]);
		printf("\n");
	}
	
	printf("Sorted array\n");
	for (int i=0; i<size; i++)
		printf("%d ", Arr[i]);
	printf("\n");
}


int main()
{
	int Arr[] = {64, 25, 12, 22, 11};
	
	int size = sizeof(Arr) / sizeof(Arr[0]);
	
	selectionSort(Arr, size);
	
	return 0;
}



/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting
it at the beginning. The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the
sorted subarray.

Time Complexity: O(n*n) as there are two nested loops. [n*(n+1)/2]

Auxiliary Space: O(1)

The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.

Output: 

puneet@jp:~/Workspace/DSA/Algorithms$ ./a.out 
Sorting array
64 25 12 22 11 
Sorted array pass 0
11 25 12 22 64 
Sorted array pass 1
11 12 25 22 64 
Sorted array pass 2
11 12 22 25 64 
Sorted array pass 3
11 12 22 25 64 
Sorted array
11 12 22 25 64 

*/