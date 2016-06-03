#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
int h[100005],s[100005],ans[100005];
int tree[1<<17+5];
void initialise(int node,int node_l,int node_r)
{
	if(node_l==node_r)	tree[node]=1;
	else
	{
		initialise(node<<1,node_l,(node_l+node_r)>>1);
		initialise((node<<1)+1,((node_l+node_r)>>1)+1,node_r);
		tree[node]=tree[node<<1]+tree[(node<<1)+1];
	}
}
int query(int node,int node_l,int node_r,int no)
{
	if(node_l==node_r)
	{
		tree[node]--;
		return node_l;
	}
	else if(tree[node<<1]>=no)
	{
		tree[node]--;
		return (query(node<<1,node_l,(node_l+node_r)>>1,no));
	}
	else if(tree[node<<1]<no)
	{
		tree[node]--;
		return (query((node<<1)+1,((node_l+node_r)>>1)+1,node_r,no-tree[node<<1]));
	}
}
int main()
{
	int i,n,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&h[i]);
	for(i=0;i<n;i++)
		scanf("%d",&s[i]);
	sort(h,h+n);
	initialise(1,0,n-1);
	for(i=n-1;i>=0;i--)
	{
		x=query(1,0,n-1,s[i]+1);
		ans[i]=h[x];
	}
	for(i=0;i<n;i++)	printf("%d\n",ans[i]);
	return 0;
}