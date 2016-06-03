#include<stdio.h>
float dp[10004][102];
int a[102];
float p[102];
int main()
{
int t,i,j,sum,n;
float ans;
scanf("%d",&t);
while(t--)
{
	ans=0;
	sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)	{scanf("%d",&a[i]);sum+=a[i];}
	for(i=1;i<=n;i++)	{scanf("%f",&p[i]);	p[i]/=100;}
	for(i=0;i<=sum;i++)
	{
		for(j=0;j<102;j++)	dp[i][j]=0;
	}
	dp[0][0]=1;
	dp[a[1]][1]=p[1];
	dp[0][1]=1-p[1];
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=sum;j++)
		{
			if(j-a[i]<0)	dp[j][i]=0;
			else		dp[j][i]=dp[j-a[i]][i-1]*p[i];
			dp[j][i]+=dp[j][i-1]*(1-p[i]);
		}
	}
	for(i=(sum+1)/2;i<=sum;i++)
		ans+=dp[i][n];
	printf("%f\n",ans);
}
return 0;
}
