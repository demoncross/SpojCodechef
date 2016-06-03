#include<cstdio>
#include<cstdlib>
#define mod 98765431
typedef long long int ll;
using namespace std;
ll n,m[2]={0,1};
ll ans[2]={1,0};
ll a[500005];
void mul(ll a[2],ll b[2])
{
	ll c[2];
	c[0]=((a[0]*b[0])%mod+(a[1]*b[1]*(n-1))%mod)%mod;
	c[1]=((a[0]*b[1]+a[1]*b[0])%mod+(a[1]*b[1]*(n-2))%mod)%mod;
	ans[0]=c[0];
	ans[1]=c[1];
}
void power(ll p)
{
	if(p==0)	return;
	power(p>>1);
	mul(ans,ans);
	if(p&1)	mul(ans,m);
	return;
}
int main()
{
	ll t,sum,i;
	scanf("%lld%lld",&n,&t);
	sum=0;
	for(i=0;i<n;i++)	
	{
		scanf("%lld",&a[i]);
		sum=sum+a[i];
	}
	power(t);
	for(i=0;i<n;i++)
	{
		a[i]=((((sum-a[i])%mod)*ans[1])%mod+(a[i]*ans[0])%mod)%mod;
	}
	for(i=0;i<n;i++)	printf("%lld\n",a[i]);
	return 0;
}