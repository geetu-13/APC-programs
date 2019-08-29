//method 1: use the code in "reverse linked list in k sized groups.c" and fix the value of k=2

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
struct node* swap_adj_nodes(struct node *h)
{
	struct node* nextt=NULL;
	struct node* prev=NULL;
	struct node* curr=h;
	int c=0;
	while(curr!=NULL && c<2)
	{
		nextt=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextt;
		c++;
	}
	if (nextt!=NULL)
	{
		h->next=swap_adj_nodes(nextt);
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
	printf("before swapping adjacent nodes:\n");
	show(&head);
	head=swap_adj_nodes(head);
	printf("after swapping adjacent nodes: \n");
	show(&head);
}
