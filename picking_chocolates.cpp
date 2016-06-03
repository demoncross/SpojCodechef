#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	vector<pair<int,int> >dp;
	vector<int> a;
	int t,n,k,i,j,m,ans,m_f;
	scanf("%d",&t);
	while(t--)
	{
		dp.clear();
		a.clear();
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			a.push_back(m);
		}
		dp.push_back(make_pair(1,1));
		for(i=1;i<n;i++)
		{
			m=-1;
			m_f=0;
			for(j=0;j<i;j++)
			{
				if(a[j]<a[i] && dp[j].first+1>m)
				{
					m=dp[j].first+1;
					m_f=dp[j].second;
				}
				else if(a[j]<a[i] && dp[j].first+1==m)
					m_f+=dp[j].second;
			}
			dp.push_back(make_pair(m,m_f));
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			if(dp[i].first==k)	ans+=dp[i].second;
		}
				printf("%d\n",ans);
	}
	return 0;
}