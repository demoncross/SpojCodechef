#include<stdio.h>
#define max 10005
typedef long long int ll;
ll dp[max][2];
int a[max];
int main()
{
int test,i,j,n;
scanf("%d",&test);
j=1;
while(test--)
{
	scanf(" %d",&n);
	for(i=0;i<n;i++)
		scanf(" %d",&a[i]);
	dp[0][0]=0;
	dp[0][1]=a[0];
	for(i=1;i<n;i++)
	{
		if(dp[i-1][0]>dp[i-1][1])
			dp[i][0]=dp[i-1][0];
		else 
			dp[i][0]=dp[i-1][1];
		dp[i][1]=dp[i-1][0]+a[i];
	}
	if(dp[i-1][0]>dp[i-1][1])
		printf("Case %d: %lld\n",j,dp[i-1][0]);
	else
		printf("Case %d: %lld\n",j,dp[i-1][1]);
	j++;	
}
return 0;
}