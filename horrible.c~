#include<stdio.h>
typedef unsigned long long int ll;
ll tree[1<<18];
ll lazy[1<<18];


void build(void)
{
	int i;
	for(i=0;i<(1<<18);i++)	
		lazy[i]=tree[i]=0;
}


void update(int i,int j,int q_i,int q_j,int add,int node)
{
	if(lazy[node]!=0)
	{
		tree[node]+=((ll)lazy[node]*(j-i+1));
		if(i!=j)
		{
			lazy[node<<1]+=lazy[node];
			lazy[(node<<1)+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(q_i>j || q_j<i || i>j)	return;
	if(q_i<=i && q_j>=j)
	{
		tree[node]+=((ll)add*(j-i+1));
		if(i!=j)
		{
			lazy[node<<1]+=add;
			lazy[(node<<1)+1]+=add;
		}
		return;
	}
	update(i,(i+j)>>1,q_i,q_j,add,node<<1);
	update(((i+j)>>1)+1,j,q_i,q_j,add,(node<<1)+1);
	tree[node]=tree[node<<1]+tree[(node<<1)+1];
	return;
}


ll query(int i,int j,int q_i,int q_j,int node)
{
	ll q1,q2;
	if(lazy[node]!=0)
	{
		tree[node]+=((ll)lazy[node]*(j-i+1));
		if(i!=j)
		{
			lazy[node<<1]+=lazy[node];
			lazy[(node<<1)+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(q_i>j || q_j<i || i>j)	return 0;	
	if(q_i<=i && q_j>=j)
	{
		return tree[node];
	}
	q1=query(i,(i+j)>>1,q_i,q_j,node<<1);
	q2=query(((i+j)>>1)+1,j,q_i,q_j,(node<<1)+1);
	return (q1+q2);
}

int main()
{
	int test,t,n,c,l,r,add,i;
	scanf("%d",&test);
	while(test--)
	{
		build();
		scanf("%d %d",&n,&c);
		for(i=0;i<c;i++)
		{
			scanf("%d",&t);
			if(t==0)
			{
				scanf("%d %d %d",&l,&r,&add);
				update(0,n-1,l-1,r-1,add,1);
			}
			else
			{
				scanf("%d %d",&l,&r);
				printf("%llu\n",query(0,n-1,l-1,r-1,1));
			}
		}
	}
	return 0;
}
