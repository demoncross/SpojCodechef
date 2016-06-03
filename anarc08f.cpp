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

vector<pair<int,int> > list[105],list_r[105];
int d[105],d_r[105];
map<string,int> ma;
char s[15],t[15];
int targets[100005],n;

void dj(vector <pair<int,int> > list[105],int *d)
{
	int i,v,w;
	d[1]=0;
	set<pair<int,int> > q;
	q.insert(make_pair(0,1));
	for(i=2;i<=n;i++)	q.insert(make_pair(d[i],i));
	while(!q.empty())
	{
		pair<int,int> p=*q.begin();
		q.erase(p);
		if(p.first==MAXINT)	return;
		for(i=0;i<list[p.second].size();i++)
		{
			v=list[p.second][i].first;
			w=list[p.second][i].second;
			if(d[v]>p.first+w)
			{
				q.erase(make_pair(d[v],v));
				d[v]=p.first+w;
				q.insert(make_pair(d[v],v));
			}
		}
	}
}

int main()
{
	int c,m,u,v,w,i,j,x,ans;
	char c1,c2;
	scanf("%d%d%d",&n,&c,&m);
	x=1;
	while(!(n==0 && c==0 && m==0))
	{
		for(i=0;i<=n;i++)	{list[i].clear();list_r[i].clear();d[i]=d_r[i]=MAXINT;}
		ma.clear();
		scanf(" %s",s);
		ma[s]=1;
		j=2;
		for(i=1;i<=c;i++)
		{
			scanf(" %s",s);
			if(ma.find(s)!=ma.end())	targets[i]=ma[s];
			else						targets[i]=ma[s]=j++;
		}
		for(i=0;i<m;i++)
		{
			scanf(" %s %c-%d-%c %s",s,&c1,&w,&c2,t);
			if(ma.find(s)!=ma.end())	u=ma[s];
			else						u=ma[s]=j++;
			if(ma.find(t)!=ma.end())	v=ma[t];
			else						v=ma[t]=j++;
			if(c1=='-' && c2=='>')
			{
				list[u].push_back(make_pair(v,w));
				list_r[v].push_back(make_pair(u,w));
			}
			else if(c1=='<' && c2=='-')
			{
				list_r[u].push_back(make_pair(v,w));
				list[v].push_back(make_pair(u,w));
			}
			else if(c1=='<' && c2=='>')
			{
				list[u].push_back(make_pair(v,w));
				list[v].push_back(make_pair(u,w));
				list_r[u].push_back(make_pair(v,w));
				list_r[v].push_back(make_pair(u,w));
			}
			else
				cout<<"error"<<endl;
		}

		dj(list,d);
		dj(list_r,d_r);
		ans=0;
		for(i=1;i<=c;i++)	ans=ans+d[targets[i]]+d_r[targets[i]];
		printf("%d. %d\n",x,ans);
		x++;
		scanf("%d%d%d",&n,&c,&m);
	}
	return 0;
}