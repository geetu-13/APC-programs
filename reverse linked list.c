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
void reverse(struct node** h)
{
	if (*h==NULL)
		return;
	else
	{
		struct node *curr=*h;
		int count=1;
		struct node *st=*h; // to save the first node, so that at the end we can mke st->next=NULL
		while (curr && curr->next)
		{
			curr=curr->next;
			count++;
		}
		
		while(count>1)
		{
			int d=count--;
			struct node* prev=*h;
			struct node *c=*h;
			while(d>1)
			{
				d--;
				prev=c;
				c=c->next;
			}
			c->next=prev;
		}
		*h=curr; //head pointer refers to the last node. 
		st->next=NULL;//and first node refers to NULL
	}
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
	printf("before reversing:\n");
	show(&head);
	printf("after reversing:\n");
	reverse(&head);
	show(&head);	
}
