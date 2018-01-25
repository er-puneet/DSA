#include <stdio.h>

void swap(int *val1, int *val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}


void bubbleSort(int *Arr, int size)
{
	//Print Array to be sorted
	printf("Sorting array\n");
	for (int i=0; i<size; i++)
		printf("%d ", Arr[i]);
	printf("\n");
	
	int swapped;
	
	for (int i=0; i<size-1; i++)
	{
		swapped = 0;
		for(int j=0; j<size-i-1; j++)					//Last I elements are already sorted
		{
			if(Arr[j] > Arr[j+1])						//Compare all elements in Array[0 to size-i-1]
			{
				swap(&Arr[j], &Arr[j+1]);
				swapped = 1;
			}
		}
		
		printf("Sorted array pass %d\n", i);		//Print Array after one sort pass completed
		for (int i=0; i<size; i++)
			printf("%d ", Arr[i]);
		printf("\n");
		
		if (!swapped)								//If no swap required in pass, all elements are sorted now
			break;
	}
	
	printf("Sorted array\n");
	for (int i=0; i<size; i++)
		printf("%d ", Arr[i]);
	printf("\n");
}


int main()
{
	int Arr[] = {64, 34, 25, 12, 22, 11, 90};
	
	int size = sizeof(Arr) / sizeof(Arr[0]);
	
	bubbleSort(Arr, size);
	
	return 0;
}



/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
Auxiliary Space: O(1)
Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm.
In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it
with just linear complexity (2n).

Output: 

puneet@jp:~/Workspace/DSA/Algorithms$ ./a.out 
Sorting array
64 34 25 12 22 11 90 
Sorted array pass 0
34 25 12 22 11 64 90 
Sorted array pass 1
25 12 22 11 34 64 90 
Sorted array pass 2
12 22 11 25 34 64 90 
Sorted array pass 3
12 11 22 25 34 64 90 
Sorted array pass 4
11 12 22 25 34 64 90 
Sorted array pass 5
11 12 22 25 34 64 90 
Sorted array
11 12 22 25 34 64 90 

*/