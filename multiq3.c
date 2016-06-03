#include<stdio.h>
typedef struct node
{
	int m0,m1,m2;
}t;

t tree[1<<18];
int lazy[1<<18];

void build(int i,int j,int node)
{
	if(i==j)
	{
		tree[node].m0=1;
		tree[node].m1=tree[node].m2=lazy[node]=0;
		return;
	}
	build(i,(i+j)>>1,node<<1);
	build(((i+j)>>1)+1,j,(node<<1)+1);
	tree[node].m0=tree[node<<1].m0+tree[(node<<1)+1].m0;
	tree[node].m1=tree[node<<1].m1+tree[(node<<1)+1].m1;
	tree[node].m2=tree[node<<1].m2+tree[(node<<1)+1].m2;
}

void update(int i,int j, int q_i,int q_j,int node)
{
	int a,b,c,k;
	if(lazy[node]%3!=0)
	{
		a=tree[node].m0; b=tree[node].m1; c=tree[node].m2;
		k=lazy[node]%3;
		if(k==1)
		{
			tree[node].m0=c;
			tree[node].m1=a;
			tree[node].m2=b;
		}
		else
		{
			tree[node].m0=b;
			tree[node].m1=c;
			tree[node].m2=a;
		}
		if(i!=j)
		{
			lazy[node<<1]+=lazy[node];
			lazy[(node<<1)+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(q_i>j || q_j<i)	return;
	else if(q_i<=i && q_j>=j)
	{
		a=tree[node].m0;
		tree[node].m0=tree[node].m2;
		tree[node].m2=tree[node].m1;
		tree[node].m1=a;
		if(i!=j)
		{
			lazy[node<<1]++;
			lazy[(node<<1)+1]++;
		}
		return;
	}
	update(i,(i+j)>>1,q_i,q_j,node<<1);
	update(((i+j)>>1)+1,j,q_i,q_j,(node<<1)+1);
	tree[node].m0=tree[node<<1].m0+tree[(node<<1)+1].m0;
	tree[node].m1=tree[node<<1].m1+tree[(node<<1)+1].m1;
	tree[node].m2=tree[node<<1].m2+tree[(node<<1)+1].m2;
	return;
}

int query(int i,int j,int q_i,int q_j,int node)
{
	int a,b,c,k;
	if(lazy[node]%3!=0)
	{
		a=tree[node].m0; b=tree[node].m1; c=tree[node].m2;
		k=lazy[node]%3;
		if(k==1)
		{
			tree[node].m0=c;
			tree[node].m1=a;
			tree[node].m2=b;
		}
		else
		{
			tree[node].m0=b;
			tree[node].m1=c;
			tree[node].m2=a;
		}
		if(i!=j)
		{
			lazy[node<<1]+=lazy[node];
			lazy[(node<<1)+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(q_i>j || q_j<i)	return 0;
	else if(q_i<=i && q_j>=j)
	{
		return tree[node].m0;
	}
	a=query(i,(i+j)>>1,q_i,q_j,node<<1);
	b=query(((i+j)>>1)+1,j,q_i,q_j,(node<<1)+1);
	return (a+b);
}

int main()
{
	int n,q,i,l,r,t;
	scanf("%d %d",&n,&q);
	build(0,n-1,1);
	for(i=0;i<q;i++)
	{
		scanf("%d",&t);
		if(t==0)
		{
			scanf("%d %d",&l,&r);
			update(0,n-1,l,r,1);
		}
		else
		{
			scanf("%d %d",&l,&r);
			printf("%d\n",query(0,n-1,l,r,1));
		}
	}
	return 0;
}
