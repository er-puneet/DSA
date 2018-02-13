#include <stdio.h>
#define NA -1

void moveToEnd(int mPlusN[], int size)
{
	int i, j = size-1;
	for (i = size-1; i>=0; i--)
		if (mPlusN[i] != NA)
		{
			mPlusN[j] = mPlusN[i];
			j--;
		}
}

void merge(int mPlusN[], int N[], int m, int n)
{
	int k=0, j=0, i=n;
	
	while(k<m+n)
	{
		if(j<n && N[j]<mPlusN[i])
		{
			mPlusN[k] = N[j];
			j++; k++;
		}
		else
		{
			mPlusN[k] = mPlusN[i];
			i++; k++;
		}
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
	/* Initialize arrays */
	int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
	int N[] = {5, 7, 9, 25};
	int n = sizeof(N)/sizeof(N[0]);
	int m = sizeof(mPlusN)/sizeof(mPlusN[0]) - n;
	
	printArray(mPlusN, m+n);
	printArray(N, n);

	/*Move the m elements at the end of mPlusN*/
	moveToEnd(mPlusN, m+n);
	
	/*Merge N[] into mPlusN[] */
	merge(mPlusN, N, m, n);
	
	/* Print the resultant mPlusN */
	printArray(mPlusN, m+n);
	
	return 0;
}

/*

Merge an array of size n into another array of size m+n
There are two sorted arrays. First one is of size m+n containing only m elements. Another one is of size n and contains n elements. Merge these
two arrays into the first array of size m+n such that the output is sorted.
	Input: array with m+n elements (mPlusN[]).
	NA => Value is not filled/available in array mPlusN[]. There should be n such array blocks.
	Input: array with n elements (N[]).
	Output: N[] merged into mPlusN[] (Modified mPlusN[])

Algorithm:
Let first array be mPlusN[] and other array be N[]
	1) Move m elements of mPlusN[] to end.
	2) Start from nth element of mPlusN[] and 0th element of N[] and merge them into mPlusN[]

Time Complexity: O(m+n)

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
2 8 -1 -1 -1 13 -1 15 20 
5 7 9 25 
2 5 7 8 9 13 15 20 25 

*/