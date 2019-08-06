#include<bits/stdc++.h>
using namespace std;
int l=0;
string s[20];
struct node
{
int x;
int y;
struct node *ptr;
};

struct node *createnode()
{
    struct node *temp;
temp = (struct node *) malloc(sizeof(struct
node));
return temp;
};

void addfirst(struct node **str,int a,int b)
{
    struct node *newnode;
    newnode=createnode();
    newnode->x=a;
    newnode->y=b;
    newnode->ptr=*str;
    *str=newnode;
};

void deletefirst(struct node **str)
{
    if(*str==NULL) return;
    struct node *temp;
    temp=*str;
    *str=(*str)->ptr;
    free(temp);
};

void del(struct node **str,int a,int b)
{
    struct node *prev,*temp,*temp1;
    prev=NULL;
        temp=*str;
        if(temp->x==a && temp->y==b)
        {
            deletefirst(str);
        }
        else
        {
        while(temp!=NULL)
        {
            if(temp->x==a&&temp->y==b)
            {
                prev->ptr=temp->ptr;
                temp1=temp;
                free(temp1);
                break;
            }
            else
            {
                prev=temp;
                temp=temp->ptr;
            }
        }
        }
};
void disp(struct node *str)
{
    struct node *temp;
    temp=str;
    while(temp!=NULL)
    {
        cout<<temp->x<<" "<<temp->y<<endl;
        temp=temp->ptr;
    }
}

void Search(struct node **str,int d)
{
    struct node *temp;
    temp=*str;
int flag=0;
    while(temp!=NULL)
    {
        int dist=sqrt((temp->x)*(temp->x)+(temp->y)*(temp->y));
        if(dist<=d)
        {
            s[l].push_back('(');
    s[l].push_back(temp->x+'0');
    s[l].push_back(',');
             s[l].push_back(temp->y+'0');
             s[l].push_back(')');
             flag=1;	
        }
        temp=temp->ptr;
    }
    if(flag==1) l++;
};

void Find(struct node **str,int a,int b)
{
    struct node *temp;
    temp=*str;
    while(temp!=NULL)
    {
        if((temp->x==a)&&(temp->y==b))
        {
            s[l].push_back('T');
            s[l].push_back('R');
            s[l].push_back('U');
            s[l].push_back('E');
            l++;
            break;
        }
        temp=temp->ptr;
    }
    if(temp==NULL) 
{
s[l].push_back('F');
s[l].push_back('A');
s[l].push_back('L');
s[l].push_back('S');
s[l].push_back('E');
l++;
}

};

void length(struct node **str)
{
    struct node *temp;
    temp=*str;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->ptr;
    }
    s[l].push_back(i+'0');
     l++;
};
 struct node *str1;

int main()
{

   str1=NULL;
   int i;
int n1;
cin>>n1;

for(int j=0;j<n1;j++)
{
   
       cin>>i;
       
        if(i==1)
       {
           int a,b;
           cin>>a>>b;
           addfirst(&str1,a,b);
       }

        if(i==2)
       {

           deletefirst(&str1);
       }

        if(i==3)
       {
           int a,b;
           cin>>a>>b;
          del(&str1,a,b);

       }

       if(i==4)
       {
           int d;
           cin>>d;
           Search(&str1,d);
       }

        if(i==5)
       {
           int a,b;
           cin>>a>>b;
           Find(&str1,a,b);
       }

        if(i==6)
       {
           length(&str1);
       }
   
  }
   
for(int j=0;j<l;j++)
{
cout<<s[j]<<endl;


}
   return 0;
}
