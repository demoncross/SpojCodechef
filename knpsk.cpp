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

using namespace std;
typedef long long int ll;

bool f(ll x,ll y)
{
	return x>y;
}

typedef struct ss
{
	ll v,p1,p2;
}s;

s dp[1000000];
vector<ll> list[3];

int main()
{
	ll n,x,y,one,two,sum,i,q1,q2;
	scanf("%lld",&n);
	sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&x,&y);
		list[x].push_back(y);
		sum+=x;
	}
	sort(list[1].begin(),list[1].end(),f);
	sort(list[2].begin(),list[2].end(),f);
	dp[0].v=dp[0].p1=dp[0].p2=0;
	dp[1].v=(list[1].size()?list[1][0]:0);
	dp[1].p1=1;
	dp[1].p2=0;
	printf("%lld ",dp[1].v);
	for(i=2;i<=sum;i++)
	{
		q1=dp[i-2].v;
		one=dp[i-2].p1;
		two=dp[i-2].p2;
		if(two<list[2].size())
			q1+=list[2][two];
		q2=dp[i-1].v;
		one=dp[i-1].p1;
		two=dp[i-1].p2;
		if(one<list[1].size())
			q2+=list[1][one];
		if(q1>q2)
		{
			dp[i].v=q1;
			dp[i].p1=dp[i-2].p1;
			dp[i].p2=dp[i-2].p2+1;
		}
		else
		{
			dp[i].v=q2;
			dp[i].p1=dp[i-1].p1+1;
			dp[i].p2=dp[i-1].p2;
		}
		printf("%lld ",dp[i].v);
	}
	printf("\n");
	return 0;
}