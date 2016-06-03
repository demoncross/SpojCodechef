#include<stdio.h>
#define sentinel 1000000000
int a[100008];
int tree[1<<18];
void initialise(int i,int j,int node)
{
	if(i==j)
	{
		tree[node]=a[i];
		return;	
	}
	initialise(i,(i+j)>>1,node<<1);
	initialise(((i+j)>>1)+1,j,(node<<1)+1);
	if(tree[node<<1]<tree[(node<<1)+1])
		tree[node]=tree[node<<1];
	else
		tree[node]=tree[(node<<1)+1];
}

int query(int i,int j,int q_i,int q_j,int node)
{
	int q1,q2;
	if(q_i>j || q_j<i)		return sentinel;
	else if(i>=q_i && j<=q_j)	return tree[node];
	q1=query(i,((i+j)>>1),q_i,q_j,node<<1);
	q2=query(((i+j)>>1)+1,j,q_i,q_j,(node<<1)+1);
	if(q1<q2)	return q1;
	else		return q2;
}


int main()
{
int t=0,test,i,num,j,qery,u,v;
scanf("%d",&test);
while(test--)
{
t++;
printf("Scenario #%d:\n\n",t);
scanf("%d %d",&num,&qery);
for(i=0;i<num;i++)
	scanf(" %d",&a[i]);
initialise(0,num-1,1);
for(i=1;i<=qery;i++)
{
	scanf("%d %d",&u,&v);
	printf("%d\n",query(0,num-1,u-1,v-1,1));
}
}
return 0;
}
