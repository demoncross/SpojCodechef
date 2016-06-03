#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[100][100],ht[100];
int abs(int x)
{
	return (x<0?-x:x);
}
int main()
{
	int ans,test,i,j,k,n,w;
	float q;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		for(i=0;i<n;i++)	scanf("%d",&ht[i]);
		scanf("%d",&w);
		for(i=0;i<=ht[0];i++)	dp[0][i]=-1;
		dp[0][1]=0;
		for(i=1;i<n;i++)
		{
			for(j=0;j<=ht[i];j++)
			{
				dp[i][j]=-1;
				for(k=0;k<=ht[i-1];k++)
				{
					if(dp[i-1][k]==-1)	continue;
					q=((w*w)+(abs(k-j)*abs(k-j)));
					q=sqrt(q);
					q+=dp[i-1][k];
					if(dp[i][j]==-1 || dp[i][j]<q)	dp[i][j]=q;
				}
			}
		}
		ans=-1;
		for(i=1;i<=ht[n-1];i++)
		{
			if(dp[n-1][i]>ans)	ans=dp[n-1][i];
		}
		printf("%d\n",ans);
	}
	return 0;
}