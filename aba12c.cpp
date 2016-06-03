#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#define mod 1000000007

using namespace std;
typedef long long int ll;
int a[1000];
int dp[1001][1001];

int main()
{
	int test,i,n,k,l,j;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=k;i++)	scanf("%d",&a[i]);
		dp[0][0]=0;
		for(i=1;i<=k;i++)	dp[0][i]=10000000;
		for(i=1;i<=n;i++)
		{
			dp[i][0]=0;
			for(j=1;j<=k;j++)
			{
				dp[i][j]=10000000;
				for(l=1;l<=j;l++)
				{
					if(a[l]==-1)	continue;
					dp[i][j]=min(dp[i][j],dp[i-1][j-l]+a[l]);
				}
			}
		}
		if(dp[n][k]>=10000000)	printf("-1\n");
		else					printf("%d\n",dp[n][k]);
	}
	return 0;
}