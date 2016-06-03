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

using namespace std;
typedef long long int ll;

int a[1000000],tree[1000000];

void build(int node,int l,int r)
{
	tree[node]=r-l+1;
	if(l==r)
		return;
	build(node<<1,l,(l+r)>>1);
	build((node<<1)+1,((l+r)>>1)+1,r);
}

int query(int node,int l,int r,int q)
{
	tree[node]--;
	if(l==r)
		return l;
	int q1=tree[(node<<1)+1];
	if(q1>=q)
		return query((node<<1)+1,((l+r)>>1)+1,r,q);
	else
		return query(node<<1,l,(l+r)>>1,q-q1);
}

int main()
{
	int test,n,i;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)	scanf("%d",&a[i]);
		build(1,0,n-1);
		for(i=n-1;i>=0;i--)
			a[i]=query(1,0,n-1,a[i]+1)+1;
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}