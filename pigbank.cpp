#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
int dp[10004];
int main()
{
	int t,x,y,w,m,i,n;
	vector < pair<int,int> > list;
	scanf("%d",&t);
	while(t--)
	{
		list.clear();
		scanf("%d%d",&x,&y);
		m=y-x;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			list.push_back(make_pair(y,x));
		}
		sort(list.begin(),list.end());
		dp[0]=0;
		for(w=1;w<=m;w++)
		{
			dp[w]=1000000000;
			for(i=0;i<list.size() && list[i].first<=w ; i++)
			{
				dp[w]=min(dp[w],dp[w-list[i].first]+list[i].second);
			}
		}
		if(dp[m]==1000000000)	printf("This is impossible.\n");
		else					printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
	}
	return 0;
}