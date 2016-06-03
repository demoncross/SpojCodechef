# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <queue>
# include <cmath>
# include <cstring>
# include <iostream>
# include <stack>
# include <map>
# include <vector>
# include <utility>
# include <set>
# include <deque>

# define MOD (1000000007)
# define MAXINT 1e9

using namespace std;
typedef long long int ll;

char m[1001][1001];
pair<bool,bool> dp[1001][1001];

int main()
{
	int test,ans,j,n,i;
	cin>>test;
	while(test--)
	{
		ans=0;
		cin>>n;
		for(i=1;i<=n;i++)	
			scanf(" %s",&m[i][1]);
		for(i=n;i>=1;i--)
		{
			for(j=n;j>=1;j--)
			{
				if(m[i][j]=='#')	dp[i][j]=make_pair(0,0);
				else if(i==n && j==n)
					dp[i][j]=make_pair(1,1);
				else if(i==n)
					dp[i][j]=make_pair(1,dp[i][j+1].second);
				else if(j==n)
					dp[i][j]=make_pair(dp[i+1][j].first,1);
				else
					dp[i][j]=make_pair(dp[i+1][j].first,dp[i][j+1].second);
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)	if(dp[i][j].first && dp[i][j].second)	ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}