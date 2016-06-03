#include<stdio.h>
int dp[1002][52];
int time[51][51],toll[51][51];
//int dp[51][51];
int main()
{
int n,t,i,j,k,min_toll,min_time;
while(1)
{
	for(i=0;i<=1001;i++)
	{
		for(j=0;j<=51;j++)
			dp[i][j]=-1;
	}
	scanf(" %d %d",&n,&t);
	if(n==0 && t==0)	break;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)	scanf(" %d",&time[i][j]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)	scanf(" %d",&toll[i][j]);
	}
	dp[0][1]=0;
	for(i=1;i<=n;i++)
	{
		if(time[1][i]<=t)
		dp[0+time[1][i]][i]=toll[1][i];
	}	
	min_toll=10000000;
	for(j=2;j<=n-1;j++)
	{
		for(i=0;i<=t;i++)
		{
			if(dp[i][j]==-1)	continue;
			for(k=1;k<=n;k++)
			{
				if(i+time[j][k]<=t){
				if(dp[i+time[j][k]][k]==-1 || dp[i+time[j][k]][k]>dp[i][j]+toll[j][k])
					dp[i+time[j][k]][k]=dp[i][j]+toll[j][k];
				}
			}
		}
	}
	for(i=0;i<=t;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(dp[i][j]==-1) continue;
			if(i+time[j][n]>t)	continue;
			else if(dp[i][j]+toll[j][n]<min_toll){
				min_toll=dp[i][j]+toll[j][n];
				min_time=i+time[j][n];}
		}
	}
	printf("%d %d\n",min_toll,min_time);
}
return 0;
}
