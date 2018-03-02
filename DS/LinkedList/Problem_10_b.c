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

void reverseRecursive(struct node **head_ref)
{
	if (*head_ref == NULL)
		return;

	struct node *first = *head_ref;
	struct node *res = first -> next;

	if(res == NULL)
		return;

	reverseRecursive(&res);

	first -> next -> next = first;

	first -> next = NULL;

	*head_ref = res;
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
	
	
	reverseRecursive(&head);
	printf("After reversing, ");
	printLinkedList(head);

}


/*
Write a function to reverse a linked list
Recursive Method:
	1) Divide the list in two parts - first node and rest of the linked list.
	2) Call reverse for the rest of the linked list.
	3) Link rest to first.
	4) Fix head pointer

Time Complexity: O(n)
Space Complexity: O(1)

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
After reversing, Linked List : 5 -> 4 -> 3 -> 2 -> 1 -> NULL

*/