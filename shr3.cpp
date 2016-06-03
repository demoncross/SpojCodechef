#include <cstdio>
#include <cstdlib>
#include <cmath>
#define MOD 1000000007
typedef long long int ll;
ll power(ll a,ll b)
{
	if(b==1)	return a;
	ll q=power(a,b/2);
	q=(q*q)%MOD;
	if(b&1)	q=(q*a)%MOD;
	return q;
}
using namespace std;
int main()
{
	int test,n,x,i,max;
	ll ans;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			max=max|x;
		}
		//no=log2(max);
		//q=((1<<ceil(no))-1);
		ans=power(2,n-1);
		ans=(ans*max)%MOD;
		printf("%lld\n",ans);
		//printf("%f",no);
	}
	return 0;
}