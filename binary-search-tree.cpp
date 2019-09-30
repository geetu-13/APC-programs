#include<stdio.h>
#include<stdlib.h>
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
int getMax(struct node* root)
{
	if(root->right==NULL)
	return root->key;
	return(getMax(root->right));
}
struct node* del_min(struct node* r)
{
	if(r->left==NULL)
	return r->right;
	r->left=del_min(r->left);
	return r;
}
void delmin(struct node* root)
{
	if(root==NULL)
	return;
	root=del_min(root);
}

struct node* delete_node(struct node* root, int k)
{	//conditions:
	//1. full tree	//2. right is null	//3. left is null	//4. delete root	//5. both child are null
	if (root==NULL)
		return NULL;//key not found
	if (k > root->key)
		root->right=delete_node(root->right,k);
	else if (k < root->key)
		root->left=delete_node(root->left, k);
	else if (root->right==NULL && root->key==k)
		return root->left;
	else if (root->left==NULL && root->key==k)
		return root->right;
	else
		{
			struct node* temp=newNode(getMin(root->right));
			//temp->key=getMin(root->right);
			delmin(root->right);
			temp->left=root->left;
			temp->right=root->right;
			return temp;
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
printf("\n");
printf("root elemenet: %d\n",root->key);
printf("min element of tree is %d\n",getMin(root));
printf("max element of tree is %d\n",getMax(root));
delmin(root);
printf("after deleting min node: \n");
print(root);
printf("\nmin element of tree is %d\nTree:\n",getMin(root));
int p;
printf("tree:\n");
print(root);
printf("\ndelete a node: ");
scanf("%d",&p);
root=delete_node(root, p);
printf("after deleting the node:\n");
print(root);
printf("\nroot: %d",root->key);
return 0;
}

