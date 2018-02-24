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

/* Add a node in linked list in last/end */
void append(struct node** head_ref, int data)
{
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

/* Inserts a new node on the front of the list. */
void push(struct node** head_ref, int data)
{
	struct node* new_node = NULL;
	struct node* head = *head_ref;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = data;
	new_node -> next = head;
	
	*head_ref = new_node;
	return;
}

/* Given a node prev_node, insert a new node after the given prev_node */
void insertAfter(struct node* prev_node, int data)
{
	if (prev_node == NULL)
	{
		printf("The given previous node cannot be NULL\n");
		return;
	}
	struct node* new_node = NULL;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = data;
	new_node -> next = prev_node -> next;
	prev_node -> next = new_node;
	return;
}

/* Program to create a simple linked list with 3 nodes */
int main()
{
	struct node* head = NULL;
	
	printLinkedList(head);
	
	push(&head, 1);		//1
	printLinkedList(head);
	
	append(&head, 3);	//1 -> 3
	printLinkedList(head);
	
	append(&head, 4);	//1 -> 3 -> 4
	printLinkedList(head);
	
	append(&head, 5);	//1 -> 3 -> 4 -> 5
	printLinkedList(head);
	
	push(&head, 0);		//0 -> 1 -> 3 -> 4 -> 5
	printLinkedList(head);
	
	insertAfter(head->next, 2);		//0 -> 1 -> 2 -> 3 -> 4 -> 5
	printLinkedList(head);
	
}


/*
Inserting a node in Linked List in C

Add a node at the front:
The new node is always added before the head of the given Linked List. And newly added node becomes the new head of the Linked List. 

For example if the given Linked List is 10->15->20->25 and we add an item 5 at the front, then the Linked List becomes 5->10->15->20->25. 

Add a node after a given node: 
We are given pointer to a node, and the new node is inserted after the given node.

Add a node at the end:
The new node is always added after the last node of the given Linked List. For example if the given Linked List is 5->10->15->20->25 and we add an item 30 at the end, then the Linked List becomes 5->10->15->20->25->30.
Since a Linked List is typically represented by the head of it, we have to traverse the list till end and then change the next of last node to new node.

Output:

Linked List is empty
Linked List : NULL
Linked List : 1 -> NULL
Linked List : 1 -> 3 -> NULL
Linked List : 1 -> 3 -> 4 -> NULL
Linked List : 1 -> 3 -> 4 -> 5 -> NULL
Linked List : 0 -> 1 -> 3 -> 4 -> 5 -> NULL
Linked List : 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL

*/