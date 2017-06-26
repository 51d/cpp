#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
node* newnode(int data)
{
	node* temp=new node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
node* insert(node *root,int x)
{
	int i;
	char direction[10];
	if(root==NULL)
	{
		root=newnode(x);
		return root;
	}
	node* temp=newnode(x);
	node* cur;
	node *prev;
	prev=NULL;
	cur=root;
	printf("enter choice\n");
	scanf("%s" ,&direction);
	for(i=0;i<strlen(direction);i++)
	{
		if(cur==NULL)break;
		prev=cur;
		if(direction[i]=='l')
		cur=cur->left;
		else cur=cur->right;
	}
	if(cur!=NULL||i!=strlen(direction))
	{
		cout<<"insertion not possible";
		free(temp);
		return root;
	}
	if(direction[i]=='l')
	{
		prev->left=temp;
	}
	else
	{
		prev->right=temp;
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
}
