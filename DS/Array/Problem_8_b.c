#include<stdio.h>

/* Utility functions to get maximum of two integers */
int max(int valx, int valy)
{
	if (valx > valy)
		return valx;
	else
		return valy;
}

/* Utility functions to get minimum of two integers */
int min(int valx, int valy)
{
	if (valx < valy)
		return valx;
	else
		return valy;
}

/* Functions to get median of a sorted array*/
int median(int arr[], int n)
{
	if (n%2 == 0)
		return (arr[n/2 - 1] + arr[n/2])/2;
	else
		return arr[n/2];
}

/* This function returns median of ar1[] and ar2[]. 
Assumptions in this function: Both ar1[] and ar2[] are sorted arrays and both have n elements */
int getMedian(int arr1[], int arr2[], int n)
{
	if (n<=0)
		return -1;
	if (n==1)
		return (arr1[0] + arr2[0])/2;
	if (n==2)
		return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]))/2;
	
	int m1 = median(arr1, n); /* get the median of the first array */
	int m2 = median(arr2, n); /* get the median of the second array */
	
	if(m1==m2)
		return m1;
	
	if(m1<m2)
	{
		/*second half of array 1 and first half of array 2 will have median*/
		if (n%2 == 0)
			return getMedian(arr1+n/2-1, arr2, n - n/2 + 1);
		else
			return getMedian(arr1+n/2, arr2, n - n/2);
	}
	else
	{
		/*first half of array 1 and second half of array 2 will have median*/
		if (n%2 == 0)
			return getMedian(arr1, arr2+n/2+1, n - n/2 + 1);
		else
			return getMedian(arr1, arr2+n/2, n - n/2);
	}
}

/* Driver program to test above function */
int main()
{
	int ar1[] = {1, 2, 3, 6, 7};
	int ar2[] = {4, 6, 7, 8, 10};
	int n1 = sizeof(ar1)/sizeof(ar1[0]);
	int n2 = sizeof(ar2)/sizeof(ar2[0]);
	if (n1 == n2)
		printf("Median is %d\n", getMedian(ar1, ar2, n1));
	else
		printf("Doesn't work for arrays of unequal size");
	return 0;
}

/*
Median of two sorted arrays
Question: There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2
arrays(i.e. array of length 2n). The complexity should be O(log(n))

Median: In probability theory and statistics, a median is described as the number separating the higher half of a sample, a population, or a
probability distribution, from the lower half.

The median of a finite list of numbers can be found by arranging all the numbers from lowest value to highest value and picking the middle one.
For getting the median of input array { 12, 11, 15, 10, 20 }, first sort the array. We get { 10, 11, 12, 15, 20 } after sorting. Median is the middle
element of the sorted array which is 12.

There are different conventions to take median of an array with even number of elements, one can take the mean of the two middle values, or first
middle value, or second middle value.
Let us see different methods to get the median of two sorted arrays of size n each. Since size of the set for which we are looking for median is even
(2n), we are taking average of middle two numbers in all below solutions.

Method 1 (Simply count while Merging)
Use merge procedure of merge sort. Keep track of count while comparing elements of two arrays. If count becomes n(For 2n elements), we have
reached the median. Take the average of the elements at indexes n-1 and n in the merged array. See the below implementation.
Time Complexity: O(n)

Method 2 (By comparing the medians of two arrays)
This method works by first getting medians of the two sorted arrays and then comparing them.
Let ar1 and ar2 be the input arrays.
	Algorithm:
	1) Calculate the medians m1 and m2 of the input arrays ar1[]
	and ar2[] respectively.
	2) If m1 and m2 both are equal then we are done.
	return m1 (or m2)
	3) If m1 is greater than m2, then median is present in one
	of the below two subarrays.
		a) From first element of ar1 to m1 (ar1[0...|_n/2_|])
		b) From m2 to last element of ar2 (ar2[|_n/2_|...n-1])
	4) If m2 is greater than m1, then median is present in one
	of the below two subarrays.
		a) From m1 to last element of ar1 (ar1[|_n/2_|...n-1])
		b) From first element of ar2 to m2 (ar2[0...|_n/2_|])
	5) Repeat the above process until size of both the subarrays
	becomes 2.
	6) If size of the two arrays is 2 then use below formula to get
	the median.
		Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2

Time Complexity: O(logn)
Algorithmic Paradigm: Divide and Conquer

Output: 
puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Median is 6

*/