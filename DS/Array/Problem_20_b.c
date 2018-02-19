#include <stdio.h>
#include<limits.h>

struct pair
{
	int min;
	int max;
};

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
	printf("Array : ");
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}



/*Method to find first occurance of element in arr[]*/
struct pair getMinMax(int arr[], int low, int high)
{
	
	struct pair minmax, mml, mmr;
	int mid;
	
	if (high == low)
	{
		minmax.min = arr[low];
		minmax.max = arr[low];
		return minmax;
	}
	
	else if (high == low+1)
	{
		if(arr[low] > arr[high])
		{
			minmax.min = arr[high];
			minmax.max = arr[low];
		}
		else
		{
			minmax.min = arr[low];
			minmax.max = arr[high];
		}
		return minmax;
	}
	
	mid = (low+high)/2;
	
	mml = getMinMax(arr, low, mid);
	mmr = getMinMax(arr, mid+1, high);
	
	if(mml.min < mmr.min)
		minmax.min = mml.min;
	else 
		minmax.min = mmr.min;
	
	if(mml.max > mmr.max)
		minmax.max = mml.max;
	else
		minmax.max = mmr.max;
	
	return minmax;
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {1, 2, 30, 13, -3, -233, 10};
	int m = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, m);
	
	struct pair minmax = getMinMax(arr, 0, m-1);
	
	printf("Min and Max in array are : %d, %d\n", minmax.min, minmax.max);
	
	return 0;
}


/*
Maximum and minimum of an array using minimum number of comparisons
Write a C function to return minimum and maximum in an array. You program should make minimum number of comparisons.

METHOD 1 (Simple Linear Search)
Initialize values of min and max as minimum and maximum of the first two elements respectively. Starting from 3rd, compare each element with max
and min, and change max and min accordingly (i.e., if the element is smaller than min then change min, else if the element is greater than max then
change max, else ignore the element)

Time Complexity: O(n)
In this method, total number of comparisons is 1 + 2(n-2) in worst case and 1 + n 2 in best case.
In the above implementation, worst case occurs when elements are sorted in descending order and best case occurs when elements are sorted in
ascending order.

METHOD 2 (Tournament Method)
Divide the array into two parts and compare the maximums and minimums of the the two parts to get the maximum and the minimum of the the
whole array.

Pair MaxMin(array, array_size)
	if array_size = 1
		return element as both max and min
	else if arry_size = 2
		one comparison to determine max and min
		return that pair
	else
		array_size > 2 
		recur for max and min of left half
		recur for max and min of right half
		one comparison determines true max of the two candidates
		one comparison determines true min of the two candidates
		return the pair of max and min

Time Complexity: O(n)

Output:

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 1 2 30 13 -3 -233 10 
Min and Max in array are : -233, 30

*/