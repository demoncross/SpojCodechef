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

int a[1000006],b[1000006];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)	scanf("%d%d",&a[i],&b[i]);
	if(b[1]==1)
	{
		dp[1][0]=a[1];
		dp[1][1]=-1;
	}
	else
	{
		dp[1][0]=-1;
		dp[1][1]=
	}
	return 0;
}