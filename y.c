#include<stdio.h>
int max(int a,int b)
{
	return (a>b?a:b);
}
char map[505][505];
int dp[505][505];
int main()
{
	int t,i,j,ans,q,n,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)	scanf("%s",map[i]);
		for(i=0;i<505;i++)
		{
			for(j=0;j<505;j++)	dp[i][j]=-1;
		}
		switch(map[0][0])
		{
			case '*': dp[0][0]=1;
					break;
			case '.':dp[0][0]=0;
					break;
			case '#':dp[0][0]=-1;
		}
		for(i=1;i<n;i++)
		{
			if(map[0][i]=='#' || dp[0][i-1]==-1)	break;
			dp[0][i]=dp[0][i-1]+(map[0][i]=='*'?1:0);
		}
		for(i=1;i<n;i++)
		{
			if(map[i][0]=='#' || dp[i-1][0]==-1)	break;
			dp[i][0]=dp[i-1][0]+(map[i][0]=='*'?1:0);
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				if(map[i][j]=='#')
					dp[i][j]=-1;
				else 
				{
					a=dp[i][j-1];
					b=dp[i-1][j];
					if(a==-1 && b==-1)	dp[i][j]=-1;
					else	dp[i][j]=max(a,b)+(map[i][j]=='*'?1:0);
				}
			}
		}
		printf("%d\n",dp[n-1][n-1]);
	}
	return 0;
}