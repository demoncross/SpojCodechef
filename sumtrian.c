#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
	return (a>b?a:b);
}
int dp[101][101];
int main()
{
int i,j,n,m,test,a,b;
scanf("%d",&test);
while(test--)
{
	m=-1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)	scanf(" %d",&dp[i][j]);
	}
	for(i=2;i<=n;i++)
	{
		dp[i][1]+=dp[i-1][1];
		for(j=2;j<=i-1;j++)
		{
			a=dp[i-1][j-1]+dp[i][j];
			b=dp[i-1][j]  +dp[i][j];
			dp[i][j]=min(a,b);
		}
		dp[i][i]+=dp[i-1][i-1];
	}
	for(i=1;i<=n;i++)
	{
		if(dp[n][i]>m)	m=dp[n][i];
	}
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)	printf("%d ",dp[i][j]);
		printf("\n");
	}*/
	printf("%d\n",m);
}
return 0;
}
