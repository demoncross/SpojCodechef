# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <queue>
# include <cmath>
# include <cstring>
# include <iostream>
# include <stack>
# include <map>
# include <vector>
# include <utility>
# include <set>
# include <deque>

# define MOD (1000000007)
# define MAXINT 1e9

using namespace std;
typedef long long int ll;

int dp[102][102];
int wt[102],sum[102];

int main()
{
	int n,t,i,j,l,start,end,n1,n2,w1,w2,q,ans;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)	scanf("%d",&wt[i]);
	sum[0]=0;
	for(i=1;i<=n;i++)	sum[i]=sum[i-1]+wt[i];
	for(l=1;l<=n;l++)
	{
		for(start=1;start<=n-l+1;start++)
		{
			end=start+l-1;
			dp[start][end]=MAXINT;
			if(l==1)	dp[start][end]=0;
			else
			{
				for(i=start;i<=end-1;i++)
				{
					q=dp[start][i]+dp[i+1][end];
					n1=i-start+1;
					n2=end-i;
					w1=sum[i]-sum[start-1];
					w2=sum[end]-sum[i];
					q+=(w1*n1)+(w2*n2);
					dp[start][end]=min(dp[start][end],q);
				}
			}
		}
	}
	ans=dp[1][n];
	if(ans>t)
	{
		int f=(ans-t);
		if(f%(n-1)==0)
			ans=f/(n-1);
		else
			ans=(f/(n-1))+1;
	}
	else
		ans=0;
	printf("%d\n",ans);
	return 0;
}