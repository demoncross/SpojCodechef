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

using namespace std;
typedef long long int ll;

pair<int,int> rounds[102];
int A[102][102];
long double dp[52][52][102];

int main()
{
	int test,i,l,j,k,c,r,n,x,y;
	long double q,ans;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&n,&c,&r);
		for(i=1;i<=r;i++)
		{
			scanf("%d%d",&x,&y);
			rounds[i]=make_pair(x,y);
		}
		for(i=0;i<c;i++)
		{
			for(j=0;j<c;j++)
			{
				A[i][j]=0;
				for(k=0;k<c;k++)
					if((i*k)%c==j)	A[i][j]++;
			}
		}
		for(i=1;i<=r;i++)	for(j=0;j<=n;j++)	for(k=0;k<=c;k++)	dp[i][j][k]=0;
		for(j=1;j<=n;j++)	dp[0][j][1]=1;
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=0;k<c;k++)
				{
					if(j<rounds[i].first || j>rounds[i].second)
					{
						dp[i][j][k]=dp[i-1][j][k];
						continue;
					}
					dp[i][j][k]=(dp[i-1][j][k])/2;
					q=0;
					for(l=0;l<c;l++)
						q=q+((dp[i-1][j][l]*A[l][k])/c);
					q=q/2;
					dp[i][j][k]+=q;
				}
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<c;j++)
				ans=ans+(dp[r][i][j])*j;
		}
		printf("%.10Lf\n",ans);
	}
	return 0;
}