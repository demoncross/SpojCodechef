//belman-ford

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

struct e
{
	int u,v,w;
}edges[10004];
double d[105];

int main()
{
	int n,m,i,j,u,v,w;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&m);
		j=0;
		for(i=0;i<m;i++)	
		{
			scanf("%d%d%d",&u,&v,&w);
			edges[j].u=u;
			edges[j].v=v;
			edges[j].w=w;
			j++;
			edges[j].u=v;
			edges[j].v=u;
			edges[j].w=w;
			j++;
		}
		m=2*m;
		for(i=1;i<=n;i++)	d[i]=-1;
		d[1]=1;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<m;j++)
			{
				if(d[edges[j].u]==-1)	continue;
				d[edges[j].v]=max(d[edges[j].v],(d[edges[j].u]*edges[j].w)/100);
			}
		}
		printf("%.6f percent\n",d[n]*100);
		scanf("%d",&n);
	}
	return 0;
}