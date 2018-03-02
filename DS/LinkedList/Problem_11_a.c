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
		printf("%2d -> ", head -> data);
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

void move(struct node **dest, struct node **src)
{
	struct node *temp = *src;
	
	*src = temp -> next;
	
	*dest = temp;
}


struct node* sortedMerge(struct node *a, struct node *b)
{
	struct node temp;
	temp.next = NULL;
	
	struct node * tail = &temp;
	
	while(1)
	{
		if(a == NULL)
		{
			tail -> next = b;
			break;
		}
		
		if(b == NULL)
		{
			tail -> next = a;
			break;
		}
		
		if(a -> data < b -> data)
			move(&(tail -> next), &a);
		else
			move(&(tail -> next), &b);
		tail = tail -> next;
	}
	return temp.next;
}

/* Program to create a simple linked list and count all element in it */
int main()
{
	struct node* a = NULL;
	struct node* b = NULL;
	int count;
	
	append(&a, 2);
	append(&a, 6);
	append(&a, 20);
	
	append(&b, 0);
	append(&b, 10);
	append(&b, 15);
	append(&b, 25);
	
	printLinkedList(a);
	printLinkedList(b);
	
	struct node* c = sortedMerge(a, b);
	printLinkedList(c);
}


/*
Merge two sorted linked lists
Write a SortedMerge() function that takes two lists, each of which is sorted in increasing order, and merges the two together into one list which is in increasing order.
SortedMerge() should return the new list. The new list should be made by splicing together the nodes of the first two lists.

	For example if the first linked list a is 5->10->15 and the other linked list b is 2->3->20, 
	then SortedMerge() should return a pointer to the head node of the merged list 2->3->5->10->15->20.

Method 1 (Using Dummy Nodes)
The strategy here uses a temporary dummy node as the start of the result list. The pointer Tail always points to the last node in the result list, so appending new nodes is easy.
The dummy node gives tail something to point to initially when the result list is empty. This dummy node is efficient, since it is only temporary, and it is allocated in the stack.
The loop proceeds, removing one node from either a or b, and adding it to tail. When we are done, the result is in dummy.next.

Time Complexity: O(n)
Space Complexity: O(1)

Output:

puneet@jp:~/Workspace/DSA/DS/LinkedList$ ./a.out 
Append node : 2
Append node : 6
Append node : 20
Append node : 0
Append node : 10
Append node : 15
Append node : 25
Linked List :  2 ->  6 -> 20 -> NULL
Linked List :  0 -> 10 -> 15 -> 25 -> NULL
Linked List :  0 ->  2 ->  6 -> 10 -> 15 -> 20 -> 25 -> NULL

*/