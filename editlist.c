#include<stdio.h>
int dp[105][105];
int a[105];
int b[105];
int min(int a,int b,int c)
{
if(a<=b && a<=c)	return a;
else if(b<=a && b<=c)	return b;
else			return c;
}
int main()
{
int t,i,j,m,n;
scanf("%d",&t);
while(t--)
{
	scanf("%d",&n);
	dp[0][0]=0;
	for(i=1;i<=n;i++)	{dp[i][0]=i;scanf("%d",&a[i]);}
	scanf("%d",&m);
	for(i=1;i<=m;i++)	{dp[0][i]=i;scanf("%d",&b[i]);}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])	dp[i][j]=dp[i-1][j-1];
			else		dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
		}
	}
	printf("%d\n",dp[n][m]);
}
return 0;
}
