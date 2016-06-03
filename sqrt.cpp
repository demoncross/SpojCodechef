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
#define EPS (1e-9)
#define mp   make_pair
#define pb   push_back
#define pii  pair<int,int> 
#define se   second
#define fi   first
#define ll long long int

using namespace std;

typedef struct xxx
{
	int l,r,id;
}xx;

xx list[1000006];
int c[1000006],a[1000006];
int size;
ll an[1000006];

bool cmp(const xx &a,const xx b)
{
	if((a.l/size)==(b.l/size))	return a.r<b.r;
	return (a.l/size)<(b.l/size);
}

int main()
{
	ll x,y,ans;
	int n,m,i,j,k,l,prev;
	scanf("%d%d",&n,&m);
	size=sqrt(n)+1;
	for(i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(i=0;i<m;list[i].id=i,i++)
		scanf("%d%d",&list[i].l,&list[i].r);
	sort(list,list+m,cmp);
	ans=0;
	prev=-1;
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
			if((list[j].l/size)!=(list[i].r/size))
				break;
		for(k=i;k<j;k++)
		{
			if(prev==-1)
			{
				for(l=list[k].l;l<=list[k].r;l++)
				{
					x=a[l];
					y=c[x];
					ans=ans+(1+2*y)*x;
					c[x]++;
				}
			}
			else
			{
				if(list[prev].l<=list[k].l)
				{
					for(l=list[prev].l;l<list[k].l;l++)
					{
						x=a[l];
						y=c[x];
						ans=ans-(2*y-1)*x;
						c[x]--;
					}
				}
				else
				{
					for(l=list[k].l;l<list[prev].l;l++)
					{
						x=a[l];
						y=c[x];
						ans=ans+(1+2*y)*x;
						c[x]++;
					}
				}
				if(list[prev].r>=list[k].r)
				{
					for(l=list[prev].r;l>list[k].r;l--)
					{
						x=a[l];
						y=c[x];
						ans=ans-(2*y-1)*x;
						c[x]--;
					}	
				}
				else
				{
					for(l=list[k].r;l>list[prev].r;l--)
					{
						x=a[l];
						y=c[x];
						ans=ans+(1+2*y)*x;
						c[x]++;
					}
				}
			}
			//cout<<ans<<endl;
			prev=k;
			an[list[k].id]=ans;
		}
		i=j-1;
	}
	for(i=0;i<m;i++)	cout<<an[i]<<" ";
	return 0;
}