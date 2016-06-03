#include<stdio.h>
#include<stdlib.h>
long long  **allocate(long long  x,long long  y)
{
long long  **a,i;
a=(long long  **)malloc(x*sizeof(long long  *));
for(i=0;i<x;i++)
{
a[i]=(long long  *)malloc(y*sizeof(long long ));
}
return a;
}
void freea(long long  **a,long long  x)
{
long long  i;
for(i=0;i<x;i++)	free(a[i]);
}
long long  minimum(long long  a,long long  b)
{
return (a>b?b:a);
}
long long  main()
{
long long  i,j,m,n,temp,test,** prices, **discounts, **dp;
long long min;
scanf("%lld",&test);
while(test-->0)
{
scanf("%lld %lld",&n,&m);
prices=allocate(n,m);
for(i=0;i<n;i++)
{
	for(j=0;j<m;j++)	scanf(" %lld",&prices[i][j]);
}
discounts=allocate(n,m);
for(i=0;i<n;i++)
{
	for(j=0;j<m;j++)	scanf(" %lld",&discounts[i][j]);
}
dp=allocate(n,m);
min=100000000000000;
for(i=0;i<m;i++)
{
	if(prices[0][i]<min)	min=prices[0][i];
	dp[0][i]=prices[0][i];
}
for(i=1;i<n;i++)
{
	for(j=0;j<m;j++)
	{
		temp=prices[i][j]-discounts[i-1][j];
		if(temp<0)	temp=0;
		dp[i][j]=minimum(dp[i-1][j]+temp,min+prices[i][j]);
	}
	min=10000000000000;
	for(j=0;j<m;j++)
	{
		if(dp[i][j]<min)	min=dp[i][j];
	}
}
printf("%lld\n",min);
freea(dp,n);
freea(prices,n);
freea(discounts,n);
}
return 0;
}
