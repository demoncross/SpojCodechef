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
#define EPS 1e-9
#define mod 1000000007

using namespace std;
typedef long long int ll;
ll a[1000000],sum[1000000];

ll power(ll ar,ll b)
{
	if(b==0)	return 1;
	ll x=power(ar,b>>1);
	x=x*x;
	if(b&1)	x=x*ar;
	return x;
}

int main()
{
	ll test,n,q,i,j,z,root,ans,x,y,w;
	scanf("%lld",&test);
	while(test--)
	{
		scanf("%lld%lld",&n,&q);
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]%=mod;
			while(a[i]<0)	a[i]+=mod;
			sum[i]=sum[i-1]+a[i];
			sum[i]%=mod;
		}
		for(i=1;i<=q;i++)
		{
			scanf("%lld",&z);
			j=2;
			ans=((z%mod)*a[1])%mod;
			while(j<=n)
			{
				root=(ll)pow((double)z,1.0/(double)j);
				if(pow((double)((double)root+1),(double)j)+EPS<=(double)z)	root++;
				if(root==1)	break;
				ll t=((root%mod)*a[j]);
				t=t%mod;
				ans=(ans+t);
				ans=ans%mod;
				j++;
			}
			ans=(ans+sum[n]-sum[j-1]);
			while(ans<0)	ans=ans+mod;
			ans=(ans%mod);
			printf("%lld ",ans);
		}
		printf("\n");
	}
	return 0;
}