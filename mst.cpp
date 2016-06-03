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

vector<pair<ll,ll> > list[100005];
bool visited[100005];
ll parent[100005];
ll d[100005];

int main()
{
	ll n,m,u,v,w,i;
	ll ans;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		list[u].push_back(make_pair(v,w));
		list[v].push_back(make_pair(u,w));
	}
	for(i=0;i<=n;i++)	
	{
		visited[i]=false;
		parent[i]=-1;
		d[i]=(ll)1e15;
	}
	parent[1]=0;
	d[1]=0;
	set<pair<ll,ll> > q;
	ans=0;
	q.insert(make_pair(0,1));
	for(i=2;i<=n;i++)	q.insert(make_pair(d[i],i));
	while(!q.empty())
	{
		pair<ll,ll> t=*(q.begin());
		q.erase(t);
		ans+=t.first;
		visited[t.second]=1;
		for(i=0;i<list[t.second].size();i++)
		{
			v=list[t.second][i].first;
			w=list[t.second][i].second;
			if(!visited[v] && d[v]>w)
			{	
				q.erase(make_pair(d[v],v));
				q.insert(make_pair(w,v));
				d[v]=w;
				parent[v]=t.second;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}