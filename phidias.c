#include<stdio.h>
#include<stdlib.h>
int dp[605][605];
int main()
{
	int test,i,j,k,min_w,min_h,w,h,wd,ht,n,q;
	scanf("%d",&test);
	while(test--)
	{
		for(i=1;i<=600;i++)	for(j=1;j<=600;j++)	dp[i][j]=-1;
		min_h=min_w=1000;
		scanf("%d%d",&w,&h);
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&wd,&ht);
			dp[wd][ht]=0;
			if(wd<min_w)	min_w=wd;
			if(ht<min_h)	min_h=ht;
		}
		dp[0][0]=0;
		for(i=1;i<=w;i++)
		{
			for(j=1;j<=h;j++)
			{
				if(i<min_w || j<min_h)	{dp[i][j]=i*j;
							continue;}
				if(dp[i][j]==0)	continue;
				dp[i][j]=100000000;
				for(k=1;k<=i;k++)
				{
					q=dp[k][j]+dp[i-k][j];
					if(q<dp[i][j])	dp[i][j]=q;
				}
				for(k=1;k<=j;k++)
				{
					q=dp[i][k]+dp[i][j-k];
					if(q<dp[i][j])	dp[i][j]=q;
				}
			}
		}
		//for(i=0;i<=w;i++){	for(j=0;j<=h;j++)	printf("%d ",dp[i][j]); printf("\n");}
		printf("%d\n",dp[w][h]);
	}
	return 0;
}