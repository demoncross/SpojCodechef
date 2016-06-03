#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;
typedef unsigned long long int ll;

ll a[100005],sum[100005],dp[100005];

int main()
{
	ll i,n,k,j,q;
	scanf("%lld%lld",&n,&k);
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		q=0;
		for(j=1;j<=k;j++)
		{
			if(j>i)	break;
			q=max(q,dp[i-j-1]+sum[i]-sum[i-j]);
		}
		dp[i]=q;
	}
	//for(i=0;i<=n;i++)	printf("%lld ",dp[i]);
	printf("%lld\n",dp[n]);
	return 0;
}