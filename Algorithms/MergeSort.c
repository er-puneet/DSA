#include <stdio.h>


void printArray(int arr[], int size)
{
	for (int i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void merge(int arr[], int left, int mid, int right)
{
	int sizeL = mid - left + 1;
	int sizeR = right - mid;
	
	int L[sizeL], R[sizeR];
	
	for (int i=0; i<sizeL; i++)
		L[i] = arr[left+i];
	
	for (int j=0; j<sizeR; j++)
		R[j] = arr[mid+1+j];
	
	int i = 0, j = 0, k = left;
	
	while(i < sizeL && j < sizeR)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;	
	}
	
	while(i<sizeL)
	{
		arr[k] = L[i];
		i++;	k++;
	}
	
	while(j<sizeR)
	{
		arr[k] = R[j];
		k++; 	j++;
	}
}


void mergeSort(int arr[], int left, int right)
{
	if(left < right)
	{
		int mid  = left + (right - left)/2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		
		merge(arr, left, mid, right);
	}
}

int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Sorting array\n");
	printArray(arr, arr_size);
	
	mergeSort(arr, 0, arr_size-1);
	
	printf("Sorted array\n");
	printArray(arr, arr_size);
	
	return 0;
}

/*
MergeSort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted
halves. The merg() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are
sorted and merges the two sorted sub-arrays into one. See following C implementation for details.
	MergeSort(arr[], l, r)
		If r > l
			1. Find the middle point to divide the array into two halves:
		middle m = (l+r)/2
			2. Call mergeSort for first half:
		Call mergeSort(arr, l, m)
			3. Call mergeSort for second half:
		Call mergeSort(arr, m+1, r)
			4. Merge the two halves sorted in step 2 and 3:
		Call merge(arr, l, m, r)

Time complexity of Merge Sort is O(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array in two halves andtake linear time to merge two halves.
Auxiliary Space: O(n)
Algorithmic Paradigm: Divide and Conquer

Output: 

puneet@jp:~/Workspace/DSA/Algorithms$ ./a.out 
Sorting array
12 11 13 5 6 7 
Sorted array
5 6 7 11 12 13 

*/