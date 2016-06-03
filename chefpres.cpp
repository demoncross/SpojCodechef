# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <queue>
# include <cmath>
# include <cstring>
# include <iostream>
# include <stack>
# include <map>
# include <vector>
# include <utility>
# include <set>
# include <deque>

# define MOD (1000000007)
# define MAXINT 1e9

using namespace std;
typedef long long int ll;

vector<int> list[10004];
int dp[10004][102];
int p[10004],parent[10004];
int k;

void work1(int node)
{
	int i,j,x;
	for(i=0;i<list[node].size();i++)
	{
		if(!parent[list[node][i]])
		{
			parent[list[node][i]]=node;
			work1(list[node][i]);
		}
	}
	for(i=0;i<list[node].size();i++)
	{
		x=list[node][i];
		if(x==parent[node])	continue;
		for(j=1;j<=k;j++)
		{
			if(dp[node][j]==0)	dp[node][j]=dp[x][j];
			else if(dp[x][j]==0)	continue;
			else				dp[node][j]=min(dp[node][j],dp[x][j]);
		}
	}
	if(dp[node][p[node]]==0)	dp[node][p[node]]=node;
	else						dp[node][p[node]]=min(dp[node][p[node]],node);
}

void work2(int node)
{
	int x,i;
	x=parent[node];
	if(x!=-1)
	{
		for(i=1;i<=k;i++)
			if(dp[node][i]==0)	dp[node][i]=dp[x][i];
	}
	for(i=0;i<list[node].size();i++)
	{
		if(list[node][i]==parent[node])	continue;
		work2(list[node][i]);
	}
}

int main()
{
	int i,n,root,x,y,q;
	scanf("%d%d",&n,&k);
	scanf("%d",&root);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		list[x].push_back(y);
		list[y].push_back(x);
	}
	for(i=1;i<=n;i++)	scanf("%d",&p[i]);
	parent[root]=-1;
	work1(root);
	work2(root);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(dp[x][y])	printf("%d\n",dp[x][y]);
		else			printf("-1\n");
	}
	return 0;
}