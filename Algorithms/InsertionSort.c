# include <stdio.h>

void insertionSort(int *Arr, int size)
{
	//Print Array to be sorted
	printf("Sorting array\n");
	for (int i=0; i<size; i++)
		printf("%d ", Arr[i]);
	printf("\n");
	
	//sort Array
	int key, j;
	int count = 0;		//Variable to count number of swap operation performed. 
	for (int i=1; i<size; i++)
	{
		key = Arr[i];
		j=i-1;
		
		while(j>=0 && Arr[j]>key)
		{
			Arr[j+1] = Arr[j];
			j--;
			count++;
		}
		
		Arr[j+1] = key;
		
		printf("Sorted array pass %d\n", i);		//Print Array after one sort pass completed
		for (int i=0; i<size; i++)
			printf("%d ", Arr[i]);
		printf("\n");
	}
	
	printf("Sorted array\n");
	for (int i=0; i<size; i++)
		printf("%d ", Arr[i]);
	printf("\n");
	
	printf("\nSwap Count : %d\n", count);
	
}
	
int main()
{
	int Arr[] = {13, 12, 11, 6, 5, 1};
	int size = sizeof(Arr)/sizeof(Arr[0]);
	
	//Function for insertion sorting
	insertionSort(Arr, size);
	
	return 0;
}

/*
Time Complexity: O(n*n)
Auxiliary Space: O(1)
Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when
elements are already sorted.
Algorithmic Paradigm: Incremental Approach
Uses: Insertion sort is uses when number of elements is small. It can also be useful when input array is almost sorted, only few elements are
misplaced in complete big array.

Output :

puneet@jp:~/Workspace/DSA/Algorithms$ ./a.out 
Sorting array
13 12 11 6 5 1 
Sorted array pass 1
12 13 11 6 5 1 
Sorted array pass 2
11 12 13 6 5 1 
Sorted array pass 3
6 11 12 13 5 1 
Sorted array pass 4
5 6 11 12 13 1 
Sorted array pass 5
1 5 6 11 12 13 
Sorted array
1 5 6 11 12 13 

Swap Count : 15

*/