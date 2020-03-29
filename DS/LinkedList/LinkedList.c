#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void printLinkedList(struct Node *head)
{
	printf("	Linked List: ");

	struct Node *curr = head;
	while(curr != NULL)
	{
		printf("%d -> ", curr -> data);
		curr = curr -> next;
	}
	printf("NULL\n");
}

void addNodeAtStart(struct Node **head_ref, int data)
{

	printf("Add element at start: %d\n", data);
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode -> data = data;
	newNode -> next = *head_ref;
	*head_ref = newNode;
}

void addNodeAtEnd(struct Node **head_ref, int data)
{
	printf("Add element at end: %d\n", data);
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;
	newNode -> next = NULL;

	struct Node *curr = *head_ref;	
	while(curr -> next != NULL)
	{
		curr = curr -> next;
	}
	curr -> next = newNode;
}

void addNodeAtPosition(struct Node **head_ref, int data, int pos)
{
	printf("Add element %d at position %d\n", data, pos);
	struct Node *newNode, *temp;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;

	struct Node *curr = *head_ref;	
	while(pos-- != 2)
	{
		if (curr -> next != NULL)
			curr = curr -> next;
		else
			break;
	}
	temp = curr -> next;
	curr -> next = newNode;
	newNode -> next = temp;
}

void delNodeAtStart(struct Node **head_ref)
{
	printf("Deleting node %d at starting\n", (*head_ref) -> data );
	struct Node *curr = *head_ref;
	*head_ref = (*head_ref) -> next;
	free(curr);
}

void delNodeAtEnd(struct Node **head_ref)
{
	struct Node *curr = *head_ref;
	struct Node *tmp;
	while(curr -> next != NULL)
	{
		tmp = curr;
		curr = curr -> next;
	}
	printf("Deleting node %d at end\n", tmp -> next -> data );
	tmp -> next = NULL;
	free(curr);
}

void delNodeAtPosition(struct Node **head_ref, int pos)
{
	struct Node *curr = *head_ref;
	struct Node *tmp;
	while(curr -> next != NULL && (pos-- !=  1))
	{
		tmp = curr;
		curr = curr -> next;
	}
	printf("Deleting node %d\n", tmp -> next -> data);
	tmp -> next = curr -> next;
	free(curr);
}

void delLinkedList(struct Node **head_ref)
{
	struct Node *curr = *head_ref;
	struct Node *tmp;
	printf("Deleting linked list\n");
	while(curr != NULL)
	{
		tmp = curr;
		curr = curr -> next;
		free(tmp);
	}
	*head_ref = curr;
}

int main()
{
	struct Node *head = NULL;
	struct Node *tail = NULL;

	printLinkedList(head);
	addNodeAtStart(&head, 4);
	addNodeAtStart(&head, 3);
	addNodeAtStart(&head, 2);
	addNodeAtStart(&head, 1);
	addNodeAtEnd(&head, 5);
	addNodeAtEnd(&head, 8);
	addNodeAtEnd(&head, 9);
	addNodeAtPosition(&head, 7, 6);
	printLinkedList(head);
	delNodeAtStart(&head);
	printLinkedList(head);
	delNodeAtEnd(&head);
	printLinkedList(head);
	delNodeAtPosition(&head, 3);
	printLinkedList(head);
	delLinkedList(&head);
	printLinkedList(head);
}