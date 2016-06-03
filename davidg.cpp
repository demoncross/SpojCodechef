//prim's O(v*v). Kruskal's will give tle!

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

pair<int,int> a[1003];
double d[1003];

double dist(int c,int b)
{
	double x,y,ans;
	x=a[c].first-a[b].first;
	x=(x*x);
	y=a[c].second-a[b].second;
	y=(y*y);
	ans=sqrt(x+y);
	return ans;
}

int main()
{
	int test,k,mi,x,n,cost,i,j;
	double q;
	ll ans;
	scanf("%d",&test);
	x=1;
	while(test--)
	{
		scanf("%d%d",&n,&cost);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&j,&k);
			a[i]=make_pair(j,k);
		}
		for(i=1;i<=n;i++)	d[i]=MAXINT;
		d[1]=0;
		ans=0;
		for(i=1;i<=n;i++)
		{
			mi=-1;
			for(j=1;j<=n;j++)
				if(d[j]!=-1 && (mi==-1 || d[j]<d[mi]))	mi=j;
			//cout<<mi<<" "<<d[mi]<<endl;
			ans+=(ceil(d[mi]*cost));
			ans%=MOD;
			for(j=1;j<=n;j++)
			{
				if(d[j]==-1 || j==mi)	continue;
				q=dist(mi,j);
				d[j]=min(d[j],q);
			}
			d[mi]=-1;
		}
		printf("Scenario #%d: %lld\n",x,ans);
		x++;
	}
	return 0;
}