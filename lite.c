#include<stdio.h>
#define toggle(n)	(n==0?1:0)
int tree[(1<<18)+5];
int lazy[(1<<18)+5];

int query(int node,int node_s,int node_e,int q_s,int q_e)
{
	if(lazy[node])
	{
		tree[node]=(node_e-node_s+1)-tree[node];
		lazy[node]=0;
		if(node_s!=node_e){
		lazy[node<<1]=toggle(lazy[node<<1]);
		lazy[(node<<1)+1]=toggle(lazy[(node<<1)+1]);
		}	
	}
	if(q_s>node_e || q_e<node_s)	return 0;
	else if(q_s<=node_s && q_e>=node_e)	return tree[node];
	else				return (query(node<<1,node_s,(node_s+node_e)>>1,q_s,q_e)+
					query((node<<1)+1,((node_s+node_e)>>1)+1,node_e,q_s,q_e));						 
}



int update(int node,int node_s,int node_e,int q_s,int q_e)
{
	if(lazy[node])
	{
		tree[node]=(node_e-node_s+1)-tree[node];
		lazy[node]=0;
		if(node_s!=node_e){
		lazy[node<<1]=toggle(lazy[node<<1]);
		lazy[(node<<1)+1]=toggle(lazy[(node<<1)+1]);
		}
	}
	if(q_s>node_e || q_e<node_s)	return tree[node];
	else if(q_s<=node_s && q_e>=node_e)
	{
		tree[node]=(node_e-node_s+1)-tree[node];
		if(node_s!=node_e){		
		lazy[node<<1]=toggle(lazy[node<<1]);
		lazy[(node<<1)+1]=toggle(lazy[(node<<1)+1]);
		}		
		return tree[node];
	}
	else
	{	tree[node]=update(node<<1,node_s,(node_s+node_e)>>1,q_s,q_e)+
		update((node<<1)+1,((node_s+node_e)>>1)+1,node_e,q_s,q_e);
		return tree[node];
	}
}



int main()
{
int n,m,i,t,s,e;
scanf("%d%d",&n,&m);
for(i=0;i<m;i++)
{
	scanf("%d%d%d",&t,&s,&e);
	if(t==0)
		update(1,0,n-1,s-1,e-1);
	else
		printf("%d\n",query(1,0,n-1,s-1,e-1));
}
return 0;
}
