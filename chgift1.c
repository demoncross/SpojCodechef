#include<stdio.h>
int main()
{
int a[20];
int dp[20];
int test,n,i,c;
scanf("%d",&test);
while(test--)
{
	scanf(" %d",&n);
	for(i=0;i<n;i++)	scanf(" %d",&a[i]);
	dp[0]=a[0];
	for(i=1;i<n;i++)
	{
		dp[i]=dp[i-1]+a[i];
		c=dp[i-1]-a[i];
		if(dp[i]>c)
			dp[i]=c;
		c=dp[i-1]*a[i];
		if(dp[i]>c)
			dp[i]=c;
	}
	printf("%d\n",dp[n-1]);
}
return 0;
}
