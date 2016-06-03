#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b)
{
	if(b==0)	return a;
	return (gcd(b,a%b));	
}
ll lcm(ll a,ll b)
{
	ll t,g;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	g=gcd(a,b);
	return ((a*b)/g);
}
int main()
{
	ll i,j,ans,n,k,l,c,a[25];
	scanf("%lld%lld",&n,&k);
	for(i=1;i<=k;i++)	scanf("%lld",&a[i]);
	l=1;
	ans=n;
	for(i=1;i<(1<<k);i++)
	{
		c=0;
		l=1;
		for(j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				l=lcm(l,a[j]);
				c++;
			}
		}
		if(c%2)
			ans-=(n/l);
		else
			ans+=(n/l);
	}
	printf("%lld",ans);
	return 0;
}