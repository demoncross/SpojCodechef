#include<stdio.h>
int dp[2][2000005];
int v[505],w[505];
int max(int a,int b)
{
	return (a>b?a:b);
}
int main()
{
int i,j,k,n,t,u,s;
scanf("%d%d",&k,&n);
for(i=1;i<=n;i++)	scanf("%d%d",&v[i],&w[i]);
for(i=0;i<2000005;i++)	dp[0][i]=0;
dp[0][1]=0;
t=1,u=0;
for(i=1;i<=n;i++)
{
	for(j=1;j<=k;j++)
	{
		if(j>=w[i])
			dp[t][j]=max(dp[u][j-w[i]]+v[i],dp[u][j]);
		else
			dp[t][j]=dp[u][j];
	}
	s=t;
	t=u;
	u=s;
}
printf("%d\n",dp[u][k]);
return 0;
}
