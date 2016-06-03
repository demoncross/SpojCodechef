#include<stdio.h>
typedef struct ass
{
int fee,fun;
}node; 
node a[102];
node dp[102][505];
node max;
int main()
{
int n,i,j,budget,x,y;
while(1)
{
scanf(" %d %d",&budget,&n);
if(n==0 && budget==0)	break;
for(i=0;i<n;i++)
{
	scanf(" %d %d",&a[i].fee,&a[i].fun);
}max.fee=max.fun=0;
for(i=0;i<102;i++)
{
	for(j=0;j<505;j++)
		dp[i][j].fun=dp[i][j].fee=0;
}
for(i=1;i<=n;i++)
{
	for(j=0;j<=budget;j++)
	{
		if(j>=a[i-1].fee)
		{
			x=dp[i-1][j-a[i-1].fee].fun+a[i-1].fun;
			y=dp[i-1][j].fun;
			if(x>y){
				dp[i][j].fun=x;
				dp[i][j].fee=dp[i-1][j-a[i-1].fee].fee+a[i-1].fee;
			}
			else
			{
				dp[i][j].fun=y;
				dp[i][j].fee=dp[i-1][j].fee;
			}
		}
		else
		{
			dp[i][j]=dp[i-1][j];
		}
	}
}
for(j=0;j<=budget;j++)
{
	if(dp[n][j].fun>max.fun)
		max=dp[n][j];
}
printf("%d %d\n",max.fee,max.fun);	
}
return 0;
}
