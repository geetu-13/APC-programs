#include<stdio.h>
#include<stdlib.h>
struct node{
	int d;
	struct node *left, *right;
};
struct node* newNode(int d){
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->d=d;
	n->left=NULL;
	n->right=NULL;
	return n;
}
struct node* insertNode(struct node* n, int key){
	if (n==NULL)
		n=newNode(key);
	if (n->d > key){
		n->left=insertNode(n->left, key);
	}
	if (n->d < key){
		n->right=insertNode(n->right, key);
	}
	return n;
}

int rank(struct node* n){
	if (n==NULL)
		return 0;
	else 
	return 1+rank(n->left)+rank(n->right);
}

int find(struct node* root, int k){
	if (root==NULL)
		return -1;
	if (root->d==k){
		rank(root->left);
	}
	else if(root->d<k){
		find(root->right,k);
	}
	else{
		find(root->left,k);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int i;
	struct node* root=NULL;
	for(i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		root=insertNode(root, x);
	}
	int t;
	scanf("%d",&t);
	int test[t];
	for(i=0;i<t;++i)
	{
		scanf("%d",&test[i]);
	}
	for(i=0;i<t;++i){
		printf("%d\n",find(root, test[i]));
	}
	return 0;
}
