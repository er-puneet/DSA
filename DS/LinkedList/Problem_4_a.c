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

/* Delete first occurance of a node in linked list */
void deleteNode(struct node **head_ref, int key)
{
	printf("Delete node : %d\n", key);
	
	struct node *temp = *head_ref, *prev;
	
	if(temp != NULL && temp -> data == key)
	{
		*head_ref = temp-> next;
		free(temp);
		return;
	}
	
	while(temp != NULL && temp -> data != key)
	{
		prev = temp;
		temp = temp -> next;
	}
	
	if(temp == NULL)
		return;
	
	prev -> next = temp -> next;
	free(temp);
	return;
}

/* Program to create a simple linked list and delete an element from it */
int main()
{
	struct node* head = NULL;
	
	printLinkedList(head);
	
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	
	printLinkedList(head);
	
	deleteNode(&head, 3);
	
	printLinkedList(head);
}


/*
Deleting a node

Given a key, delete the first occurrence of this key in linked list.

To delete a node from linked list, we need to do following steps.
	1) Find previous node of the node to be deleted.
	2) Changed next of previous node.
	3) Free memory for the node to be deleted.

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
Delete node : 3
Linked List : 1 -> 2 -> 4 -> 5 -> NULL

*/