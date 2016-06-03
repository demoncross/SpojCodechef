#include <stdio.h>
int dp[3335];
int main()
{
	int test,n,i;
	dp[3]=1;
	dp[4]=1;
	dp[5]=1;
	dp[6]=2;
	dp[7]=1;
	dp[8]=2;
	for(i=9;i<=3333;i++)
	{
		if(dp[i-3]==2||dp[i-4]==2||dp[i-5]==2||dp[i-6]==2)	dp[i]=1;
		else	dp[i]=2;
	}
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n );
		if(dp[n]==1)	printf("Joker\n");
		else			printf("Bane\n");
	}
	return 0;
}