//http://codeforces.com/contest/92/problem/D
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

vector < pair<int, pair< int,int> > > a,b,c;

void work(int s,int e)
{
	int m,p_b,p_c,i,ans;
	if(s>=e)	return;
	m=(s+e)>>1;	
	work(s,m);
	work(m+1,e);
	p_b=p_c=0;
	b.clear();
	c.clear();
	for(i=s;i<=m;i++)	b.push_back(a[i]);
	for (;i<=e;i++)		c.push_back(a[i]);
	ans=-1;
	for(i=s;i<=e;i++)
	{
		if(p_b==b.size())
			a[i]=c[p_c++];
		else if(p_c==c.size())
		{
			a[i]=b[p_b++];
			if(ans!=-1)
				a[i].second.second=max(a[i].second.second,ans-a[i].second.first-1);
		}
		else if(b[p_b]<=c[p_c])
		{
			a[i]=b[p_b++];
			if(ans!=-1)
				a[i].second.second=max(a[i].second.second,ans-a[i].second.first-1);
		}
		else
		{
			a[i]=c[p_c];
			if(c[p_c].second.first>ans)	ans=c[p_c].second.first;
			p_c++;
		}
	}
}

int ans[100005];
int main()
{
	int i,n,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)	
	{
		scanf("%d",&x);
		a.push_back(make_pair(x,make_pair(i,-1)));
	}
	work(0,n-1);
	for(i=0;i<n;i++)	ans[a[i].second.first]=a[i].second.second;
	for(i=0;i<n;i++)	printf("%d ",ans[i]);
	return 0;
}