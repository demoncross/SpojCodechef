#include<stdio.h>
int s[1005],l[1005];
int dp[1005][2];
//#define abs(x) (x>0?x:-x)
//#define max(x,y) (x>y?x:y)
int abs(int a)
{
	return (a<0?-a:a);
}
int max(int a,int b)
{
	return (a<b?b:a);
}
int main()
{
	int i,n,x,y,q1,q2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(x>y)
		{
			l[i]=x;s[i]=y;
		}
		else
		{
			l[i]=y;s[i]=x;
		}
	}
	dp[1][0]=s[1];
	dp[1][1]=l[1];
	for(i=2;i<=n;i++)
	{
		q1=dp[i-1][0]+s[i]+abs(l[i-1]-l[i]);
		q2=dp[i-1][1]+s[i]+abs(s[i-1]-l[i]);
		dp[i][0]=max(q1,q2);
		q1=dp[i-1][0]+l[i]+abs(l[i-1]-s[i]);
		q2=dp[i-1][1]+l[i]+abs(s[i-1]-s[i]);
		dp[i][1]=max(q1,q2);
	}
	printf("%d\n",max(dp[n][0],dp[n][1]));
	//for(i=1;i<=n;i++)	printf("%d %d\n",dp[i][0],dp[i][1]);
	return 0;
}