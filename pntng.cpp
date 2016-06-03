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


vector<pair<ll,ll> > a;

int main()
{
	ll n,m,h,cost,needed,i,t,c;
	scanf("%lld%lld%lld",&n,&m,&h);
	for(i=1;i<=h;i++)
	{
		scanf("%lld%lld",&t,&c);
		a.push_back(make_pair(c,t));
	}
	sort(a.begin(),a.end());
	needed=n*m;
	cost=0;
	for(i=0;i<h;i++)
	{
		if(a[i].second>needed){
			cost+=(a[i].first*needed);
			needed=0;
			break;}
		else
		cost+=(a[i].first*a[i].second);
		needed-=a[i].second;
	}
	if(needed)	printf("Impossible\n");
	else		printf("%lld\n",cost);
	return 0;
}