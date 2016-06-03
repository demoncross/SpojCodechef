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

#define MOD (1000000009)
#define MAXINT 1e9

using namespace std;
typedef long long int ll;

typedef struct xx
{
int a,b,c,d;
}ss;

map< pair<pair<int,int>,pair<int,int> >,int> dp;

int work(pair<pair<int,int>,pair<int,int> > x)
{
	if(dp.find(x)!=dp.end())	return dp[x];
	if(x.second.second==0)
		return max(x.first.first,max(x.first.second,x.second.first));
	int a[4];
	int k=x.second.first;
	pair<pair<int,int>,pair<int,int> > y;
	a[0]=x.first.first/2;a[1]=x.first.second+1;a[2]=x.second.first+1;
	sort(a,a+3);
	y=make_pair(make_pair(a[0],a[1]),make_pair(a[2],x.second.second-1));
	k=min(k,work(y));
	a[0]=x.first.first+1;a[1]=x.first.second/2;a[2]=x.second.first+1;
	sort(a,a+3);
	y=make_pair(make_pair(a[0],a[1]),make_pair(a[2],x.second.second-1));
	k=min(k,work(y));
	a[0]=x.first.first+1;a[1]=x.first.second+1;a[2]=x.second.first/2;
	sort(a,a+3);
	y=make_pair(make_pair(a[0],a[1]),make_pair(a[2],x.second.second-1));
	k=min(k,work(y));
	dp[x]=k;
	return k;
}

int main()
{
	int test,x,y,z,rr,gg,bb,r,g,b,m,i;
	cin>>test;
	while(test--)
	{
		dp.clear();
		gg=bb=rr=-1;
		cin>>r>>g>>b>>m;
		for(i=0;i<r;i++)
		{
			cin>>x;
			rr=max(rr,x);
		}
		for(i=0;i<g;i++)
		{
			cin>>x;
			gg=max(gg,x);
		}
		for(i=0;i<b;i++)
		{
			cin>>x;
			bb=max(bb,x);
		}
		int a[4];
		a[0]=rr;a[1]=gg;a[2]=bb;
		sort(a,a+3);
		pair<pair<int,int> , pair<int,int> > s;
		s=make_pair(make_pair(a[0],a[1]),make_pair(a[2],m));
		cout<<work(s)<<endl;
	}
	return 0;
}