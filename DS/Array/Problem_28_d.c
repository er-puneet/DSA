#include <stdio.h>
#include<stdlib.h>

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
	printf("Array : ");
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/* Function to print two numbers which occur twice in a given array arr[] */
void printRepeating(int arr[], int size)
{
	int x = 0, y = 0;
	int xor = arr[0], i = 0;
	int n = size-2;
	
	//Find XOR of all elements in arr[]
	for(i=1; i<size; i++)
		xor = xor^arr[i];
	
	//Find XOR of all elements in arr[] and 1...n
	for(i=1; i<=n; i++)
		xor = xor^i;		//At last, xor will contain xor of x and y repeated elements
	
	int first_set_bit = xor & ~(xor-1);		//This will return first set bit in xor. i.e. c = 10 ('0b1010') --> '0b10'
	
	/* Now divide elements in two sets by comparing rightmost set bit of xor with bit at same position in each element. */
	for(i = 0; i < size; i++)
	{
		if(arr[i] & first_set_bit)
			x = x ^ arr[i]; /*XOR of first set in arr[] */
		else
			y = y ^ arr[i]; /*XOR of second set in arr[] */
	}
	for(i = 1; i <= n; i++)
	{
		if(i & first_set_bit)
			x = x ^ i; /*XOR of first set in arr[] and {1, 2, ...n }*/
		else
			y = y ^ i; /*XOR of second set in arr[] and {1, 2, ...n } */
	}
	
	printf("The two repeating elements are %d & %d \n", x, y);
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {4, 2, 7, 5, 2, 3, 1, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	/* Print Array */
	printArray(arr, n);
	
	printRepeating(arr, n);
	
	return 0;
}


/*
Find the two repeating elements in a given array
Given an array of n+2 elements. All elements of the array are in range 1 to n. And all elements occur once except two numbers which
occur twice. Find the two repeating numbers.
	For example, array = {4, 2, 4, 5, 2, 3, 1} and n = 5
	The above array has n + 2 = 7 elements with all elements occurring once except 2 and 4 which occur twice. So the output should be 4 2.

Method 1 (Basic)
	Use two loops. In the outer loop, pick elements one by one and count the number of occurrences of the picked element in the inner loop.
	This method doesnt use the other useful data provided in questions like range of numbers is between 1 to n and there are only two repeating
	elements.
	
Time Complexity: O(n*n)
Auxiliary Space: O(1)

Method 2 (Use Count array)
	Traverse the array once. While traversing, keep track of count of all elements in the array using a temp array count[] of size n, when you see an
	element whose count is already set, print it as duplicate.
	This method uses the range given in the question to restrict the size of count[], but doesnt use the data that there are only two repeating elements.
	
Time Complexity: O(n)
Auxiliary Space: O(n)

Method 3 (Make two equations)

	Let the numbers which are being repeated are X and Y. We make two equations for X and Y and the simple task left is to solve the two equations.
	We know the sum of integers from 1 to n is n(n+1)/2 and product is n!. We calculate the sum of input array, when this sum is subtracted from
	n(n+1)/2, we get X + Y because X and Y are the two numbers missing from set [1..n]. Similarly calculate product of input array, when this
	product is divided from n!, we get X*Y. Given sum and product of X and Y, we can find easily out X and Y.
	Let summation of all numbers in array be S and product be P
	X + Y = S n(n+1)/2
	XY = P/n!
	
Time Complexity: O(n)
Auxiliary Space: O(1)

Method 4 (Use XOR)

	Let the repeating numbers be X and Y, if we xor all the elements in the array and all integers from 1 to n, then the result is X xor Y.
	The 1s in binary representation of X xor Y is corresponding to the different bits between X and Y. Suppose that the kth bit of X xor Y is 1, we
	can xor all the elements in the array and all integers from 1 to n, whose kth bits are 1. The result will be one of X and Y.

Output :

puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 4 2 7 5 2 3 1 6 7 
The two repeating elements are 7 & 2 

*/