#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define mod 10000

using namespace std;
typedef long long ll;

pair<ll,ll> a[100000];

int main()
{
	ll i,j,n,l,r,u,q,start,end,no,add,ans;
	scanf("%lld%lld%lld",&n,&u,&q);
	for(i=0;i<u;i++)	scanf("%lld%lld",&a[i].first,&a[i].second);
	for(i=0;i<q;i++)
	{
		ans=0;
		scanf("%lld%lld",&l,&r);
		for(j=0;j<u;j++)
		{
			if(r<a[j].first || l>a[j].second)	continue;
			if(l<a[j].first)
				start=a[j].first;
			else
				start=l;
			if(r>a[j].second)
				end=a[j].second;
			else
				end=r;
			no=end-start+1;
			add=(no*(no+1))>>1;
			if(start==l)
			{
				add=(add+no*(l-a[j].first))%mod;
			}
			ans=(ans+add)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 