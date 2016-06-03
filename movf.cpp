#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int dp[505][1005][4];
int a[505];
int main()
{
	int test,n,sum,i,k,l,j;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&sum);
		for(i=0;i<n;i++)	scanf(" %*[^\n] %d",&a[i]);
		sort(a,a+n);
		for(i=0;i<=n;i++)	dp[i][0][0]=1;
		for(i=1;i<=n;i++)
		{
			for(k=0;k<=sum;k++)
			{
				for(l=1;l<=3;l++)
				{
					dp[i][k][l]=dp[i-1][k][l];
					if(a[i-1]<=k)
						dp[i][k][l]+=dp[i-1][k-a[i-1]][l-1];
				}
			}
		}
		printf("%d\n",dp[n][sum][3]);
	}
	return 0;
} 