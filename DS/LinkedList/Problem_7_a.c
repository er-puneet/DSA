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

int getCountRec(struct node *head)
{
	if(head == NULL)
		return 0;
	else
		return 1 + getCountRec(head->next);
}

int getCountIter(struct node *head)
{
	int count = 0;
	
	while(head != NULL)
	{
		count++;
		head = head -> next;
	}
	return count;
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
	count = getCountRec(head);
	printf("Recursive Count : %d\n", count);
	count = getCountIter(head);
	printf("Iterative Count : %d\n", count);
	
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	
	printLinkedList(head);
	count = getCountRec(head);
	printf("Recursive Count : %d\n", count);
	count = getCountIter(head);
	printf("Iterative Count : %d\n", count);
}


/*
Find Length of a Linked List (Iterative and Recursive). Write a C function to count number of nodes in a given singly linked list.

For example, the function should return 5 for linked list 1->3->1->2->1.

Iterative Solution
	1) Initialize count as 0
	2) Initialize a node pointer, current = head.
	3) Do following while current is not NULL
		a) current = current -> next
		b) count++;
	4) Return count

Recursive Solution
	int getCount(head)
	1) If head is NULL, return 0.
	2) Else return 1 + getCount(head->next)

Output:

puneet@jp:~/Workspace/DSA/DS/LinkedList$ ./a.out 
Linked List is empty
Linked List : NULL
Recursive Count : 0
Iterative Count : 0
Append node : 1
Append node : 2
Append node : 3
Append node : 4
Append node : 5
Linked List : 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Recursive Count : 5
Iterative Count : 5

*/