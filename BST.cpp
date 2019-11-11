#include<bits/stdc++.h>
using namespace std;

struct node 
{
	int key;
	struct node *left , *right, *p;
};

void inorder(struct node *root)
{
	if (root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<endl;
		inorder(root->right);
	}
}

struct node * tree_search(struct node* root,int key)
{
	if (root==NULL||root->key==key)
		return root;
	if (root->key<key)
		return tree_search(root->right,key);
	else if (root->key>key)
		return tree_search(root->left,key);
}

struct node * minimum(struct node* root)
{	
	struct node* temp=root;
	while(temp->left!=NULL)
		temp= temp->left;
	return temp;
}

struct node* maximum(struct node* root)
{
	struct node* temp;
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp;
}

struct node* successor(struct node* node)
{
	if(node==NULL)
		return node;
	if(node->right!=NULL)
		return minimum(node->right);
	struct node* x=node;
	struct node* y=x->p;
	while(y!=NULL&&y->right==x)
		y=y->p;
	return y;
}

struct node* newnode(int key)
{
	struct node* temp=(struct node *)malloc(sizeof(struct node));
	temp->key=key;
	temp->right=temp->left=temp->p=NULL;
}

struct node * insert(struct node* root,int key)
{
	if(root==NULL)
		return  newnode(key);
	if (key<root->key)
	{
		root->left=insert(root->left,key);
		root->left->p=root;
	}
	else if (key>root->key)
	{	
		root->right=insert(root->right,key);
		root->right->p=root;
	}
	return root;
}

struct node * deletekey(struct node* root,int key)
{
	if(root==NULL)
		return root;
	if(key<root->key)
		root->left=deletekey(root->left,key);
	else if(key>root->key)
		root->right=deletekey(root->right,key);
	else
	{
		if(root->right==NULL&&root->left==NULL)
		{
			return NULL;
		}
		else if(root->right==NULL)
		{

			struct node* temp=root->left;
			temp->p=root->p;
			free(root);
			return temp;


		}
		else if(root->left==NULL)
		{
			struct node* temp=root->right;
			temp->p=root->p;

			free(root);
			return temp;

		}

		else
		{
			struct node* temp=minimum(root->right);
			if(temp->p!=root)
			{
				temp->p->left=temp->right;
				temp->right->p=temp->p;
				temp->right=root->right;
				root->right->p=temp;
			}
			temp->left=root->left;

			root=temp;
			

		}


	}
	return root;
}


int main()
{
	struct node *root=NULL;
	root=insert(root,50);
	root=insert(root,40);
	root=insert(root,30);
	root=insert(root,60);
	root=insert(root,65);
	root=insert(root,70);

	inorder(root);

	struct node* temp=successor(root);
	cout<<"successor is "<<temp->key<<" ";
	temp=successor(temp);
	cout<<temp->key<<endl;

	root=deletekey(root,65);
	inorder(root);



	return 0;
}
