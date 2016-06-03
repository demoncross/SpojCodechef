#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[105],dp[104][1000005];
int main()
{
	int test,sum,q,q2,i,n,g,j;
	scanf("%d",&test);
	while(test--)
	{
		sum=0;
		scanf("%d%d",&n,&g);
		for(i=0;i<n;i++){
			scanf("%d\n",&a[i+1]);
			sum+=a[i+1];
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=g;j++)
			{
				dp[i][j]=dp[i-1][j];
				if(a[i]<=j)
					dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+a[i]);
			}
			//printf("8");
		}
		q=dp[n][g];
		q2=sum-q;
		if(q2<=g)	printf("YES\n");
		else		printf("NO\n");
	}
	return 0;
}