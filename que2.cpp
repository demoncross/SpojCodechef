#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
vector < pair<int,int> > v;
int a[1<<15];
int b[10004];
void initialise(int node,int node_l,int node_r)
{
	if(node_l==node_r)
	{
		a[node]=1;
		return;
	}
	a[node]=node_r-node_l+1;
	initialise(node<<1,node_l,(node_l+node_r)>>1);
	initialise((node<<1)+1,((node_l+node_r)>>1)+1,node_r);
}
int query(int node,int node_l,int node_r,int no)
{
	if(node_l==node_r)
	{
		a[node]--;
		return node_l;
	}
	else if(a[node<<1]>=no)
	{
		a[node]--;
		return (query(node<<1,node_l,(node_l+node_r)>>1,no));
	}
	else if(a[node<<1]<no)
	{
		a[node]--;
		return (query((node<<1)+1,((node_l+node_r)>>1)+1,node_r,no-a[node<<1]));
	}
}
int main()
{
	int test,n,i,x,ht,no;
	scanf("%d",&test);
	while(test--)
	{
		v.clear();
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(i=0;i<n;i++)
		{
			v.push_back(make_pair(a[i],b[i]));
			b[i]=-1;
		}
		sort(v.begin(),v.end());
		initialise(1,0,n-1);
		for(i=0;i<n;i++)
		{
			ht=v[i].first;
			no=v[i].second;
			x=query(1,0,n-1,no+1);
			b[x]=ht;
		}
		for(i=0;i<n;i++)
			printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}