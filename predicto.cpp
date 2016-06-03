#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[102][2],win[102],lose[102];
char s[102];
int main()
{
	int t,i,j,l,c,ic,q,ma;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&c,&ic);
		scanf("%s",s);
		l=strlen(s);
		dp[0][0]=dp[0][1]=0;
		win[0]=lose[0]=0;
		if(s[0]=='W')	
		{
			dp[1][0]=1;
			win[1]=1;
			lose[1]=dp[1][1]=0;
		}
		else
		{	
				dp[1][0]=win[1]=0;
				lose[1]=1;
				dp[1][1]=1;
		}
		for(i=2;i<=l;i++)
		{
			if(s[i-1]=='W')	
			{
				win[i]=win[i-1]+1;
				lose[i]=lose[i-1];
			}
			else
			{
				win[i]=win[i-1];
				lose[i]=lose[i-1]+1;
			}
		}
		for(i=2;i<=l;i++)
		{
			ma=-1;
			for(j=1;j<=c;j++)
			{
				if(i-j<0)	break;
				q=dp[i-j][1]+win[i]-win[i-j];
				if(q>ma)	ma=q;
			}
			dp[i][0]=ma;
			ma=-1;
			for(j=1;j<=ic;j++)
			{
				if(i-j<0)	break;
				q=dp[i-j][0]+lose[i]-lose[i-j];
				if(q>ma)	ma=q;
			}
			dp[i][1]=ma;
		}
		printf("%d\n",max(dp[l][0],dp[l][1]));
		//for(i=0;i<=l;i++)	printf("%d %d\n",dp[i][0],dp[i][1]);
	}
	return 0;
}