#include<stdio.h>
typedef long long ll;
ll tree[1<<18];
ll lazy[1<<18];
ll  a,b;
ll update(int node,int node_s,int node_e,int query_s,int query_e,int s)
{
ll x,y;
if(lazy[node])
{
	tree[node]+=((node_e-node_s+1)*((2*lazy[node])+node_e-node_s))>>1;
	lazy[node<<1]=lazy[node];
	lazy[(node<<1)+1]=1+lazy[node]+(node_e-node_s+1)>>1;
	lazy[node]=0;
}
if(node_s>query_e || node_e<query_s)	return tree[node];
else if(node_s>=query_s && node_e<=query_e)
{
	tree[node]+=((node_e-node_s+1)*((2*s)+node_e-node_s))>>1;
	lazy[node<<1]=s;
	lazy[(node<<1)+1]=1+s+(node_e-node_s+1)>>1;
	return (tree[node]);
}
else
{
	x=update(node<<1,node_s,(node_s+node_e)>>1,query_s,query_e,s);
	y=update((node<<1)+1,((node_s+node_e)>>1)+1,node_e,query_s,query_e,s+((node_s+node_e)>>1)+1-query_s);
	tree[node]=x+y;
	return tree[node];
}
}

ll query(int node,int node_s,int node_e,int query_s,int query_e)
{
ll x,y;
if(lazy[node])
{
	tree[node]+=((node_e-node_s+1)*((2*lazy[node])+node_e-node_s))>>1;
	lazy[node<<1]=lazy[node];
	lazy[(node<<1)+1]=1+lazy[node]+(node_e-node_s+1)>>1;
	lazy[node]=0;
}
if(node_s>query_e || node_e<query_s)	return 0;
else if(node_s>=query_s && node_e<=query_e)	return tree[node];
else
{
	x=query(node<<1,node_s,(node_s+node_e)>>1,query_s,query_e);
	y=query((node<<1)+1,((node_s+node_e)>>1)+1,node_e,query_s,query_e);
	return (x+y);
}
}

int main()
{
ll n,q,t,i;
scanf("%lld%lld",&n,&q);
while(q--)
{
	scanf("%lld%lld%lld",&t,&a,&b);
	a--;
	b--;
	if(t==0)
	{
		update(1,0,n-1,a,b,1);
	}
	else
	{
		printf("%lld\n",query(1,0,n-1,a,b));
		for(i=1;i<=11;i++)	printf("%d ",tree[i]);
	}
}
return 0;
}

