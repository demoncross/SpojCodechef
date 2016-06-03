#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
typedef long long int ll;
int a[1000000],b[1000000];
int temp[1000000];
pair<int,int> dp[1004][1005];
//first will indicate if that state of remainder is possible
// -1 means not possible, 1 means taking this then follow the path as indicated by the second, and 2 means forget this and just take the path
//second will indicate the path
int main()
{
	int test,n,i,j;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)	temp[i]=-1;
		for(i=0;i<n;i++)	scanf("%d",&a[i]);
		b[0]=temp[0]=0;
		for(i=1;i<=n;i++)	
		{
			b[i]=(b[i-1]+a[i-1])%n;
			if(temp[b[i]]==-1)	temp[b[i]]=i;
			else
			{
				printf("%d\n",i-temp[b[i]]);
				for(j=i;j>temp[b[i]];j--)	printf("%d ",j);
				printf("\n");
				break;
			}
		}
		/*scanf("%d",&n);
		if(n>1000){
			printf("-1\n");
			continue;}
		for(i=0;i<n;i++)	scanf("%d",&a[i]);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				dp[i][j].first=dp[i][j].second=-1;
		dp[0][a[0]%n].first=1;
		dp[0][a[0]%n].second=-1;
		for(i=1;i<n;i++)
		{
			dp[i][a[i]%n].first=1;
			dp[i][a[i]%n].second=-1;
			for(j=0;j<=n;j++)
			{
				if(dp[i-1][j].first==-1)	continue;
				dp[i][j].second=j;
				dp[i][j].first=2;
				dp[i][(j+a[i])%n].first=1;
				dp[i][(j+a[i])%n].second=j;
			}
		}
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d/%d ",dp[i][j].first,dp[i][j].second);
			printf("\n");
		}*/
		/*if(dp[n-1][0].first==-1)	{printf("-1\n");continue;}
		i=n-1;
		j=0;
		int c=0;
		while(j!=-1)
		{
			if(dp[i][j].first==1)
				temp[c++]=i+1;
			j=dp[i][j].second;
			i--;
		}
		printf("%d\n",c);
		for(i=0;i<c;i++)	printf("%d ",temp[i]);
		printf("\n");*/
	}
	return 0;
}