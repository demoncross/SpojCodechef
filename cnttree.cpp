#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cmath>
using namespace std;
vector < vector<int> > adj_list(100);
char v[100];
int k,count=0;
int work(int node,int *h)
{
	int ht,d,x,i,q,ma,sec_max_ht,max_ht;
	ma=sec_max_ht=max_ht=0;
	v[node]=1;
	for(i=0;i<adj_list[node].size();i++)
	{
		q=adj_list[node][i];
		if(v[q])	continue;
		x=work(q,&ht);
		if(x>ma)	ma=x;
		if(ht>max_ht)
		{
			sec_max_ht=max_ht;
			max_ht=ht;
		}
		if(ht>sec_max_ht)	sec_max_ht=ht;
	}
	*h=max_ht;
	d=(max(ma,max_ht+sec_max_ht+1));
	if(d>=k)	count++;
	return d;
}
int main()
{
	int t,n,i,x,y;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<100;i++)	
		{
			adj_list[i].clear();
			v[i]=0;
		}
		scanf("%d%d",&n,&k);
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&x,&y);
			adj_list[x].push_back(y);
			adj_list[y].push_back(x);
		}
		work(1,&x);
		printf("%d\n",count);
	}
	return 0;
}