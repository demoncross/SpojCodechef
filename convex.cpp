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
#define EPS (1e-9)
#define mp   make_pair
#define pb   push_back
#define pii  pair<int,int> 

using namespace std;
typedef long long int ll;

ll a[100000],b[1000000],dp[1000000],s[1000000];

double intersect(int i,int j)
{
	return ((double)(dp[s[j]]-dp[s[i]]))/(b[s[i]]-b[s[j]]);
}

int main()
{
	ll n,left,right,mid,r,ans,i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)	scanf("%lld",&a[i]);
	for(i=0;i<n;i++)	scanf("%lld",&b[i]);
	dp[0]=0;
	r=0;
	s[r]=0;
	r++;
	ans=0;
	for(i=1;i<n;i++)
	{
		for(;ans<r-1;ans++)
		{
			if(intersect(ans,ans+1)>a[i])	break;
		}
		dp[i]=dp[s[ans]]+((ll)a[i]*b[s[ans]]);
		s[r]=i;
		while(r>=2)
		{
			if(intersect(r-1,r-2)>intersect(r-2,r))
				{swap(s[r-1],s[r]);r--;}
			else
				break;
		}
		ans=min(ans,r);
		r++;
	}
	printf("%lld\n",dp[n-1]);
	return 0;
}
