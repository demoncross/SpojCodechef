//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=553&page=show_problem&problem=4379

#include <cstdio>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
ll dp[1005];
int main()
{
	int rem,i,j,c=1,n;
	dp[0]=0;
	dp[1]=1;
	for(i=2;i<=1000;i++)
	{
		dp[i]=0;
		rem=i-1;
		for(j=1;j<=rem;j++)
		{
			if(rem%j==0)
			{
				dp[i]=(dp[i]+dp[rem/j])%MOD;
			}
		}
	}
	while(~scanf("%d",&n))
	{
		printf("Case #%d: %lld\n",c,dp[n]);
		c++;
	}
	return 0;
}