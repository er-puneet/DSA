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
	{
		printf("Linked List is empty\n");
		return;
	}
	
	printf("Linked List : ");
	
	while(head != NULL)
	{
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");
}


/* Program to create a simple linked list with 3 nodes */
int main()
{
	struct node* head = NULL;
	struct node* mid = NULL;
	struct node* tail = NULL;
	
	printLinkedList(head);
	
	head = (struct node *)malloc(sizeof(struct node));
	mid = (struct node *)malloc(sizeof(struct node));
	tail = (struct node *)malloc(sizeof(struct node));
	
	head -> data = 1;
	head -> next = mid;
	
	mid -> data = 2;
	mid -> next = tail;
	
	tail -> data = 3;
	tail -> next = NULL;
	
	printLinkedList(head);
}


/*
First Simple Linked List in C

Output:

puneet@jp:~/Workspace/DSA/DS/LinkedList$ ./a.out 
Linked List is empty
Linked List : 1 2 3 

*/