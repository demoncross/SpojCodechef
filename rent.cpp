#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm> 

using namespace std;

long long int dp[10004];
vector < pair < pair <int,int> ,int > > v;
int ans;

long long int max(long long int a,long long int b)
{
	return(a>b?a:b);
}

void bi_search(int s,int e,long long int q)
{
	int m;
	while(s<e)
	{
		m=(s+e)>>1;
		if(v[m].first.first<=q && v[m+1].first.first>=q)	
		{
			ans=m;
			s=m+1;
		}
		else if(v[m].first.first>q)	
			e=m;
		else
			s=m+1;
	}
}

int main()
{
	long long int ma;
	int i,s,d,p,test,j,n;
	scanf("%d",&test);
	while(test--)
	{
		v.clear();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&s,&d,&p);
			v.push_back(make_pair(make_pair(s+d,s),p));
		}
		sort(v.begin(),v.end());
		ma=dp[0]=v[0].second;
		for(i=1;i<v.size();i++)
		{
			ans=-1;
			bi_search(0,i,v[i].first.second);
			if(ans==-1)	dp[i]=max(dp[i-1],v[i].second);
			else		dp[i]=max(dp[i-1],dp[ans]+v[i].second);
			if(dp[i]>ma)	ma=dp[i];
		}
		printf("%lld\n",ma);
	}
	return 0;
}