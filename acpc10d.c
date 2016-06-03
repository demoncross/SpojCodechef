#include<stdio.h>
int map[100008][3];
int dp[100008][3];
int min(int a,int b)
{
	return (a>b?b:a);
}
int min3(int a,int b,int c)
{
	if(a<=b)
	{
		if(c<=a)	return c;
		else 		return a;
	}
	else
	{
		if(c<=b)	return c;
		else		return b;
	}
}
int min4(int a,int b,int c,int d)
{
	if(a<=b)
	{
		if(a<=c)
		{
			if(a<=d)	return a;
			else 		return d;
		}
		else
		{
			if(c<=d)	return c;
			else		return d;
		}
	}
	else
	{
		if(b<=c)
		{
			if(b<=d)	return b;
			else		return d;
		}
		else
		{
			if(c<=d)	return c;
			else		return d;
		}
	}
	
}
int main()
{
int n,i,t;
scanf("%d",&n);
t=1;
while(n!=0)
{
for(i=0;i<n;i++)
	scanf("%d %d %d",&map[i][0],&map[i][1],&map[i][2]);
dp[1][0]=map[1][0]+map[0][1];
dp[0][1]=map[0][1];
dp[0][2]=map[0][1]+map[0][2];
dp[1][1]=min3(dp[1][0],dp[0][1],dp[0][2])+map[1][1];
dp[1][2]=min3(dp[1][1],dp[0][1],dp[0][2])+map[1][2];
for(i=2;i<n;i++)
{
	dp[i][0]=min(dp[i-1][0],dp[i-1][1])+map[i][0];
	dp[i][1]=min4(dp[i-1][0],dp[i-1][1],dp[i][0],dp[i-1][2])+map[i][1];
	dp[i][2]=min3(dp[i-1][2],dp[i-1][1],dp[i][1])+map[i][2];
}
printf("%d. %d\n",t,dp[n-1][1]);
t++;
scanf("%d",&n);
}
return 0;
}
