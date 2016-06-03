#include<cstdio>
#include<cmath>
#include<algorithm>
#define mod (1000000007)
using namespace std;
typedef long long int ll;
ll max(ll a,ll b)
{
	return (a>b?a:b);
}
ll power(ll n)
{
	if(n==0)	return 1;
	ll a=power(n/2);
	a=(a*a)%mod;
	if(n&1)
		a=(a*3)%mod;
	return a;
}
int main()
{
	ll t,n,x,a,b;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==1)	printf("1\n");
		else if(n==2)	printf("2\n");
		else
		{
			x=n/3;
			if(n%3==0)
				printf("%lld\n",power(x));
			else if(n%3==1)
				printf("%lld\n",(power(x-1)*4)%mod);
			else
				printf("%lld\n",(power(x)*2)%mod);
		}
	}
	return 0;
}