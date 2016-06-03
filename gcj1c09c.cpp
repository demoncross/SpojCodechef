#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;

map<pair<int,int> , int> dp;
int p[105],q;

int w(int a,int b)
{
	if(b<=a)	return 0;
	int i,t,min;
	pair<int,int> query(a,b);
	if(dp.find(query)!=dp.end())	return dp[query];
	min=100000000;
	for(i=0;i<q;i++)
	{
		if(p[i]>=a && p[i]<=b)
		{
			t=w(a,p[i]-1)+w(p[i]+1,b)+(b-a);
			if(t<min)	min=t;
		}
	}
	if(min==100000000)	min=0;
	dp[query]=min;
	return min;
}

int main()
{
	int t,i,n,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		dp.clear();
		scanf("%d%d",&n,&q);
		//p[1]=0;
		for(j=0;j<q;j++)
			scanf("%d",&p[j]);
		printf("Case #%d: %d\n",i,w(1,n));
	}
	return 0;
}