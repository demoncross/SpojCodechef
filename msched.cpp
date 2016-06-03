#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

vector <pair<int,int> > v;
int dp[100005];

int main()
{
	int n,i,x,y,last;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		v.push_back(make_pair(y,x));
	}
	sort(v.begin(),v.end());
	dp[0]=v[0].second;
	last=-1;
	for(i=1;i<n;i++)
	{
		if(v[i].first!=v[i-1].first)
			last=i-1;
		dp[i]=dp[i-1];
		if(last==-1)
			dp[i]=max(dp[i],v[i].second);
		else 
			dp[i]=max(dp[i],dp[last]+v[i].second);
	}
	for(i=0;i<n;i++)	printf("%3d %3d %3d\n",v[i].second,v[i].first,dp[i]);
	printf("%d\n",dp[n-1]);
	return 0;
}