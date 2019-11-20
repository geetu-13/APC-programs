#include<stdio.h>
#include<stdlib.h>

struct node{
	int d;
	struct node *left, *right;
};

struct node* newNode(int d)
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->d=d;
	n->left=n->right=NULL;
	return n;
}

int lca(struct node* root, int x, int y){
	if (root==NULL) return -1;
	if (root->d>x && root->d>y)
		return lca(root->left, x, y);
	if (root->d<x && root->d<y)
		return lca(root->right, x, y);
	return root->d;
}
int main(){
	struct node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14); 
    
    int t1=lca(root, 10, 14);
    int t2=lca(root, 14, 8);
    int t3=lca(root, 10, 22);
    printf("%d %d %d",t1,t2,t3);
}
