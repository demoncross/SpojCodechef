#include<stdio.h>
typedef long long int ll;
ll tree[(1<<21)+5];
int a[1000005];
void init(int root,int s,int e)
{
	if(s==e){
		tree[root]=a[s];
		return;}
	init(root<<1,s,(s+e)>>1);
	init((root<<1)+1,((s+e)>>1)+1,e);
	tree[root]=tree[root<<1]+tree[(root<<1)+1];
}
ll query(int root,int q_s,int q_e,int s,int e)
{
	ll m,n;
	if(q_e<s || q_s>e)	return 0;
	else if(q_s<=s && q_e>=e)	return tree[root];
	m=query(root<<1,q_s,q_e,s,(s+e)>>1);
	n=query((root<<1)+1,q_s,q_e,((s+e)>>1)+1,e);
	return (m+n);
}
void update(int root,int q,int sum,int s,int e)
{
	if(s>q || q>e)	return;
	if(s==e)
		{tree[root]=a[q]+=sum;
		return;}
	update(root<<1,q,sum,s,(s+e)>>1);
	update((root<<1)+1,q,sum,((s+e)>>1)+1,e);
	tree[root]+=sum;
}
int main()
{
	int n,quer,i,q,sum;
	char c[3];
	scanf("%d %d",&n,&quer);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	init(1,0,n-1);
	for(i=0;i<quer;i++)
	{
		scanf(" %s %d %d",c,&q,&sum);
		if(c[0]=='S')
			printf("%lld\n",query(1,q,sum,0,n-1));
		else if(c[0]=='G')
			update(1,q,sum,0,n-1);
		else	update(1,q,-sum,0,n-1);
	}
	return 0;
}