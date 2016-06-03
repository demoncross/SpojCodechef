#include<cstdio>
#include<cstdlib>
#include<algorithm>
typedef long long int ll;
using namespace std;
ll dp[60],a[60];
int main()
{
	ll t,n,k,i,j,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&k,&n);
		dp[0]=1;
		ans=0;
		a[0]=0;
		for(i=1;i<=n;i++)	
		{
			scanf("%lld",&a[i]);
			dp[i]=0;
		}
		for(i=0;i<=n;i++)
		{
			if(a[i])	continue;
			for(j=0;j<k;j++)
			{
				if(i+j+1<=n)
				dp[i+j+1]+=dp[i];
				else
				{
					ans+=dp[i];
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}