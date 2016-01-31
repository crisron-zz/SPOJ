// Kruskal's algorithm
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 1000

using namespace std;

int rank[MAX + 2];
int parent[MAX + 2];
vector <pair <int, pair <int, int> > > adj;

void createGraph (int);
void addEdge (int, int, int);
void reset (int);
int findSet (int);
void unionSet (int, int);
int kruskal ();

int main ()
{
	int t,p,n,m,cost;
	scanf ("%d",&t);
	while (t--)
	{
		scanf ("%d",&p);
		scanf ("%d",&n);		//vertices
		scanf ("%d",&m);		//edges
		createGraph (m);
		reset (n);
		cost = p * kruskal ();
		printf ("%d\n",cost);
	}
	return 0;
}

void createGraph (int m)
{
	int a,b,c,i;
	for (i = 0;i < m;i++)
	{
		scanf ("%d%d%d",&a,&b,&c);
		a--;
		b--;
		addEdge (a,b,c);
	}
}

void addEdge (int i, int j, int w)
{
	adj.push_back (make_pair (w, make_pair (i, j)));
	adj.push_back (make_pair (w, make_pair (j, i)));
}

void reset (int n)
{
	int i;
	for (i = 0;i < n;i++)
	{
		rank[i] = 1;
		parent[i] = i;
	}
}

int kruskal ()
{
	int i,u,v,pu,pv,w = 0;
	sort (adj.begin (), adj.end ());
	for (i = 0;i < adj.size ();i++)
	{
		u = adj[i].second.first;
		v = adj[i].second.second;
		pu = findSet (u);
		pv = findSet (v);
		if (pu != pv)
		{
			unionSet (pu,pv);
			w += adj[i].first;
		}
	}
	return w;
}

int findSet (int x)
{
	if (parent[x] != x)
		parent[x] = findSet (parent[x]);
	return parent[x];
}

void unionSet (int pu, int pv)
{
	if (pu != pv)
	{
		if (rank[pu] < rank[pv])
			parent[pu] = pv;
		else if (rank[pv] < rank[pu])
			parent[pv] = pu;
		else
		{
			parent[pu] = pv;
			rank[pv]++;
		}
	}
}
