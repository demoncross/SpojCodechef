#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
int dp[100001][3];
vector < vector <int> > adj_list(100001);
int work(int node,int f)
{
	int i,ans,q;
	if(dp[node][f]!=-1)	return dp[node][f];
	if(f==1)
	{
		ans=1;
		for(i=0;i<adj_list[node].size();i++)
		{
			q=adj_list[node][i];
			if(dp[node][2]!=q)
			{
				dp[q][2]=node;
				ans+=min(work(q,1),work(q,0));
			}
		}
	}
	else
	{
		ans=0;
		for(i=0;i<adj_list[node].size();i++)
		{
			q=adj_list[node][i];
			if(dp[node][2]!=q)
			{
				dp[q][2]=node;
				ans+=work(q,1);
			}
		}
	}
	dp[node][f]=ans;
	return ans;
}
int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	for(i=0;i<=100000;i++)	dp[i][0]=dp[i][1]=dp[i][2]=-1;
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}
	x=min(work(1,0),work(1,1));
	printf("%d\n",x);
	return 0;
}