#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <utility>
#include <set>

#define MOD (1000000007)
#define MAXINT 1e9

using namespace std;
typedef long long int ll;

ll m[2][2]={1,1,1,0};
ll ans[2][2]={1,0,0,1};
ll p;

void mull(ll a[][2],ll b[][2])
{
	ll x[2][2],i,j,k;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			x[i][j]=0;
			for(k=0;k<2;k++)
				x[i][j]=(x[i][j]+a[i][k]*b[k][j])%p;
		}
	}
	for(i=0;i<2;i++)	for(j=0;j<2;j++)	ans[i][j]=x[i][j];
}

void get_fibonacci(ll n)
{
	if(n<=0)	return;
	get_fibonacci(n>>1);
	mull(ans,ans);
	if(n&1)	mull(ans,m);
}

ll power(ll x,ll y)
{
	if(y<=0)	return 1;
	ll an=power(x,y>>1);
	an=(an*an)%p;
	if(y&1)	an=(an*x)%p;
	return an;
}

int main()
{
	ll test,a,b,n,i,f_a,f_b,xx,yy;
	scanf("%lld",&test);
	for(i=1;i<=test;i++)
	{
		ans[0][0]=ans[1][1]=1;ans[0][1]=ans[1][0]=0;
		scanf("%lld%lld%lld%lld",&a,&b,&p,&n);
		printf("Case #%lld: ",i);
		if(n==1)
			printf("%lld\n",a%p);
		else if(n==2)
			printf("%lld\n",b%p);
		else
		{
			get_fibonacci(n-3);
			f_b=(ans[0][0]+ans[0][1])%p;
			f_a=(ans[1][0]+ans[1][1])%p;
			xx=power(b,f_b);
			yy=power(a,f_a);
			printf("%lld\n",(xx*yy)%p);
		}
	}
	return 0;
}