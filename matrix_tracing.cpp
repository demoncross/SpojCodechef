//https://www.hackerrank.com/contests/codesprint5/challenges/matrix-tracing
//inverse modulo , fermats little theorem, combinatorics
#include<cstdio>
#include<cstdlib>
#define mod (1000000007)
typedef long long int ll;
ll f[2000005];
using namespace std;
ll power(ll x,ll p)
{
	if(p==0)	return 1;
	ll ans=power(x,p>>1);
	ans=(ans*ans)%mod;
	//ans=(ans+mod)%mod;
	if(p&1)
	{
		ans=(ans*x)%mod;
	}
	//ans=(ans+mod)%mod;
	return ans;
}
ll inverse(ll x)
{
	//x=(x+mod)%mod;
	return (power(x,mod-2));
}
int main()
{
	ll i,t,n,m,ans;
	f[0]=1;
	for(i=1;i<=2000000;i++)	f[i]=(f[i-1]*i)%mod;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		ans=f[n+m-2];
		ans=(ans*inverse(f[n-1]))%mod;
	//	ans=(ans+mod)%mod;
		ans=(ans*inverse(f[m-1]))%mod;
	//	ans=(ans+mod)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}