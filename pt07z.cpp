#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
vector < vector <int> > adj_list(10005);
int p[10005];
int work(int node,int *h)
{
	int ht,max_ht=0,a,b,i,q,x,max_w=0,second_max_ht=0;
	p[node]=1;
	for(i=0;i<adj_list[node].size();i++)
	{
		q=adj_list[node][i];
		if(p[q])	continue;
		ht=0;
		x=work(q,&ht);
		if(x>max_w)	max_w=x;
		if(ht>max_ht)	
		{
			second_max_ht=max_ht;
			max_ht=ht;
		}
		else if(ht>second_max_ht)	second_max_ht=ht;
	}
	a=max_ht+second_max_ht+1;
	b=max_w;
	*h=max_ht+1;
	return (max(a,b));
}
int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}
	printf("%d\n",work(1,&x)-1);
	return 0;
}