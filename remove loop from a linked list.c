#include<stdio.h>
struct node
{
	int data;
	struct node* next;
};
void insertatbeg(struct node** head, int data)
{
	struct node*n=(struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->next=*head;
	*head=n;
}
int check(struct node* h)
{
	struct node *slow=h;
	struct node *fast=h;
	int flag=0;//not cyclic
	while(slow && fast && fast->next)
	{
		
		slow=slow->next;
		fast=fast->next->next;
		if (slow==fast) //return position where the cycle starts
		{
			flag=1;
			
				struct node* x=h;
				struct node* y=fast;
				struct node* prev=NULL;
				while (x!=y && x->next && y->next)
				{
					prev=y;
					x=x->next;
					y=y->next;
				}
				prev->next=NULL;//remove the cycle
				return x->data;//returns the start point of cycle in the linked list
			
		}
	}
	return flag;
}
int main()
{
	struct node* head=NULL;
	insertatbeg(&head,9);
	insertatbeg(&head,8);
	insertatbeg(&head,7);
	insertatbeg(&head,6);
	insertatbeg(&head,5);
	insertatbeg(&head,4);
	insertatbeg(&head,3);
	insertatbeg(&head,2);
	insertatbeg(&head,1);
	struct node* curr=head;
	while(curr && curr->next)
		curr=curr->next;
	curr->next=head->next->next;
	
	int flag=check(head);
	if (flag!=0)
	{
		printf("cyclic");
		printf("\npoint where cycle begins: %d",flag);
		printf("\nafter removing the cycle\ncheck function implemented again: ");
		flag=check(head);
		
	}
	if (flag==0)
	{
		printf("not cyclic");
	}
	return 0;
}
