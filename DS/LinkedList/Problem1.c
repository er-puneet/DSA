#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node *next;
};

void push(struct Node **head_ref, int data)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	
	newNode -> data = data;
	newNode -> next = *head_ref;
	*head_ref = newNode;
	printf("PUSH : %d\n", data);
}

void pop(struct Node **head_ref)
{
	struct Node *tmp;
	if (*head_ref)
	{
		tmp = *head_ref;
		*head_ref = (*head_ref) -> next;
		printf("POP : %d\n", tmp -> data);
		free(tmp);
	}
	else
		printf("Nothing to POP\n");
}

void printStack(struct Node *head_ref)
{
	struct Node *curr = head_ref;
	printf("Stack: ");
	while (curr)
	{
		printf("%d, ", curr -> data);
		curr = curr -> next;
	}
	printf("END\n");
}

int main()
{
	
	struct Node *head = NULL;
	push(&head, 1);
	//push(&head, 2);
	//push(&head, 3);
	//push(&head, 4);
	pop(&head);
	pop(&head);
	push(&head, 2);
	printStack(head);
}