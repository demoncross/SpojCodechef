#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int c[1000006];
vector<long long int>v;
int find(int l,int r,int val)
{
	int ans=-1,m;
	while(l<=r)
	{
		m=(l+r)>>1;
		if(v[m]<val)	l=m+1;
		else if(v[m]>val) r=m-1;
		else
		{
			if(c[m]==0)	ans=m;
			l=m+1;
		}		
	}
	return ans;
}
//map<long long int,long long int> m;
int main()
{
	long long int test,q,i,n,x,ans;
	scanf("%lld",&test);
	while(test--)
	{
		//m.clear();
		v.clear();
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			c[i]=0;
			scanf("%lld",&x);
			v.push_back(x);
		}
		ans=0;
		sort(v.begin(),v.end());
		for(i=n-1;i>=0;i--)
		{
			if(c[i])	continue;
			q=find(0,i-1,v[i]>>1);
			if(q!=-1)
			{
				c[i]=c[q]=1;
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}