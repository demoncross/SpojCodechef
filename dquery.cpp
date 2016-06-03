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

typedef struct xx
{
	int l,r,i,ans;
}xx;

bool ff(xx a, xx b)
{
	return a.l<b.l;
}

bool fg(xx a, xx b)
{
	return a.i<b.i;
}

int a[100005],next[100005];
int prev[1000006];
xx list[200005];
int lp[200005];
int tree[1<<18];

void initialise(int node,int l,int r)
{
	if(l==r)
	{
		tree[node]=(prev[a[l]]==l?1:0);
		return;
	}
	initialise(node<<1,l,(l+r)>>1);
	initialise((node<<1)+1,((l+r)>>1)+1,r);
	tree[node]=tree[node<<1]+tree[(node<<1)+1];
}

void update(int node,int n_l,int n_r,int q)
{
	if(n_l==n_r)
	{
		if(q==n_r)	tree[node]=1;
		return;
	}
	if(n_r>=q && n_l<=q)
	{
		tree[node]++;
		update(node<<1,n_l,(n_l+n_r)>>1,q);
		update((node<<1)+1,((n_l+n_r)>>1)+1,n_r,q);
	}
}

int query(int node,int n_l,int n_r,int q_l,int q_r)
{
	if(n_r<q_l || n_l>q_r)	return 0;
	else if(n_l>=q_l && n_r<=q_r)	return tree[node];
	return query(node<<1,n_l,(n_l+n_r)>>1,q_l,q_r)+query((node<<1)+1,((n_l+n_r)>>1)+1,n_r,q_l,q_r);
}

int main()
{
	int n,m,i,j,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	for(i=0;i<=1000000;i++)	prev[i]=-1;
	for(i=n-1;i>=0;i--)
	{
		next[i]=prev[a[i]];
		prev[a[i]]=i;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		list[i].l=x;
		list[i].r=y;
		list[i].i=i;
	}
	sort(list,list+m,ff);
	initialise(1,0,n-1);
	j=0;
	for(i=0;i<m;i++)
	{
		x=list[i].l-1;
		for(;j<x;j++)
		{
			y=next[j];
			if(y!=-1)
				update(1,0,n-1,y);
		}
		list[i].ans=query(1,0,n-1,list[i].l-1,list[i].r-1);
	}
	//sort(list,list+m,fg);
	for(i=0;i<m;i++)	lp[list[i].i]=list[i].ans;
	for(i=0;i<m;i++)	printf("%d\n",lp[i]);
	return 0;
}