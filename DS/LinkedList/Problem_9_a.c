#include <stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};	

/* Utility that prints out a LinkedList on a line */
void printLinkedList(struct node *head)
{
	if (head == NULL)
		printf("Linked List is empty\n");
		
	printf("Linked List : ");
	
	while(head != NULL)
	{
		printf("%d -> ", head -> data);
		head = head -> next;
	}
	printf("NULL\n");
}

void swapNodes(struct node **head_ref, int x, int y)
{
	if(x == y)
		return;
	
	struct node *prevX = NULL, *currX = *head_ref;
	while(currX && currX -> data != x)
	{
		prevX = currX;
		currX = currX -> next;
	}
	
	struct node *prevY = NULL, *currY = *head_ref;
	while(currY && currY -> data != y)
	{
		prevY = currY;
		currY = currY -> next;
	}
	
	if(currX == NULL || currY == NULL)
		return;
	
	if(prevX != NULL)
		prevX -> next = currY;
	else
		*head_ref = currY;
	
	if(prevY != NULL)
		prevY -> next = currX;
	else
		*head_ref = currX;
	
	struct node *temp = currX -> next;
	currX -> next = currY -> next;
	currY -> next = temp;
}

/* Add a node in linked list in last/end */
void append(struct node** head_ref, int data)
{
	printf("Append node : %d\n", data);
	
	struct node* new_node = NULL;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = data;
	
	struct node *last = *head_ref;
	
	if(*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	while(last->next != NULL)
		last = last->next;
	
	last->next	 = new_node;
	return;
}

/* Program to create a simple linked list and count all element in it */
int main()
{
	struct node* head = NULL;
	int count;
	
	printLinkedList(head);
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	
	printLinkedList(head);
	
	swapNodes(&head, 1, 4);
	printf("After swapping 1 and 4, ");
	printLinkedList(head);
	
	swapNodes(&head, 4, 3);
	printf("After swapping 4 and 3, ");
	printLinkedList(head);

}


/*
Swap nodes in a linked list without swapping data
Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. Swapping data of nodes may
be expensive in many situations when data contains many fields.
It may be assumed that all keys in linked list are distinct.
Examples:
	Input: 10->15->12->13->20->14, x = 12, y = 20
	Output: 10->15->20->13->12->14

	Input: 10->15->12->13->20->14, x = 10, y = 20
	Output: 20->15->12->13->10->14
	
	Input: 10->15->12->13->20->14, x = 12, y = 13
	Output: 10->15->13->12->20->14
	
It has following cases to be handled.
	1) x and y may or may not be adjacent.
	2) Either x or y may be a head node.
	3) Either x or y may be last node.
	4) x and/or y may not be present in linked list.

The idea it to first search x and y in given linked list. If any of them is not present, then return. While searching for x and y, keep track of current
and previous pointers. First change next of previous pointers, then change next of current pointers.

Output:

puneet@jp:~/Workspace/DSA/DS/LinkedList$ ./a.out 
Linked List is empty
Linked List : NULL
Append node : 1
Append node : 2
Append node : 3
Append node : 4
Append node : 5
Linked List : 1 -> 2 -> 3 -> 4 -> 5 -> NULL
After swapping 1 and 4, Linked List : 4 -> 2 -> 3 -> 1 -> 5 -> NULL
After swapping 4 and 3, Linked List : 3 -> 2 -> 4 -> 1 -> 5 -> NULL

*/