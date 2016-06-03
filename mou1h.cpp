#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#define mod (1000000009)

using namespace std;
typedef long long int ll;

typedef struct nn
{
	int x[4];
	int index;
}node;

node a[100000];
int s[100000];
int list[20][100000];

bool ff(node a,node b)
{
	if(a.x[0]==b.x[0])	return a.x[1]<b.x[1];
	else				return a.x[0]<b.x[0];
}

int lcp(int x,int y,int i,int l)
{
	int ans=0;
	if(x==y)	return l-x;
	for(;i>=0 && x<l && y<l;i--)	
	{
		if(list[i][x]==list[i][y])
		{
			ans+=(1<<i);
			x+=(1<<i);
			y+=(1<<i);
		}
	}
	return ans;
}

int main()
{
	int test,n,l,i,rank,step,move;
	ll ans,temp;
	cin>>test;
	while(test--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)	cin>>s[i];
		for(i=0;i<n-1;i++)
			s[i]=s[i]-s[i+1]+100;
		l=n-1;
		for(i=0;i<l;i++)	list[0][i]=s[i];
		step=1;
		move=1;
		while(move<l)
		{
			for(i=0;i<l;i++)
			{
				a[i].index=i;
				a[i].x[0]=list[step-1][i];
				a[i].x[1]=((i+move<l)?list[step-1][i+move]:-1);
			}
			sort(a,a+l,ff);
			rank=0;
			for(i=0;i<l;i++)
			{
				if(i!=0 && a[i-1].x[0]==a[i].x[0] && a[i-1].x[1]==a[i].x[1])	list[step][a[i].index]=list[step][a[i-1].index];
				else															list[step][a[i].index]=rank++;
			}
			step++;
			move<<=1;
		}
		temp=(((ll)l)*(l+1))>>1;
		ans=0;
		for(i=0;i<l-1;i++)	ans+=lcp(a[i].index,a[i+1].index,step-1,l);
		temp=temp-ans;
		printf("%lld\n",temp%mod);
	}
	return 0;
}