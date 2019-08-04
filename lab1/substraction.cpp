#include<bits/stdc++.h>
using namespace std;
int main()
{
string s1,s2,s;
cin>>s1>>s2;
if(s1.length()<s2.length()) swap(s1,s2);
if (s1.length()==s2.length())
{
for(int i=0;i<s1.length();i++)
{
if(s1[i]>s2[i]) break;
if(s1[i]<s2[i])
{swap(s1,s2);
break;}
}
}

int n1=s1.length();
int n2=s2.length();
reverse(s1.begin(),s1.end());
reverse(s2.begin(),s2.end());

int c=0;
for(int i=0;i<n2;i++)
{
s1[i]=((s1[i]-'0')-c)+'0';
if((s1[i]-'0')>=(s2[i]-'0')) {c=0;}
if ((s1[i]-'0')<(s2[i]-'0')) 
{
s1[i]=((s1[i]-'0')+10)+'0';
c=1;
}
int diff=(s1[i]-'0')-(s2[i]-'0');
s.push_back(diff+'0');
}

for(int j=n2;j<n1;j++)
{
s1[j]=((s1[j]-'0')-c)+'0';
if((s1[j]-'0')>=1){c=0;}
if((s1[j]-'0')<1)
{
s1[j]=((s1[j]-'0')+10)+'0';
c=1;
}

s.push_back(s1[j]);

}

reverse(s.begin(),s.end());
cout<<s;
return 0;
}
