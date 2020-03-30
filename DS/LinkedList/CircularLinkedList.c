#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void addNodeAtStart(struct Node **head_ref, int data)
{
	struct Node *curr = *head_ref, *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;
	
	while(curr && curr -> next && curr -> next != *head_ref)
		curr = curr -> next;

	if (*head_ref)
	{
		newNode -> next = *head_ref;
		curr -> next = newNode;
	}
	else
	{
		newNode -> next = newNode;
	}
	*head_ref = newNode;
}

void addNodeAtEnd(struct Node **head_ref, int data)
{
	struct Node *curr = *head_ref, *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;
	
	while(curr && curr -> next && curr -> next != *head_ref)
		curr = curr -> next;

	if (*head_ref)
	{
		newNode -> next = *head_ref;
		curr -> next = newNode;
	}
	else
	{
		newNode -> next = newNode;
		*head_ref = newNode;
	}
}

void delNodeAtStart(struct Node **head_ref)
{
	if (!(*head_ref))
		return;

	struct Node *curr = *head_ref, *tmp = NULL;

	while(curr -> next != *head_ref)
	{
		curr = curr -> next;
	}
	curr -> next = (*head_ref) -> next;
	tmp = *head_ref;
	*head_ref = (*head_ref) -> next;
	free(tmp);
}

void delNodeAtEnd(struct Node **head_ref)
{
	if (!(*head_ref))
		return;

	struct Node *curr = *head_ref, *tmp = NULL;

	while(curr -> next != *head_ref)
	{
		tmp = curr;
		curr = curr -> next;
	}
	tmp -> next = curr -> next;
	free(curr);
}

void printLinkedList(struct Node *head_ref)
{
	struct Node *curr = head_ref;

	printf("Linked List: ");
	do
	{
		printf("%d -> ", curr -> data);
		curr = curr -> next;
	}while(curr != head_ref);
	
	printf("REPEAT\n");
}

int main()
{
	struct Node *head = NULL;
	
	addNodeAtStart(&head, 4);
	addNodeAtStart(&head, 3);
	
	addNodeAtEnd(&head, 5);
	
	addNodeAtStart(&head, 2);
	addNodeAtStart(&head, 1);
	addNodeAtEnd(&head, 6);
	
	printLinkedList(head);
	delNodeAtStart(&head);
	printLinkedList(head);
	delNodeAtEnd(&head);
	printLinkedList(head);
}