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

int a[100005];
int f[1000006];
int visited[1000006];
vector<vector<int> > aa;
vector<int> list;
vector<int> prime;

void g(void)
{
	ll i,j,x,p;
	aa.clear();
	prime.clear();
	for(i=0;i<=1000000;i++)	f[i]=0;
	f[1]=1;
	for(i=2;i<=1000000;i++)
	{
		if(f[i]==0)
		{
			prime.push_back(i);
			visited[i]=-1;
			f[i]=i;		
			for(j=i;j*i<=1000000;j++)
				f[i*j]=i;
		}
	}
}

void factor(int n)
{
	ll i,j,x,p;
	aa.clear();
	for(i=0;i<n;i++)
	{
		list.clear();
		x=a[i];
		while(x>1)
		{
			p=f[x];
			while(x%p==0)	x=x/p;
			list.push_back(p);
		}
		aa.push_back(list);
	}
}

int main()
{
	int test,i,n,j,ans,curr,start,end,q;
	g();
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)	scanf("%d",&a[i]);
		factor(n);
		for(i=0;i<prime.size();i++)	visited[prime[i]]=-1;
		start=0;
		for(i=0;i<aa[0].size();i++)
			visited[aa[0][i]]=0;
		ans=1;
		curr=1;
		for(end=1;end<n;end++)
		{
			for(j=0;j<aa[end].size();j++)
			{
				if(visited[aa[end][j]]>=start)	break;
				else							visited[aa[end][j]]=end;
			}
			if(j==aa[end].size())	
			{
				curr++;
				ans=max(ans,curr);
			}
			else
			{
				q=start;
				for(;j<aa[end].size();j++)
				{
					if(visited[aa[end][j]]>=start)	q=max(q,visited[aa[end][j]]);
					visited[aa[end][j]]=end;
				}
				start=q+1;
				curr=end-start+1;
				ans=max(ans,curr);
			}
		}
		if(ans==1)	ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}