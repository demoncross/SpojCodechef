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

#define MOD (1000000009)
#define MAXINT 1e9

using namespace std;
typedef long long int ll;

pair<int,int> a[2003];
map<pair<int,int>,int> m;

int f(int n,int p)
{
		pair<int,int> p1,p2;
		bool b1,b2;
		int test,x,y,i,j,k,l,ans,d,q;
		ans=2;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)	if(a[j].first!=a[i].first)	break;
			for(k=i;k<j;k++)
			{
				for(l=k+1;l<j;l++)
				{
					d=a[l].second-a[k].second;
					q=2;
					p1=make_pair(a[l].first+d,a[l].second);
					p2=make_pair(a[k].first+d,a[k].second);
					if(p)
					{
						x=p1.first;
						p1.first=p1.second;
						p1.second=x;
						x=p2.first;
						p2.first=p2.second;
						p2.second=x;
					}
					if(m.find(p1)!=m.end())	b1=true;
					else					b1=false;
					if(m.find(p2)!=m.end())	b2=true;
					else					b2=false;
					if(b1&&b2)	q=min(0,q);
					else if(b1||b2)	q=min(q,1);
					else	;
					ans=min(ans,q);
					q=2;
					if(d%2)	continue;
					d=d/2;
					p1=make_pair(a[l].first-d,a[l].second-d);
					p2=make_pair(a[l].first+d,a[l].second-d);
					if(p)
					{
						x=p1.first;
						p1.first=p1.second;
						p1.second=x;
						x=p2.first;
						p2.first=p2.second;
						p2.second=x;
					}
					if(m.find(p1)!=m.end())	b1=true;
					else					b1=false;
					if(m.find(p2)!=m.end())	b2=true;
					else					b2=false;
					if(b1&&b2)	q=min(0,q);
					else if(b1||b2)	q=min(q,1);
					else	q=min(q,2);
					ans=min(ans,q);
				}
			}
			i=j-1;
		}
		return ans;
}


int main()
{
	pair<int,int> p1,p2;
	bool b1,b2;
	int test,x,y,i,j,k,l,n,ans,d,q;
	scanf("%d",&n);
	for(i=0;i<n;i++)	
	{
		scanf("%d%d",&x,&y);
		a[i]=make_pair(x,y);
		m[make_pair(x,y)]=i;
	}
	if(n==0)	printf("4\n");
	else if(n==1)	printf("3\n");
	else
	{
		int q1,q2,q3=3;
		sort(a,a+n);
		q1=f(n,0);
		for(i=0;i<n;i++)
		{
			q=a[i].first;
			a[i].first=a[i].second;
			a[i].second=q;
		}
		sort(a,a+n);
		q2=f(n,1);
		ans=min(2,min(q1,q2));
		printf("%d\n", ans);
	}

	return 0;
}