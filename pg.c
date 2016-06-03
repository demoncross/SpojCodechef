
#include<stdio.h>
#include<string.h>
int dp[102][102][2];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<102;i++)
		{
			for(j=0;j<102;j++)
				dp[i][j][0]=dp[i][j][1]=0;
		}
		scanf("%d%d",&n,&m);
		scanf("%s",s);
		if(s[0]=='W')
		{
			dp[0][1][0]=1;
			dp[0][1][1]=0;
			dp[0][101][0idiy]
		}
		else
		{
			dp[0][1][1]=1;
			dp[0][1][0]=0;
		}
		dp[0][101][0]=1;
		for(i=1;i<n;i++)
		{
			for(j=1;j<=m;j++)
			{

			}
		}
	}
	return 0;
}