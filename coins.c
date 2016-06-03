#include<stdio.h>
long long dp[35][35];
void init()
{
	int i,j;
	for(i=0;i<35;i++)
	{
		for(j=0;j<35;j++)	dp[i][j]=0;
	}
}

long long work(int n,int a,int b)
{
	if(dp[a][b])	return dp[a][b];
	else if(n<=1)	return n;
	long long x=work(n/2,a+1,b)+work(n/4,a+2,b)+work(n/3,a,b+1);
	if(x>n)	dp[a][b]=x;
	else	dp[a][b]=n;
	return dp[a][b];
}

int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		init();
		printf("%lld\n",work(n,0,0));
	}
	return 0;
}
