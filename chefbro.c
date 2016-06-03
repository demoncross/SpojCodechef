#include<stdio.h>
int dp[1005][1005];
int a[10];
int check(void)
{
	int i,j;
	for(i=0;i<=6;i++)
	{
		for(j=0;j<=5;j++)
		{
			if(a[j]==i)	break;
		}
		if(j==6)
			return i;
	}
}
int main()
{
int t,n,m,c,i,j,p,ans;
m=n=1004;
scanf("%d",&t);
		for(j=m;j>=1;j--)
		{
			for(i=n;i>=1;i--)
			{
				a[0]=((j+1<=m)?dp[i][j+1]:10000000);
				a[1]=((j+2<=m)?dp[i][j+2]:10000000);
				a[2]=((i+1<=n)?dp[i+1][j]:10000000);
				a[3]=((i+2<=n)?dp[i+2][j]:10000000);
				a[4]=((i+1<=n && j+1 <=m)?dp[i+1][j+1]:10000000);
				a[5]=((i+2<=n && j+2 <=m)?dp[i+2][j+2]:10000000);
				dp[i][j]=check();
			}
		}
while(t--)
{
	ans=0;
	scanf("%d",&c);

	for(p=0;p<c;p++)
	{
		scanf("%d%d",&n,&m);
		
		/*for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)	printf("%d ",dp[i][j]);
			printf("\n");
		}*/
		ans=ans^dp[1004-n+1][1004-m+1];
	}
	if(ans)
		printf("MasterChef\n");
	else
		printf("Football\n");
}
return 0;
}
