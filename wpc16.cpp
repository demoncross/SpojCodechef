#include<cstdlib>
#include<cstdio>
#define mod 1000000007
using namespace std;
typedef long long int ll;
ll dp[105][105];
struct as
{
	ll s,e;
}a[105];
int main()
{
	ll t,n,m,i,j,k;
	scanf("%lld",&t);
	while(t--)
	{
		for(i=0;i<102;i++)
		{
			for(j=0;j<102;j++)	dp[i][j]=0;
		}
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=m;i++)	scanf("%lld%lld",&a[i].s,&a[i].e);
		for(i=a[1].s;i<=a[1].e;i++)	dp[1][i]=1;
		for(i=2;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				for(k=a[i].s;k<=a[i].e;k++)
				{
					if(k>j) break;
					dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
				}
			}
		}
		printf("%lld\n",dp[m][n]);
	}
	return 0;
}