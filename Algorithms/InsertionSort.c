# include <stdio.h>

void insertionSort(int *Arr, int size)
{
	printf("Sorting array\n");
	
	for (int i=0; i<size; i++)
	{
		printf("%d ", Arr[i]);
	}
}
	
int main()
{
	int Arr[] = {12, 11, 13, 5, 6};
	int size = sizeof(Arr)/sizeof(Arr[0]);
	
	insertionSort(Arr, size);
	
	return 0;
}