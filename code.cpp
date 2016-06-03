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

using namespace std;
typedef long long int ll;

typedef struct ss
{
	int m,f,g;
}xx;

int a[100005];
xx tree[1<<21];

int gcd(int a,int b)
{
	if(a<b)	swap(a,b);
	if(b==0)	return a;
	return gcd(b,a%b);
}

void build(int node,int l,int r)
{
	if(l==r)
	{
		tree[node].m=tree[node].g=a[l];
		tree[node].f=1;
		return;
	}
	build(node<<1,l,(l+r)>>1);
	build((node<<1)+1,((l+r)>>1)+1,r);
	if(tree[node<<1].m<tree[(node<<1)+1].m)
		tree[node]=tree[node<<1];
	else if(tree[(node<<1)+1].m<tree[node<<1].m)
		tree[node]=tree[(node<<1)+1];
	else
	{
		tree[node]=tree[node<<1];
		tree[node].f+=tree[(node<<1)+1].f;
	}
	tree[node].g=gcd(tree[node<<1].g,tree[(node<<1)+1].g);
}

xx query(int node,int n_l,int n_r,int q_l,int q_r)
{
	xx a,b;
	a.m=-1;
	if(q_l>n_r || n_l>q_r)	return a;
	else if(n_l>=q_l && n_r<=q_r)	return tree[node];
	a=query(node<<1,n_l,(n_r+n_l)>>1,q_l,q_r);
	b=query((node<<1)+1,((n_l+n_r)>>1)+1,n_r,q_l,q_r);
	if(a.m==-1)	return b;
	if(b.m==-1)	return a;
	if(a.m<b.m)
	{
		a.g=gcd(a.g,b.g);
		return a;
	}
	else if(b.m<a.m)
	{
		b.g=gcd(b.g,a.g);
		return b;
	}
	else
	{
		a.f+=b.f;
		a.g=gcd(a.g,b.g);
		return a;
	}
}

int main()
{
	int n,i,m,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)	scanf("%d",&a[i]);
	scanf("%d",&m);
	build(1,1,n);
	xx q;
	while(m--)
	{
		scanf("%d%d",&x,&y);
		q=query(1,1,n,x,y);
		//cout<<q.m<<" "<<q.f<<" "<<q.g<<endl;
		if(q.m!=q.g)	printf("%d\n",y-x+1);
		else			printf("%d\n",y-x+1-q.f);
	}
	return 0;
}