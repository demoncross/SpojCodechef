#include<stdio.h>
int dp[2010][2010];
int values[2010];
int cum[2010];
int main()
{
int i,j,l,n,a,b;
scanf(" %d",&n);
for(i=0;i<n;i++)
	scanf(" %d",&values[i]);
cum[0]=0;
for(i=1;i<=n;i++)
	cum[i]=cum[i-1]+values[i-1];
for(i=1;i<=n;i++)
	dp[i][i]=values[i-1];
for(l=2;l<=n;l++)
{
	for(i=1;i<=n-l+1;i++)
	{
		j=i+l-1;
		a=values[i-1]+dp[i+1][j]+cum[j]-cum[i];
		b=values[j-1]+dp[i][j-1]+cum[j-1]-cum[i-1];
		if(b>a)	dp[i][j]=b;
		else	dp[i][j]=a;
	}
}
printf("%d\n",dp[1][n]);
return 0;
}
