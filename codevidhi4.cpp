#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int tree[1000000];
void update(int node,int node_l,int node_r,int q_l,int q_r,int q)
{
	//printf("*%d %d %d %d\n",node_l,node_r,q_l,q_r);
	if(node_l>q_r || node_r<q_l)	
	{
		//printf("**%d %d\n",node_l,node_r);
		return;
	}
	if(node_l>=q_l && node_r<=q_r)	
	{
		//printf("***%d %d\n",node_l,node_r);
		tree[node]+=q;
		return;
	}
	update(node<<1,node_l,(node_l+node_r)>>1,q_l,q_r,q);
	update((node<<1)+1,((node_l+node_r)>>1)+1,node_r,q_l,q_r,q);
	//printf("%d\n",tree[node]);
}
int query(int node,int node_l,int node_r,int q)
{
	int m,q1,q2;
	if(node_r==node_l && node_r==q)	return tree[node];	
	if(node_l>q || q>node_r)	return 0;
	m=(node_r+node_l)>>1;
	q1=query(node<<1,node_l,(node_l+node_r)>>1,q);
	q2=query((node<<1)+1,((node_l+node_r)>>1)+1,node_r,q);
	if(m>=q) 
	{
		return tree[node]+q1;
	}
	else
	{
		return tree[node]+q2;
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
	int n,u,i,l,r,q,j;
	scanf("%d%d",&n,&u);
	for(i=0;i<=1000000;i++)	tree[i]=0;
	for(i=0;i<u;i++)
	{
		scanf("%d%d%d",&l,&r,&q);
		update(1,0,n-1,l,r,q);
	}
	//for(i=1;i<=16;i++)	printf("%d\n",tree[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&j);
		printf("%d\n",query(1,0,n-1,j));
	}
	//for(i=1;i<=10;i++)	printf("%d ",tree[i]);
	}
	return 0;
}
