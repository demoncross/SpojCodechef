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
#define mod 1000000007

using namespace std;
typedef long long int ll;

typedef struct xxx
{
	ll x,y,z;
}xx;

xx a [10000];

ll gcd(ll x,ll y)
{
	if(x<y){
		ll t=x;
		x=y;
		y=t;}
	if(y==0)	return x;
	//printf(".");
	return gcd(y,x%y);
}

int main()
{
	ll n,test,x,y,z,h,l,w,ans,q,i;
	scanf("%lld",&n);
	while(n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			a[i].x=x;
			a[i].y=y;
			a[i].z=z;
			if(i==0)
			{
				h=x;l=y;w=z;continue;
			}
			h=gcd(h,x);
			l=gcd(l,y);
			w=gcd(w,z);
		}
		//for(i=0;i<=1000000;i++)	;
		//printf("%lld%lld%lld\n",h,l,w);
		ans=0;
		for(i=0;i<n;i++)
		{
			q=(a[i].x/h)*(a[i].y/l)*(a[i].z/w);
			ans+=q;
		}
		q=gcd(h,gcd(l,w));
		ans=(ans*(h/q)*(l/q)*(w/q));
		printf("%lld\n",ans);
		scanf("%lld",&n);
	}
	return 0;
}