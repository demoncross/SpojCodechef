#include<stdio.h>
int main()
{
int i,j,l,k,q,n,test;
long long int min;
int dp[100][100];
int sum[101]={0};
int a[100];
while(scanf(" %d",&n)!=EOF)
{
	for(i=0;i<n;i++)	scanf(" %d",&a[i]);
	for(i=0;i<n;i++)	dp[i][i]=0;
	for(i=0;i<n;i++)	sum[i+1]=sum[i]+a[i];
	for(l=2;l<=n;l++)
	{
		for(i=0;i<=n-l;i++)
		{
			min=10000000000;
			for(k=i;k<i+l-1;k++)
			{
				q=dp[i][k]+dp[k+1][i+l-1]+(((sum[k+1]-sum[i])%100)*((sum[i+l]-sum[k+1])%100));
				if(q<min)
					min=q;
			}
			dp[i][i+l-1]=min;
		}
	}
printf("%d\n",dp[0][n-1]);
}
return 0;
}
