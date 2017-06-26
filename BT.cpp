#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
void preorder(node* root)
{
	if(root==NULL)return;
	preorder(root->left);
	preorder(root->right);
	cout<<root->data<<" ";
}
void inorder(node* root)
{
	if(root==NULL)return;
	preorder(root->left);
	cout<<root->data<<"  ";
	preorder(root->right);
}
void postorder(node* root)
{
	if(root==NULL)return;
	cout<<root->data<<"  ";
	preorder(root->left);
	preorder(root->right);
}
node* newnode(int data)
{
	node* temp=new node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
node* insert(node *root,int x)
{
	char ch;
	if(root==NULL)
	{
		root=newnode(x);
		return root;
	}
	cout<<"enter choice where to add node l or r with respect to root node"<<endl;
	cin>>ch;
	if(ch=='l')
	{
		root->left=insert(root->left,x);
	}
	else if(ch=='r')
	{
		root->right=insert(root->right,x);
	}
	return root;
}
void display(node* root,int level)
{
	int i;
	if(root==NULL)
	{
		return;
	}
	display(root->right,level+1);
	for(i=0;i<level;i++)cout<<"    ";
	cout<<root->data<<endl;
	display(root->left,level+1);
}
main()
{
	node* root=NULL;
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,50);
	display(root,0);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
}
