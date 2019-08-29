#include<stdio.h>
struct stack
{
	int data;
	struct stack *next;
};
struct stack* push(int data,struct stack* head)
{
	struct stack *newNode=(struct stack *)malloc (sizeof(struct stack));
	if(newNode==NULL)
		printf("stack is full");
	else
	{
		newNode->data=data;
		newNode->next=head;
	}
	return newNode;
}
int pop(struct stack** head)
{
	struct stack* temp=*head;
	*head= temp->next;
	int t=temp->data;
	free(temp);
	temp=NULL;
	return t;
}

int main()
{
	struct stack *head=(struct stack *)malloc(sizeof(struct stack*));
head=	push(5,head);
head=	push(4,head);
head=	push(6,head);
head=	push(3,head);
head=	push(1,head);
printf("%d %d %d",pop(&head),pop(&head),pop(&head));
	return 0;
}
