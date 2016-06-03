#include<stdio.h>
#include<stdlib.h>
#define MAXINT 10000000000000;
long long int absdiff(int a,int b)
{
int d=a-b;
return d<0?-d:d;
}
int main()
{
long long int i,j,test,sum,n,k,a,b;
long long int vals[101];
scanf("%lld",&test);
while(test-->0)
{
long long int dp[101][101]={0};
sum=0;
scanf(" %lld",&n,&k);
for(i=0;i<n;i++)	
{
	scanf(" %lld",&vals[i]);
	sum+=vals[i];
}
k=(n+1)/2;
for(i=0;i<=n;i++)	dp[i][0]=0;
for(i=0;i<=k;i++)	dp[0][i]=0;
for(i=1;i<=n;i++)
{
	for(j=1;j<=i && j<=k;j++)
	{
		a=absdiff(dp[i-1][j],sum-dp[i-1][j]);
		b=absdiff(dp[i-1][j-1]+vals[i-1],sum-dp[i-1][j-1]-vals[i-1]);
		if(a<b)	dp[i][j]=dp[i-1][j];
		else	dp[i][j]=dp[i-1][j-1]+vals[i-1];	
	}
}
for(i=0;i<=n;i++)
{
	for(j=0;j<=k;j++)	printf("%d ",dp[i][j]);
	printf("\n");
}
printf("%lld\n",absdiff(sum-dp[n][k],dp[n][k]));
}
return 0;
}
