#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	return (a>b?a:b);
}
int min(int a,int b)
{
	return (a<b?a:b);
}
char map[55][55];
int dp[55][55];
int main()
{
int h,w,i,j,k,ans,p=1;
scanf("%d %d",&h,&w);
while(h)
{
	for(i=0;i<h;i++)
		scanf("%s",map[i]);
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			dp[i][j]=(map[i][j]=='A')?1:0;
		}
	}
	for(i='A';i<'Z';i++)
	{
		for(j=0;j<h;j++)
		{
			for(k=0;k<w;k++)
			{
				if(map[j][k]==i && dp[j][k])
				{
					if(j-1>=0 && k-1>=0 && map[j-1][k-1]==i+1)
						dp[j-1][k-1]=max(dp[j-1][k-1],dp[j][k]+1);
					if(j-1>=0 && k>=0 && map[j-1][k]==i+1)
						dp[j-1][k]=max(dp[j-1][k],dp[j][k]+1);
					if(j-1>=0 && k+1<w && map[j-1][k+1]==i+1)
						dp[j-1][k+1]=max(dp[j-1][k+1],dp[j][k]+1);
					if(j>=0 && k+1<w && map[j][k+1]==i+1)
						dp[j][k+1]=max(dp[j][k+1],dp[j][k]+1);
					if(j+1<h && k+1<w && map[j+1][k+1]==i+1)
						dp[j+1][k+1]=max(dp[j+1][k+1],dp[j][k]+1);
					if(j+1<h && k<w && map[j+1][k]==i+1)
						dp[j+1][k]=max(dp[j+1][k],dp[j][k]+1);
					if(j+1<h && k-1>=0 && map[j+1][k-1]==i+1)
						dp[j+1][k-1]=max(dp[j+1][k-1],dp[j][k]+1);
					if(j>=0 && k-1>=0 && map[j][k-1]==i+1)
						dp[j][k-1]=max(dp[j][k-1],dp[j][k]+1);
				}
			}
		}
	}
	ans=0;
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			ans=max(dp[i][j],ans);
		}
	}
	printf("Case %d: %d\n",p,ans);
	p++;
	scanf("%d %d",&h,&w);
}
return 0;
}
