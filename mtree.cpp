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
bool visited[100005]={0};

ll workout(int node,ll *k)
{
	visited[node]=1;
	ll flag,x,y,ans,i,j=0;
	flag=0;
	ans=x=y=0;
	for(i=0;i<list[node].size();i++)
	{
		if(visited[list[node][i].first])	continue;
		flag=1;
		ans=(ans+workout(list[node][i].first,k))%MOD;
		*k=((*k+1)*list[node][i].second)%MOD;
		x=(x+(*k*(*k)));
		y=(y+*k);
	}
	//cout<<node<<" "<<ans<<" "<<*k<<" "<<x<<" "<<y<<endl;
	*k=y%MOD;
	x=(y*y)-x;
	while(x<0)	x+=	MOD;
	x=x;
	x=x/2;
	ans=(ans+x+y)%MOD;
	//cout<<node<<" "<<ans<<" "<<*k<<" "<<x<<endl;
	return ans%MOD;
}

int main()
{
	ll i;
	int n,u,v,w;
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		list[u].push_back(make_pair(v,w));
		list[v].push_back(make_pair(u,w));
	}
	printf("%lld\n",workout(1,&i)%MOD);
	return 0;
}