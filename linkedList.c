#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *createNode(int value)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = NULL;
	return newnode;
}
void initList(struct node **pHead)
{
	*pHead = NULL;
}
int isEmpty(struct node *head)
{
	return head == NULL;
}

void addFirst(struct node **pHead, int value)
{
	struct node *newnode = createNode(value);
	newnode->next = *pHead;
	*pHead = newnode;
}

void addLast(struct node **pHead, int value)
{
	struct node *newnode = createNode(value);
	if(isEmpty(*pHead))
		*pHead = newnode;
	else{
		struct node *trav = *pHead;
		while(trav->next != NULL)
			trav = trav->next;
		trav->next = newnode;
	}
}

void displayList(struct node *head)
{
	struct node *trav = head;
	printf("List : ");
	while(trav != NULL){
		printf("%-4d", trav->data);
		trav = trav->next;
	}
	printf("\n");
}

void freeList(struct node **pHead)
{
	struct node *trav = *pHead;
	while(trav != NULL){
		struct node *temp = trav;
		trav = trav->next;
		free(temp);
	}
	*pHead = NULL;
}

int main(void)
{
	struct node *head;

	initList(&head);

	addFirst(&head, 11);
	addFirst(&head, 22);
	addFirst(&head, 33);
	addFirst(&head, 44);


	addLast(&head, 50);
	addLast(&head, 60);


	displayList(head);

	freeList(&head);

	return 0;
}




















