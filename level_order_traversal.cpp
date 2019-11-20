#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int d;
		node *left, *right;
};
node *newNode(int d){
	node* n=new node();
	n->d=d;
	n->right=NULL;
	n->left=NULL;
	return n;
}
int height(node *n){
	if (n==NULL)
		return 0;
	else
	{
		int lh=height(n->left);
		int rh=height(n->right);
		if (lh>rh)
			return lh+1;
		else
			return rh+1;
	}
}
void printGivenLevel(node *root, int level){
	if (root==NULL)
		return;
	if (level==1)
		cout<<root->d<<" ";
	else if (level>1){
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}
}

void printLevelOrder(node *root){
	int h=height(root);
	int i;
	for(i=1;i<=h;i++)
		printGivenLevel(root,i);
}
int main(){
	node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    printLevelOrder(root);
    return 0;
}
