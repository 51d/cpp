#include<iostream>
using namespace std;
struct node{
	int x;
	node *left;
	node *right;
};
node* newnode(int data)
{
	node* temp=new node();
	temp->x=data;
	temp->left=temp->right=NULL;
	return temp;
	
}
node* insert(node *root,int data)
{
	if(root==NULL)
	{
		root=newnode(data);
		return root;
	}
	else if(data<root->x)
	{
		root->left=insert(root->left,data);
		return root;
	}
	else if(data>root->x)
	{
		root->right=insert(root->right,data);
		return root;
	}
}
void display(node* root,int level)
{
	int i;
	if(root==NULL)return;
	display(root->right,level+1);
	for(i=0;i<level;i++)
	cout<<"    ";
	cout<<root->x<<endl;
	display(root->left,level+1);
}
void preorder(node* root)
{
	if(root==NULL) return;
		cout<<root->x<<"  ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(node* root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->x<<"  ";
	inorder(root->right);
}
void postorder(node* root)
{
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->x<<"  ";
}
int min(node* root)
{
	int min;
	min=root->x;
	if(root->left==NULL)
	{
		return min;
	}
	else
	{
		while(root->left!=NULL)
		{
			root=root->left;
		}
		min=root->x;
		return min;
	}
}
node* dlt(node* root,int data)
{
	if(root==NULL) return root;
	else if(data<root->x)
	{
		root->left=dlt(root->left,data);
	}
	else if(data>root->x)
	{
		root->right=dlt(root->right,data);
	}
	else//gotcha
	{
		//leaf node
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root==NULL;
			return root;
		}
		//one child
		else if(root->left==NULL)
		{
			node* temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->right==NULL)
		{
			node* temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		//2child
		else
		{
			int m=min(root->right);
			root->x=m;
			root->right=dlt(root->right,m);
			return root;
		}
	}
}
int main()
{
	node* root=NULL;
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,5);
	root=insert(root,30);
	root=insert(root,15);
	display(root,0);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	root=dlt(root,5);
	display(root,0);
}
