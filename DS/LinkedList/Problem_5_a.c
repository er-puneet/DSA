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

/* Delete node at given position in linked list */
void deleteNode(struct node **head_ref, int pos)
{
	printf("Delete node at position : %d\n", pos);
	
	if(*head_ref == NULL || pos < 1)
		return;
	
	struct node *temp = *head_ref;
	
	if(pos == 1)
	{
		*head_ref = temp-> next;
		free(temp);
		return;
	}
	
	for(int i = 1; temp != NULL && i < pos-1; i++)
		temp = temp -> next;
	
	if(temp == NULL || temp -> next == NULL)
		return;
	
	struct node *next = temp -> next -> next;
	free(temp -> next);
	temp -> next = next;
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
Delete a Linked List node at a given position

Given a singly linked list and a position, delete a linked list node at the given position. Example:

	Input: position = 2, Linked List = 8->2->3->1->7
	Output: Linked List = 8->3->1->7
	
	Input: position = 1, Linked List = 8->2->3->1->7
	Output: Linked List = 2->3->1->7

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
Delete node at position : 3
Linked List : 1 -> 2 -> 4 -> 5 -> NULL

*/