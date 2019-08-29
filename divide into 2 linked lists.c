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
struct node* mid(struct node** h)
{
	int count=1;
	struct node* curr=*h;
	while(curr && curr->next)
	{
		curr=curr->next;
		count++;
	}
	count=count/2;
	struct node *m=*h;
	while(count>0)
	{
		count--;
		m=m->next;
	}
	struct node *mid=m->next;
	m->next=NULL;
	return mid;
}


int main()
{
	struct node *head=NULL;
	insertatbeg(&head, 90);
	insertatbeg(&head, 80);
	insertatbeg(&head, 70);
	insertatbeg(&head, 60);
	insertatbeg(&head, 50);
	insertatbeg(&head, 40);
	insertatbeg(&head, 30);
	insertatbeg(&head, 20);
	insertatbeg(&head, 10);	
	printf("before dividing:\n");
	show(&head);
	struct node *m=mid(&head);
	printf("after dividing:\nfirst list:\n");
	show(&head);
	printf("after list:\n");
	show(&m);
}

