#include<stdio.h>
struct node
{
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
struct node* reverse(struct node *h, int k)
{
	struct node* nextt=NULL;
	struct node* prev=NULL;
	struct node* curr=h;
	int c=0;
	while(curr!=NULL && c<k)
	{
		nextt=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextt;
		c++;
	}
	if (nextt!=NULL)
	{
		h->next=reverse(nextt, k);
	}
	return prev;
	
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
	printf("before reversing nodes in k size groups:\n");
	show(&head);
	printf("k= ");
	int k;
	scanf("%d",&k);
	printf("after reversing nodes in k size groups:\n");
	head=reverse(head,k);
	show(&head);
}
