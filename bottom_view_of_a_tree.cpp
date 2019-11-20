#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	int hd;
	node *left, *right;
	node(int key)
	{
		data=key;
		hd=INT_MAX;
		left=right=NULL;
	}
};

void bottomView(node *root)
{
	if (root==NULL)
		return;
	int hd=0;
	
	map<int, int> m;
	
	queue<node *> q;
	
	root->hd=hd;
	q.push(root);
	
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		hd=temp->hd;
		m[hd]=temp->data;
		if(temp->left!=NULL)
		{
			temp->left->hd=hd-1;
			q.push(temp->left);
		}
		
		if (temp->right!=NULL)
		{
			temp->right->hd=hd+1;
			q.push(temp->right);
		}
	}
	map<int, int>::iterator i; 
	for (i = m.begin(); i != m.end(); ++i) 
        cout << i->second << " ";
}

int main(){
	node *root=new node(20);
	root->left=new node(8);
	root->right=new node(22);
	root->left->left=new node(5);
	root->left->right=new node(3);
	root->right->left=new node(4);
	root->right->right=new node(25);
	root->left->right->left = new node(10); 
    root->left->right->right = new node(14); 
    bottomView(root);
    return 0;
	
}

