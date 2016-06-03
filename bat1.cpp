#include<cstdio>
using namespace std;
int cost[21][21],rating[21][21],start[21],dp[21][1003],ans[21][1003];
int main()
{
	int test,i,j,max,q,n,k,m,budget,x;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=n;i++)	scanf("%d",&start[i]);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				scanf("%d",&cost[i][j]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				scanf("%d",&rating[i][j]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=k;j++)
			{
				max=0;
				for(x=1;x<=m;x++)
				{
					if(j<cost[i][x])	continue;
					q=dp[i][j-cost[i][x]]+rating[i][x];
					if(q>max)	max=q;
				}
				dp[i][j]=max;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=k;j++)
			{
				max=ans[i-1][j];
				for(x=start[i];x<=j;x++)
				{
					q=ans[i][j-x]+dp[i][x-start[i]];
					if(q>max)	max=q;
				}
				ans[i][j]=max;
			}
		}
		printf("%d\n",ans[n][k]);
	}
	return 0;
}