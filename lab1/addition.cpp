#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
int n1,n2;
n1=s1.length();
n2=s2.length();
if(n2>n1) swap(s1,s2);
int n=s1.length();
int m=s2.length();
reverse(s1.begin(),s1.end());
reverse(s2.begin(),s2.end());

int s[n];
int q=0;

for(int i=0;i<m;i++)
{
int sum=(s1[i]-'0')+(s2[i]-'0')+q;
s[i]=sum%10;
q=sum/10;
}

for(int j=m;j<n;j++)
{
	int sum=(s1[j]-'0')+q;
	s[j]=sum%10;
	q=sum/10;
}
cout<<q;
for(int i=n-1;i>=0;i--)
{
cout<<s[i];
}


return 0;



}
