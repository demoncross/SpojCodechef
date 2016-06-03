#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <utility>
#include <set>

#define MOD (1000000007)
#define MAXINT 1e9

using namespace std;
typedef long long int ll;

int a[100005];
pair<int,int> list[100005];

int ser(int s,int e,int q)
{
	int m,ans=-1;
	while(s<=e)
	{
		m=(s+e)>>1;
		if(list[m].first<=q)	ans=m;
		if(list[m].first>q)	    e=m-1;
		else					s=m+1;
	}
	return ans;
}

int main()
{
	int test,n,m,i,x,p,q,r,k,y;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)	scanf("%d",&a[i]);
		for(i=1;i<=m;i++)	
		{
			scanf("%d%d",&x,&y);
			list[i]=make_pair(x,y);
		}	
		sort(list+1,list+m+1);
		stack<pair<int,int> > s;
		s.push(list[1]);
		for(i=2;i<=m;i++)
		{
			pair<int,int> x=s.top();
			if(list[i].first<=x.second)
			{
				x.second=max(x.second,list[i].second);
				s.pop();
				s.push(x);
			}
			else	s.push(list[i]);
		}
		x=s.size();
		for(i=x;i>=1;i--)	
		{
			list[i]=s.top();
			s.pop();
		}
	//	for(i=1;i<=x;i++)	printf("%d %d\n",list[i].first,list[i].second);
		p=1;
		for(i=1;i<=n;i++)
		{
			if(a[i]==i)	continue;
			int q=min(i,a[i]);
			int r=max(i,a[i]);
			k=ser(1,x,q);
			if(k==-1)	break;
			if(list[k].first<=q && list[k].second>=r)	continue;
			else		break;
		}
		if(i==n+1)	printf("Possible\n");
		else		printf("Impossible\n",i);
	}
	return 0;
}