//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1016

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int ll;

ll dp[65][65][101];

ll work(int n,int m)
{
	int i,j,l,k;
	ll v;
	if(n%2)	return 0;
	for(i=0;i<=64;i++)
		for(j=0;j<=64;j++)
			for(k=0;k<=100;k++)	
				dp[i][j][k]=0;
	if(m!=1)
		dp[1][0][1]=1;
	else dp[1][0][0]=1;
	for(l=1;l<=n;l++)
	{
		for(i=1;i<=l;i++)
		{
			j=l-i;
			for(k=0;k<m;k++)
			{
				v=dp[i][j][k];
				dp[i][j+1][(k*2)%m]+=v;
				dp[i+1][j][(k*2+1)%m]+=v;
			}
		}
	}
	return dp[n>>1][n>>1][0];
}

int main()
{
	int test,i,n,k;
	scanf("%d",&test);
	for(i=1;i<=test;i++)
	{
		scanf("%d%d",&n,&k);
		if(n&1 || k==0)	printf("Case %d: 0\n",i);
		else
		printf("Case %d: %lld\n",i,work(n,k));
	}
	return 0;
}