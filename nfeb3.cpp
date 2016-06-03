#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int map[505][505];
int dp[505][505];
int main()
{
	int test,n,m,p,i,j,ans;
	scanf("%d",&test);
	while(test--)
	{
		ans=-100;
		scanf("%d%d%d",&n,&m,&p);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)	scanf("%d",&map[i][j]);
		}
		for(i=0;i<=500;i++)
			dp[i][0]=dp[0][i]=dp[i][m+1]=-1000;
		for(i=1;i<=m;i++)
		{
			dp[1][i]=p-map[1][i];
			dp[1][i]=(dp[1][i]>100?100:dp[1][i]);
		}
		for(i=2;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				dp[i][j]=-1;
				if(dp[i-1][j-1]>=0)	dp[i][j]=dp[i-1][j-1];
				if(dp[i-1][j+1]>=0)	dp[i][j]=max(dp[i-1][j+1],dp[i][j]);
				if(dp[i][j]>=0)
					dp[i][j]-=map[i][j];
				dp[i][j]=(dp[i][j]>100?100:dp[i][j]);
			}
		}
		for(i=1;i<=m;i++)
			ans=max(ans,dp[n][i]);
		if(ans<0)	printf("-1\n");
		else		printf("%d\n",ans);
	}
	return 0;
}