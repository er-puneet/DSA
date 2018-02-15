#include <stdio.h>

/* Utility that finds GCD of two numbers */
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else 
		return gcd(b, a%b);
}

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int rotateArray(int arr[], int size, int d)
{
	int i, j, k, temp;
	for(int i=0; i<gcd(size, d); i++)
	{
		j = i;
		temp = arr[i];
		while (1)
		{
			k = j+d;
			if (k >= size) 
				k = k - size;
			if (k==i)
				break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}

/* Driver function to test above functions */
int main()
{
	/* Initialize array */
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	//{2, 8, 21, 43, 3, 13, -21, 15, 20};
	int m = sizeof(arr)/sizeof(arr[0]);
	int d = 4;
	
	printf("Array : ");
	printArray(arr, m);
	
	rotateArray(arr, m, d);
	
	printf("Rotated Array : ");
	printArray(arr, m);
	
}


/*
Program for array rotation
Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.

*******METHOD 1 (Use temp array)*******
Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
1) Store d elements in a temp
	temp[] = [1, 2]
2) Shift rest of the arr[]
	arr[] = [3, 4, 5, 6, 7]
3) Store back the d elements
	arr[] = [3, 4, 5, 6, 7, 1, 2]

Time complexity O(n)
Auxiliary Space: O(d)

*******METHOD 2 (Rotate one by one)*******
leftRotate(arr[], d, n)
start
	For i = 0 to i < d
		Left rotate all elements of arr[] by one
end

To rotate by one, store arr[0] in a temporary variable temp, move arr[1] to arr[0], arr[2] to arr[1] and finally temp to arr[n-1]

Time complexity: O(n*d)
Auxiliary Space: O(1)

*******METHOD 3 (A Juggling Algorithm)*******
This is an extension of method 2. Instead of moving one by one, divide the array in different sets
where number of sets is equal to GCD of n and d and move the elements within sets.
If GCD is 1 as is for the above example array (n = 7 and d =2), then elements will be moved within one set only, we just start with temp = arr[0]
and keep moving arr[I+d] to arr[I] and finally store temp at the right place.

Here is an example for n =12 and d = 3. GCD is 3 and
	Let arr[] be {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
a) Elements are first moved in first set
	arr[] after this step --> {4 2 3 7 5 6 10 8 9 1 11 12}
b) Then in second set.
	arr[] after this step --> {4 5 3 7 8 6 10 11 9 1 2 12}
c) Finally in third set.
	arr[] after this step --> {4 5 6 7 8 9 10 11 12 1 2 3}
	
Time complexity: O(n)
Auxiliary Space: O(1)

Outout:
puneet@jp:~/Workspace/DSA/DS/Array$ ./a.out 
Array : 1 2 3 4 5 6 7 8 9 10 11 12 
Rotated Array : 5 6 7 8 9 10 11 12 1 2 3 4

*/