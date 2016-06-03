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

ll power(ll a,ll b)
{
	if(b==0)	return 1;
	ll ans=power(a,b>>1);
	ans=(ans*ans)%MOD;
	if(b&1)	ans=(ans*a)%MOD;
	return ans;
}

int main()
{
	ll test,n,ans;
	cin>>test;
	while(test--)
	{
		cin>>n;
		ans=power(2,(n+3)>>1);
		ans=ans+MOD-2;
		ans=ans%MOD;
		if(n%2==0)
		ans=(ans+power(2,n>>1))%MOD;
		cout<<ans<<endl;
	}
	return 0;
}