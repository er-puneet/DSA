#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

void addNodeAtStart(struct Node **head_ref, int data)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode -> data = data;
	newNode -> next = *head_ref;
	newNode -> prev = NULL;
	if (*head_ref)
		(*head_ref) -> prev = newNode;

	*head_ref = newNode;
}

void addNodeAtEnd(struct Node **head_ref, int data)
{
	struct Node *newNode, *curr;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;
	
	curr = *head_ref;
	while(curr -> next != NULL)
	{
		curr = curr -> next;
	}
	curr -> next = newNode;
	newNode -> next = NULL;
	newNode -> prev = curr;
}

void addNodeAtPosition(struct Node **head_ref, int data, int pos)
{
	struct Node *newNode, *curr = *head_ref, *tmp = NULL;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;

	while(curr != NULL && --pos != 0)
	{
		tmp = curr;
		curr = curr -> next;
	}
	
	newNode -> prev = tmp;
	newNode -> next = curr;
	tmp -> next = newNode;
	curr -> prev = newNode;
}

void delNodeAtStart(struct Node **head_ref)
{
	struct Node *curr = *head_ref;
	if (*head_ref == NULL)
		return;
	*head_ref = (*head_ref) -> next;
	if (*head_ref != NULL)
		(*head_ref) -> prev = NULL;
	
	if (curr)
	{
		curr -> next = NULL;
		free(curr);
	}
}

void delNodeAtEnd(struct Node **head_ref)
{
	struct Node *curr = *head_ref, *tmp = NULL;
	while(curr && curr -> next != NULL)
	{
		tmp = curr;
		curr = curr -> next;
	}
	if (tmp)
		tmp -> next = NULL;
	if (curr)
		free(curr);
}

void delNodeAtPosition(struct Node **head_ref, int pos)
{
	struct Node *curr = *head_ref, *tmp;
	while(curr != NULL && --pos != 0)
	{
		tmp = curr;
		curr = curr -> next;
	}
	curr -> next -> prev = tmp;
	tmp -> next = curr -> next;
	free(curr);
}

void printLinkedList(struct Node *head_ref)
{
	struct Node *curr;
	curr = head_ref;
	printf("Linked List: ");
	while(curr != NULL)
	{
		printf("%d -> ", curr -> data);
		curr = curr -> next;
	}
	printf("NULL\n");
}

void printRevLinkedList(struct Node *head_ref)
{
	struct Node *curr = head_ref;
	while(curr -> next != NULL)
	{
		curr = curr -> next;
	}
	printf("Reverse Linked List: ");
	while(curr != NULL)
	{
		printf("%d -> ", curr -> data);
		curr = curr -> prev;
	}
	printf("NULL\n");
	
}

int main()
{
	struct Node *head = NULL;
	
	addNodeAtStart(&head, 4);
	addNodeAtStart(&head, 3);
	addNodeAtStart(&head, 2);
	addNodeAtStart(&head, 1);
	
	addNodeAtEnd(&head, 6);
	addNodeAtPosition(&head, 5, 5);
	
	printLinkedList(head);
	printRevLinkedList(head);
	
	delNodeAtStart(&head);
	delNodeAtEnd(&head);
	printLinkedList(head);
	delNodeAtPosition(&head ,2);
	printLinkedList(head);
	printRevLinkedList(head);
	delNodeAtStart(&head);
	//delNodeAtStart(&head);
	//delNodeAtStart(&head);
	//delNodeAtStart(&head);
	delNodeAtEnd(&head);
	printLinkedList(head);
	printRevLinkedList(head);
	printf("\nFinished");
}

