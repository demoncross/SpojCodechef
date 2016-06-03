#include<stdio.h>
int dp[105][105][2]={0};
int main()
{
int i,j,n,k,test;
dp[1][0][0]=dp[1][0][1]=1;
dp[2][0][0]=2;
dp[2][0][1]=1;
dp[2][1][0]=0;
dp[2][1][1]=1;
for(i=3;i<=103;i++)
{
	for(j=0;j<=i-1;j++)
	{
		dp[i][j][0]=dp[i-2][j][0]+dp[i-2][j][1]+dp[i-2][j][0]+dp[i-2][j-1][1];
		dp[i][j][1]=dp[i-2][j][0]+dp[i-2][j][1]+dp[i-2][j-1][0]+dp[i-2][j-2][1];
	}
}
scanf("%d",&test);
for(i=1;i<=test;i++)
{
	scanf("%*d %d %d",&n,&k);
	printf("%d %d\n",i,dp[n][k][0]+dp[n][k][1]);
}
return 0;
}
