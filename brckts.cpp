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

char s[30004];
int a[30004];
int tree[1<<18];
int lazy[1<<18];

void initialise(int node,int l,int r)
{
	lazy[node]=0;
	if(l==r)	{tree[node]=a[l];return;}
	initialise(node<<1,l,(l+r)/2);
	initialise((node<<1)+1,((l+r)/2)+1,r);
	tree[node]=min(tree[node<<1],tree[(node<<1)+1]);
}

void update(int node,int n_l,int n_r,int q_l,int q_r,int v)
{
	if(lazy[node])
	{
		tree[node]+=lazy[node];
		if(n_l!=n_r)	
		{
			lazy[node<<1]+=lazy[node];
			lazy[(node<<1)+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(n_l>q_r || q_l>n_r)	return;
	else if(n_l>=q_l && n_r<=q_r)
	{
		tree[node]+=v;
		if(n_l!=n_r){
		lazy[node<<1]+=v;
		lazy[(node<<1)+1]+=v;}
		return;
	}
	update(node<<1,n_l,(n_l+n_r)/2,q_l,q_r,v);
	update((node<<1)+1,((n_l+n_r)/2)+1,n_r,q_l,q_r,v);
	tree[node]=min(tree[node<<1],tree[(node<<1)+1]);
}

int check(int node,int n_l,int n_r)
{
	if(lazy[node])
	{
		tree[node]+=lazy[node];
		if(n_l!=n_r)	
		{
			lazy[node<<1]+=lazy[node];
			lazy[(node<<1)+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(n_l==n_r)	return tree[node];
	return check((node<<1)+1,((n_l+n_r)>>1)+1,n_r);
}

int main()
{
	int test,x,i,n,m,q,v;
	x=1;
	test=10;
	while(test--)
	{
		printf("Test %d:\n",x);
		scanf("%d",&n);
		scanf(" %s",s);
		a[0]=((s[0]=='(')?1:-1);
		for(i=1;i<n;i++)	
			a[i]=a[i-1]+(s[i]=='('?1:-1);
		initialise(1,0,n-1);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&q);
			if(q==0)
			{
				int k=check(1,0,n-1);
				if(n%2==0 && tree[1]>=0 && !k)	printf("YES\n");
				else			printf("NO\n");
				continue;
			}
			if(s[q-1]==')')	{v=2;s[q-1]='(';}
			else			{v=-2;s[q-1]=')';}
			update(1,0,n-1,q-1,n-1,v);
		}
		x++;
	}
	return 0;
}