#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll dp[100000],a[100000];
ll max(ll a,ll b)
{
	return a>b?a:b;
}
int main()
{
	ll i,ans,test,n,k;
	scanf("%lld",&test);
	while(test--)
	{
		ans=-1;
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		dp[0]=max(a[0],0);
		for(i=1;i<k+1;i++)
		{	
			dp[i]=max(max(a[i],dp[i-1]),0);
			//if(dp[i]>ans)	ans=dp[i];
		}
		for(;i<n;i++)
		{
			dp[i]=max(max(dp[i-1],a[i]+dp[i-k-1]),0);
		}
		printf("%lld\n",dp[n-1]);
	}
	return 0;
}