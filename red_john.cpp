
#include<cstdio>
#include<cstdlib>
using namespace std;
	int dp[50],sum[300000],a[3000000];
int main()
{
	int i,t,n,j;
	for(i=0;i<300000;i++)	a[i]=1;
	for(i=2;i*i<300000;i++)
	{
		if(a[i])
		{
			for(j=2;j*i<300000;j++)
			{
				a[i*j]=0;
			}
		}
	}
	sum[0]=sum[1]=0;
	for(i=2;i<300000;i++)
	{
		sum[i]=sum[i-1]+(a[i]?1:0);
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		dp[0]=1;
		for(i=1;i<=n;i++)
		{
			if(i>=4)
				dp[i]=dp[i-1]+dp[i-4];
			else
				dp[i]=dp[i-1];
		}
		printf("%d\n",sum[dp[n]]);
	}
	return 0;
}