#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int a[100005],tree[1<<19],ans[100005];
void initialise(int node,int node_l,int node_r)
{
	tree[node]=node_r-node_l+1;
	if(node_l==node_r)	return;
	initialise(node<<1,node_l,(node_l+node_r)>>1);
	initialise((node<<1)+1,((node_l+node_r)>>1)+1,node_r);
}
int query(int node,int node_l,int node_r,int no)
{
	tree[node]--;
	if(node_l==node_r)	return node_l;
	else if(tree[(node<<1)+1]>=no)
		return query((node<<1)+1,((node_l+node_r)>>1)+1,node_r,no);
	else
		return query((node<<1),node_l,((node_l+node_r)>>1),no-tree[(node<<1)+1]);
}
int main()
{
	int test,i,no,n,t;
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		no=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>i)	no=-1;
		}
		printf("Test : %d\n",t);
		if(no==-1)
		{	
			printf("-1\n");
			continue;
		}
		initialise(1,0,n-1);
		for(i=n-1;i>=0;i--)
		{
			ans[i]=query(1,0,n-1,a[i]+1)+1;
		}
		for(i=0;i<n;i++)
		printf("%d ",ans[i])	;
		printf("\n");
	}
	return 0;
}