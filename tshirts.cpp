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
#define mod (1000000007)

using namespace std;
typedef long long int ll;
bool check [12][102];
ll dp[102][1<<11];

int main()
{
	int test,n,x,i,j,k;
	char c;
	cin>>test;
	while(test--)
	{
		cin>>n;
		for(i=0;i<=n;i++)	for(j=0;j<=100;j++)	check[i][j]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%c",&x,&c);
			while(c!='\n')
			{
				check[i][x]=1;
				scanf("%d%c",&x,&c);
			}
			check[i][x]=1;
		}
		for(i=0;i<n;i++)	dp[1][1<<i]=check[i][1];
		dp[1][0]=1;
		for(i=2;i<=100;i++)
		{
			for(j=0;j<(1<<n);j++)
			{
				dp[i][j]=dp[i-1][j];
				for(k=0;k<n;k++)
				{
					if(j&(1<<k) && check[k][i])
						dp[i][j]=(dp[i][j]+dp[i-1][j^(1<<k)])%mod;
				}
			}
		}
		cout<<dp[100][(1<<n)-1]<<endl;
	}
	return 0;
}