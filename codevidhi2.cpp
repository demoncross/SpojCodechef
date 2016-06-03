#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
ll dp[1002][1002];
int no[1002],sum[1002];
vector<int> list[1001];
int main()
{
	int r,i,j,k,x,y,n,m,roads;
	scanf("%d",&r);
	for(i=1;i<=r;i++)
		scanf("%d",&no[i]);
	sum[1]=no[1];
	for(i=2;i<=r;i++)	sum[i]=sum[i-1]+no[i];
	scanf("%d",&roads);
	for(i=1;i<=roads;i++)
	{
		scanf("%d%d%d%d",&x,&y,&n,&m);
		list[sum[x-1]+y].push_back(m);
	}
	for(i=1;i<=no[r];i++)	dp[r][i]=1;
	for(i=n-1;i>=1;i--)
	{
		for(j=1;j<=no[i];j++)
		{
			for(k=0;k<list[sum[i-1]+j].size();k++)
				dp[i][j]+=dp[i+1][list[sum[i-1]+j][k]];
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",dp[x][y]);
	}
	return 0;
}