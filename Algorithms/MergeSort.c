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