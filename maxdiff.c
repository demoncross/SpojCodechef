#include<stdio.h>
#include<stdlib.h>
#define MAXINT 10000000000000;
int main()
{
long long int i,j,test,sum,n,k;
long long int vals[101];
scanf("%lld",&test);
while(test-->0)
{
long long int dp[101][101]={0};
sum=0;
scanf(" %lld %lld",&n,&k);
for(i=0;i<n;i++)	
{
	scanf(" %lld",&vals[i]);
	sum+=vals[i];
}
if(k>(n/2))	k=n-k;
for(i=0;i<=n;i++)	dp[i][0]=0;
for(i=0;i<=k;i++)	dp[0][i]=0;
for(i=1;i<=n;i++)
{
	for(j=1;j<=i && j<=k;j++)
	{
		if(i>j)		
		dp[i][j]=dp[i-1][j];
		else
		dp[i][j]=MAXINT;
		if((dp[i-1][j-1]+vals[i-1])<dp[i][j])
		dp[i][j]=dp[i-1][j-1]+vals[i-1];
	}
}
/*for(i=0;i<=n;i++)
{
	for(j=0;j<=k;j++)	printf("%d ",dp[i][j]);
	printf("\n");
}*/
printf("%lld\n",sum-2*dp[n][k]);
}
return 0;
}
