#include<iostream>
#include<map>
using namespace std;
struct node{
	int d;
	int hd;
	node *left, *right;
};
struct node* newNode(int d){
	struct node* n=new node();
	n->d=d;
	n->hd=INT_MAX;
	n->left=NULL;
	n->right=NULL;
	return n;
}

void printTopViewUntil(node *root, int height, int hd, map<int, pair<int,int> > &m){
	if (root==NULL)
		return;
		
	if(m.find(hd)==m.end())
		m[hd]=make_pair(root->d, height);
		
	else{
		pair<int, int>p=(m.find(hd))->second;
		
		if(p.second>height){
			m.erase(hd);
			m[hd]=make_pair(root->d,height);
		}
	}
	
	printTopViewUntil(root->left, height+1, hd-1, m);
	printTopViewUntil(root->right, height+1, hd+1, m);
}

void printTopView(node* root){
	map<int, pair<int,int> > m;
	printTopViewUntil(root, 0, 0, m);
	map<int, pair<int,int> >::iterator i;
	for(i=m.begin();i!=m.end();i++)
		{
			pair<int,int>p=i->second;
			cout<<p.first<<" ";
		}
}


int main(){
	struct node* root=newNode(20);
	root->left=newNode(10);
	root->right=newNode(30);
	root->right->right=newNode(40);
	root->left->right=newNode(50);
	root->left->left=newNode(60);
	printTopView(root);
	return 0;
}
