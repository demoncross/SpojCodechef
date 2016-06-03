#include<stdio.h>
#include<string.h>
int dp[2005][2005];
char s[2005],t[2005];
int min(int a,int b,int c)
{
	if(a<=b && a<=c)	return a;
	else if(b<=c && b<=a)	return b;
	else			return c;
}
int main()
{
int i,j,l,m,test;
scanf("%d",&test);
while(test--)
{
	scanf(" %s %s",s,t);
	l=strlen(s);
	m=strlen(t);
	for(i=0;i<=l;i++){
		for(j=0;j<=m;j++)	dp[i][j]=0; 
		}
	for(i=0;i<=l;i++)
		dp[i][0]=i;
	for(i=0;i<=m;i++)
		dp[0][i]=i;
	for(i=1;i<=l;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s[i-1]==t[j-1])	dp[i][j]=dp[i-1][j-1];
			else		dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
		}
	}
	printf("%d\n",dp[l][m]);
}
return 0;
}
