
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
#define mod 1000000007
#define MINI -100000000

using namespace std;
typedef long long int ll;

int a[1000][1000];
int dp[1000][1000];

int main()
{
	int test,n,i,j,x,y,diag,ans,q,s;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		a[0][1]=a[0][2]=0;
		for(i=0;i<=n;i++)	a[i][0]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
				scanf("%d",&a[i][j]);
			a[i][j]=a[i][j+1]=0;
		}
		for(i=0;i<=n+2;i++)	a[n+1][i]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=min(i,n-i);j++)
				a[i][j]+=max(a[i-1][j],max(a[i-1][j-1],a[i-1][j+1]));
		}
		for(i=n;i>=1;i--)
		{
			for(j=n;j>=n-min(n-i+1,i-1)+1;j--)
				a[j][i]+=max(a[j][i+1],max(a[j-1][i+1],a[j+1][i+1]));
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++)	printf("%d ",a[i][j]);
			printf("\n");
		}
		diag=0;
		ans=0;
		for(i=1;i<=(n+1)>>1;i++)
		{
			j=n-i+1;
			diag+=a[j][i];
			x=max(a[j-1][i],a[j-1][i-1]);
			y=max(a[j][i+1],a[j+1][i+1]);
			q=x+y+diag;
			if(q>ans)	ans=q;
			printf("%d %d %d\n",x,y,ans);
		}
		printf("%d\n",ans);
	}	
	return 0;
}