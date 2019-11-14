#include<bits/stdc++.h>
using namespace std;

int size;

struct Node
{
  int data;
  struct Node *ptr;
};


void insertatstart(struct Node **st,int val)
{
  struct Node *temp = new Node;
  temp->data = val;
  temp->ptr = *st;
  *st = temp;
}


void insertatend(struct Node **start,int val)
{
  struct Node *temp;
  temp = *start;
  if(temp==NULL)
  {
    insertatstart(start,val);
  }
  else
  {
    while(temp->ptr!=NULL)
    {
      temp = temp->ptr;
    }
    struct Node *temp1 = new Node;
    temp1->data = val;
    temp1->ptr = NULL;
    temp->ptr = temp1;
  }
}


void search(struct Node *start,int val)
{
  struct Node *temp;
  temp = start;
  int n=0;
  while(temp!=NULL)
  {
    if(temp->data == val)
    {
      n++;
    }
    temp = temp->ptr;
  }
  if(n>0)
  cout << "Exists " << n << " times" << endl;
  else
  cout << "Doesn't exist" << endl;
}

void deletenode(struct Node **start,int val)
{
  struct Node *temp,*prev;
  temp = *start;
  while(temp!=NULL)
  {
    if(temp->data == val)
      break;
    prev = temp;
    temp = temp->ptr;
  }
  if(temp == NULL)
  {
    cout << "Element not found";
  }
  else if(temp == *start)
    *start = temp->ptr;
  else
    prev->ptr = temp->ptr;
  free(temp);
}

void print(struct Node *start)
{
  struct Node *temp;
  temp = start;
  while(temp!=NULL)
  {
    cout << " --> "<< temp->data ;
    temp = temp->ptr;
  }
  cout << '\n';
}

Node **arr;

void Hashmap()
{
  arr = new Node*[size];
  for(int i=0 ; i < size ; i++)
  {
            arr[i]=NULL;
  }
}

int Hashfunc(int k)
{
  return k%size;
}

void insert(int k)
{
    int index = Hashfunc(k);
    insertatend(&arr[index],k);
}

void searchkey(int k)
{
  int index = Hashfunc(k);
  search(arr[index],k);
}

void deletekey(int k)
{
  int index = Hashfunc(k);
  deletenode(&arr[index],k);
}

void printHash()
{
  for (int i = 0; i < size; i++)
  {
    cout << i;
    print(arr[i]);
    cout << endl;
  }
}

int main()
{
  cin >>size;
  Hashmap();
  int a[] = {15,11,52,26,45,23,555,444,111,333,888,256,315
  };
  int n = sizeof(a)/sizeof(a[0]);
  for (int i = 0; i < n; i++)
    insert(a[i]);
  deletekey(15);
  searchkey(11);
  searchkey(88);
  printHash();

}
