//dijkstra's

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <utility>
#include <set>

#define MOD (1000000007)
#define MAXINT 1e9
using namespace std;
typedef long long int ll;

vector<pair<int,int> > list[100005];
int d[100005];

int main()
{
	int test,u,v,w,i,n,m,s,e;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d%d",&n,&m,&s,&e);
		for(i=1;i<=n;i++)	{list[i].clear();d[i]=MAXINT;}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			list[u].push_back(make_pair(v,w));
			list[v].push_back(make_pair(u,w));
		}
		set<pair<int,int> > q;
		q.insert(make_pair(0,s));
		d[s]=0;
		bool visited=false;
		for(i=1;i<=n;i++)
			if(i!=s)	q.insert(make_pair(d[i],i));
		while(!q.empty())
		{
			pair<int,int> p=*q.begin();
			if(p.first==MAXINT)	break;
			q.erase(p);
			if(p.second==e)	visited=1;
			for(i=0;i<list[p.second].size();i++)
			{
				u=list[p.second][i].first;
				w=list[p.second][i].second;
				if(d[u]>d[p.second]+w)
				{
					q.erase(make_pair(d[u],u));
					d[u]=d[p.second]+w;
					q.insert(make_pair(d[u],u));
				}
			}
		}
		if(!visited)	printf("NONE\n");
		else			printf("%d\n",d[e]);
	}
	return 0;
}