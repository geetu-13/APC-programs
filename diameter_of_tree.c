#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left, *right;
};
struct node * newNode(int data){
	struct  node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return (node);
}

int max(int a, int b)
{
	return (a>b?a:b);
}

int height(struct node*node){
	if(node==NULL)
		return 0;
	return 1+max(height(node->left),height(node->right));
}

int diameter(struct node *tree)
{
	if(tree==NULL)
		return 0;
		
	int lh=height(tree->left);
	int rh=height(tree->right);
	
	int ld=diameter(tree->left);
	int rd=diameter(tree->right);
	
	return max(lh+rh+1, max(ld,rd));
}



int main(){
	struct node* root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	printf("%d",diameter(root));
	return 0;
}

