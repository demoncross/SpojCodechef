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

int dp[21][1<<12][11];
int cost[11][21];


int main()
{
	int i,j,k,l,ans,n;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		for(j=0;j<=(1<<k);j++)
			for(l=0;l<=k;l++)
				dp[i][j][l]=MAXINT;
	for(i=1;i<=k;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	for(i=1;i<=k;i++)
	{	
		dp[1][0|(1<<(i-1))][i]=cost[i][1];
		dp[1][0|(1<<(i-1))][0]=min(dp[1][0|(1<<(i-1))][i],dp[1][0|(1<<(i-1))][0]);
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j<(1<<k);j++)
		{
			for(l=1;l<=k;l++)
			{
				if(j&(1<<(l-1)))
				{
					dp[i][j][l]=min(dp[i-1][j][l],dp[i-1][j^(1<<(l-1))][0])+cost[l][i];
				}
				dp[i][j][0]=min(dp[i][j][0],dp[i][j][l]);
			}
		}
	}
	ans=MAXINT;
	for(i=1;i<(1<<k);i++)
		ans=min(ans,dp[n][i][0]);
	printf("%d\n",ans);
	return 0;
}