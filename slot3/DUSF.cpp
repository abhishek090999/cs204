#include <bits/stdc++.h>
#define ll long long
#define f(i, a, b) for(ll i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
//Disjoint set union find to detect cycle in a graph
class Edge
{
public:
    int src,dest;
};
class Graph
{
public:
    int V,E;
    Edge* edge;
    Graph(int v,int e);
};
Graph::Graph(int v, int e)
{
    this->V=v;
    this->E=e;
    edge = new Edge[e];
}
struct subset
{
    int parent;
    int rank;
};
int find(struct subset subsets[], int i)
{
    if(subsets[i].parent != i)
    {
        subsets[i].parent=find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union(struct subset subsets[],int x, int y)
{
    int xroot = find(subsets,x);
    int yroot = find(subsets, y);
    if(subsets[xroot].rank<subsets[yroot].rank)
    {
        subsets[xroot].parent=yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 
    else
    {
        subsets[yroot].parent=xroot;
        subsets[xroot].rank++;
    }
}
int isCycle(Graph g)
{
    int v=g.V;
    int e=g.E; 
    struct subset* subsets = new subset[v];
    for(int i=0;i<v;i++)
    {
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
    for(int i=0;i<e;i++)
    {
        int x=find(subsets,g.edge[i].src);
        int y=find(subsets,g.edge[i].dest);
        if(x==y) return 1;
        Union(subsets,x,y);
    }
    return 0;
}
int main()
{
    int V=3,E=3;
    Graph g(V,E);
    g.edge[0].src = 0; 
    g.edge[0].dest = 1; 
  
    g.edge[1].src = 1; 
    g.edge[1].dest = 2; 
  
    g.edge[2].src = 0; 
    g.edge[2].dest = 2; 
    if(isCycle(g)) cout<<"TRUE\n";
    else cout<<"FALSE\n";
}
