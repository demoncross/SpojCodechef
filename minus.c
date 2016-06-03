#include<stdio.h>
int dp[100][20005];
int a[105];
int main()
{
	int n,m,q,l1,l2,i,j;
	scanf("%d %d",&n,&m);
	scanf("%d %d",i,j);
	m-=i-j;
	for(i=1;i<=n-2;i++)
		scanf("%d",&a[i]);
	dp[1][a[1]+10000]=1;
	dp[1][-a[1]+10000]=2;
	for(i=2;i<=n-1;i++)
	{
		for(j=0;<=20000;j++)
		{
			q=j-10000;
			l1=q-a[i];
			l2=q+a[i];
			if(l1<0)	l1+=10000;
			if(l2<0)	l2+=10000;
			if(l1>=0 && l1<=20000)
				dp[i][j]=(dp[i-1][l]?2:0);
			if(l2>=0 && l2<=20000)
				dp[i][j]=(dp[i-1][l]?1:0);
		}
	}
	printf("%d")
	return 0;
}