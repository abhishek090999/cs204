#include<bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	int height;
	struct node* left;
	struct node* right ;
};

struct node* newnode(int key)
{
	struct node* temp=(struct node *)malloc(sizeof(struct node));
	temp->key=key;
	temp->right=temp->left=NULL;
	temp->height=1;
	return temp;

}

int height(struct node* temp)
{
	if(temp==NULL)
		return 0;
	return temp->height;
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}


struct node * RR(struct node *y) 
{ 
    struct node *x = y->left; 
    struct node *T2 = x->right; 
  
     
    x->right = y; 
    y->left = T2; 
  
  
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    
    return x; 
} 
  
struct node * LR(struct node *x) 
{ 
    struct node *y = x->right; 
    struct node *T2 = y->left; 
  
    
    y->left = x; 
    x->right = T2; 
  
    
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    
    return y; 
} 

int diffheight(struct node* temp)
{
	int d=height(temp->left)-height(temp->right);
	return d;
}

struct node* insert(struct node* root,int key)
{
	if(root==NULL)
		return newnode(key);
	if(key<root->key)
		root->left=insert(root->left,key);
	else if(key>root->key)
		root->right=insert(root->right,key);
	else 
		return root;

	root->height=1+max(height(root->left),height(root->right));

	int diff=diffheight(root);

	if(diff>1&&key<root->left->key)
		return RR(root);
	else if(diff<-1&&key>root->right->key)
		return LR(root);
	else if(diff>1&&key>root->left->key)
	{
		root->left=LR(root->left);
		 return RR(root);
	}
	else if(diff<-1&&key<root->right->key)
	{
		root->right=RR(root->right);
		return LR(root);
	}

	return root;
}

struct node* min(struct node* node)
{
	if(node==NULL)
		return node;
	struct node* temp=node;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}

struct node* del(struct node* root,int key)
{
	if(root==NULL)
		return root;
	if(key<root->key)
		root->left=del(root->left,key);
	else if(key>root->key)
		root->right=del(root->right,key);
	else
	{	if(root->right==NULL&&root->left==NULL)
		{
			struct node* temp=root;
			root=NULL;
			free(temp);
		}
		else if(root->right==NULL)
		{	
			struct node* temp=root->left;
			root=temp;
			free(temp);
		}
		else if(root->left==NULL)
		{
			struct node* temp=root->right;
			root=temp;
			free(temp);
		}
		else
		{
			struct node* temp=min(root->right);
			root->key=temp->key;

			root->right=del(root->right,temp->key);
		}
	}
	if(root==NULL)
		return root;
	root->height=1+max(height(root->left),height(root->right));
	int diff=diffheight(root);
	
	
	if (diff> 1 && diffheight(root->left) >= 0) 
		return RR(root); 


	if (diff > 1 && diffheight(root->left) < 0) 
	{ 
		root->left = LR(root->left); 
		return RR(root); 
	} 

	
	if (diff < -1 && diffheight(root->right) <= 0) 
		return LR(root); 

 
	if (diff< -1 && diffheight(root->right) > 0) 
	{ 
		root->right = RR(root->right); 
		return LR(root); 
	} 

	return root; 
} 




void preOrder(struct node *root) 
{ 
    if(root != NULL) 
    { 
        cout<<root->key<<endl;
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
  

int main() 
{ 
struct node *root = NULL; 

	
	root = insert(root, 9); 
	root = insert(root, 5); 
	root = insert(root, 10); 
	root = insert(root, 0); 
	root = insert(root, 6); 
	root = insert(root, 11); 
	root = insert(root, -1); 
	root = insert(root, 1); 
	root = insert(root, 2); 

	

	cout << "Preorder traversal of the constructed AVL tree is \n"; 
	preOrder(root); 

	root = del(root, 10); 

	

	cout << "\n"<< " deletion of 10 \n"; 
	preOrder(root); 

	return 0; 
} 


