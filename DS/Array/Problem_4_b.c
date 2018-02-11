#include <stdio.h>

int maxSubArraySum(int arr[], int size)
{
	int max_so_far = 0, max_end_here = 0;
	int start = 0, end = 0;
	for (int i=0; i<size; i++)
	{
		max_end_here += arr[i];
		
		if (max_end_here < 0)
		{
			max_end_here = 0;
			start = -1;
		}
		else if(max_end_here > max_so_far)
		{
			if (start == -1)
				start = i;
			max_so_far = max_end_here;
			end = i;
		}
	}
	printf("start : %d, end : %d\n", start ,end);
	return max_so_far;
}

void printmaxSubArraySum(int arr[], int size)
{
	int sum = maxSubArraySum(arr, size);
	
	printf("Max sum of any sub array : %d\n", sum);
	
}

int main()
{
	int arr[] = {1, -2, -3, 4, -1, -2, 1, 5, -3, 3};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	printmaxSubArraySum(arr, arr_size);
}

/*
Largest Sum Contiguous Subarray
Write an efficient C program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
	Kadanes Algorithm:
		Initialize:
		max_so_far = 0
		max_ending_here = 0
		Loop for each element of the array
			(a) max_ending_here = max_ending_here + a[i]
			(b) if(max_ending_here < 0)
				max_ending_here = 0
			(c) else if(max_so_far < max_ending_here)
				max_so_far = max_ending_here
		return max_so_far
		
Explanation:
Simple idea of the Kadane's algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). And keep
track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). Each time we get a positive sum compare it
with max_so_far and update max_so_far if it is greater than max_so_far

Output: 

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
start : 3, end : 7
Max sum of any sub array : 7

Time Complexity: O(n)
Algorithmic Paradigm: Dynamic Programming
*/