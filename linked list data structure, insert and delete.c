//DATA STRUCTURES: LINKED LIST
#include<stdio.h>
struct node{
	int data;
	struct node * next;
};

void insertatbeg(struct node** head, int data)
{
	struct node*n=(struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->next=*head;
	*head=n;
}
void insertatend(struct node** h, int d)
{
	struct node* n=(struct node*) malloc(sizeof(struct node));
	n->data=d;
	n->next=NULL;
	struct node* curr=*h;
	if (*h==NULL)
		*h=n;
	else
	{
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=n;
	}
}

void show(struct node**h)
{
	struct node* curr=*h;
	if (*h!=NULL)
	{
		while(curr!=0)
		{
			printf("%d\n",curr->data);
			curr=curr->next;
		}
	}
}

void deleteatbeg(struct node** h)
{
	if (*h==NULL)
		return;
	else
	{
		struct node* temp=*h;
		*h=(*h)->next;
		free(temp);
		temp=NULL;
	}
}
void deleteatend(struct node** h)
{
	if (*h==NULL)
		return;
	else
	{
		struct node* curr=*h;
		while(curr && curr->next && curr->next->next)
		{
			curr=curr->next;			
		}			
		curr->next=NULL;	
	}
}

void insertatpos(struct node**h, int pos, int data)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	struct node *prev=*h;
	pos--;//pos starts from 1. 
	while (pos>0)
	{
		pos--;
		if (pos>0)
			prev=prev->next;
	}
	newnode->data=data;
	newnode->next=prev->next;
	prev->next=(newnode);
	
	
}
void deleteatpos(struct node**h, int pos)
{
	pos--;
	struct node *prev=*h;
	while (pos>0)
	{
		pos--;
		if (pos>0)
			prev=prev->next;
	}
	prev->next=prev->next->next;
}

int main()
{
	struct node *head=NULL;
	insertatbeg(&head, 20);
	insertatend(&head, 30);
	insertatend(&head, 40);
	insertatend(&head, 50);
	insertatbeg(&head, 10);
	insertatpos(&head, 2, 100);
	show(&head);
	deleteatbeg(&head);
	deleteatend(&head);
	printf("\nafter deleting: \n");
	show(&head);
	deleteatpos(&head, 2);
	printf("\nafter deleting: \n");
	show(&head);
	return 0;
}
