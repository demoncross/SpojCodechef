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
#define sqr(x) (x*x)

using namespace std;
typedef long long int ll;

ll a[200001],dp[2000001],s[2000001];

double intersect(int i,int j)
{
	return ((double)(dp[s[j]]-dp[s[i]]+sqr(a[s[j]+1])-sqr(a[s[i]+1])))/(2*(a[s[j]+1]-a[s[i]+1]));
}

int main()
{
	ll n,left,right,mid,r,ans,i,p;
	scanf("%lld%lld",&n,&p);
	for(i=1;i<=n;i++)	scanf("%lld",&a[i]);
	a[0]=a[1];
	dp[0]=0;
	r=0;
	s[r++]=0;
	for(i=1;i<=n;i++)
	{
		left=1;
		right=r-1;
		ans=0;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(intersect(mid,mid-1)<=a[i])	{ans=mid;left=mid+1;}
			else							right=mid-1;
		}
		dp[i]=dp[s[ans]]+p+sqr(((ll)a[i]-a[s[ans]+1]));
		s[r]=i;
		while(r>=2)
		{
			if(intersect(r-2,r-1)>intersect(r-2,r))
				{swap(s[r],s[r-1]);r--;}
			else
				break;
		}
		r++;
	}
	//for(i=0;i<=n;i++)	cout<<dp[i]<<endl;
	printf("%lld\n",dp[n]);
	return 0;
}
