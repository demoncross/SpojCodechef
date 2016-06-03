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
bool taken[1000006];
vector<int> ar;

int w(int s,int e,int x)
{
	int m,ans;
	ans=s;
	while(s<=e)
	{
		m=(s+e)>>1;
		if(b[m]>=a[x])	e=m-1;
		else			s=m+1;
		if(!taken[m])	ans=m;
	}
	return ans;
}

int main()
{
	int test,ans,i,j,m,n,start,x,q;
	scanf("%d",&test);
	while(test--)
	{
		ar.clear();
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)	scanf("%d",&a[i]);
		for(i=0;i<m;i++)	scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+m);
		start=0;
		for(i=0;i<n;i++)	taken[i]=0;
		for(i=0;i<n;i++)
		{
			x=w(start,m-1,i);
			taken[x]=1;
			ar.push_back(x);
			for(j=start;j<m;j++)
				if(!taken[j])	break;
			start=j;
		}
		sort(ar.begin(),ar.end());
		ans=-1;
		for(i=0;i<n;i++)
		{
			q=abs(a[i]-b[ar[i]]);
			ans=max(ans,q);
		}
		printf("%d\n",ans);
	}
	return 0;
}