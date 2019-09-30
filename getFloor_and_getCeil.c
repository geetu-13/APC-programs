//getfloor and getceiling 
#include<stdio.h>
struct node
{
	int key;
	struct node *left;
	struct node *right;
};
void print(struct node* root)
{
	if(root!=NULL)
	{
	print(root->left);
	printf("%d ",root->key);
	print(root->right);
    }
}
struct node* newNode(int i)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key=i;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node* insert(struct node* te , int k)
{
	if(te==NULL)
	return newNode(k);
	if(k<te->key)
		te->left=insert(te->left , k);
	else if(k>te->key)
		te->right=insert(te->right , k);
	return te;
}
int getMin(struct node* root)
{
	if(root->left==NULL)
	return root->key;
	return(getMin(root->left));
}
int floor(struct node* n, float x)//done
{
	if (n==NULL)
		return NULL;
	if (n->key==x)
		return n->key;
	if (n->key>x)
		return floor(n->left, x);
	int temp=floor(n->right, x);
	return temp==NULL?n->key:temp;
	
}
int ceil(struct node* n, float x)//one testcase ceil(2.9)=3 but shows 4
{
	if (n==NULL)
		return NULL;
	if (n->key==x)
		return n->key;
	else if (n->key<x)
		return ceil(n->right, x);
	else if (n->key>x)
		{
		if (n->left==NULL)
			return n->key;
		else if (n->left->key>=x)
			return ceil(n->left,x);
		else if (n->left->key<x)
			return n->key;
		}
}
int main()
{
	struct node *root=NULL;
	int n,i,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		root=insert(root,k);
	}
	printf("tree: \n");
	print(root);
	printf("\ntestcases: ");
	int t;
	scanf("%d",&t);
	float f[t];
	for(i=0;i<t;i++)
		scanf("%f",&f[i]);
	printf("\nfloor: ");
	for(i=0;i<t;i++)
		printf("\n%d", floor(root, f[i]));
	
	printf("\nceil: ");
	for(i=0;i<t;i++)
		printf("\n%d", ceil(root, f[i]));
	return 0;
}
