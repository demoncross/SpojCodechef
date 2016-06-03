#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
struct pa
{
	int length,start,end;
};
struct pa dp[505][505];
int main()
{
	int player1,player2,test,i,j,l,e;
	char s[505];
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",s);
		l=strlen(s);
		for(i=1;i<=l;i++)	{
			dp[i][i].length=1;
			dp[i][i].start=dp[i][i].end=i;
		}
		for(i=2;i<=l;i++)
		{
			for(j=1;j<=l-i+1;j++)
			{
				e=j+l-1;
				if(s[j-1]==s[e-1])
				{
					dp[j][e].start=i;
					dp[j][e].end=e;
					dp[j][e].length=dp[j+1][e-1].length+1;
				}
				else if(dp[j][e-1].length>dp[j+1][e].length)
				{
					dp[j][e].length=dp[j][e-1].length;
					dp[j][e].start=dp[j][e-1].start;
					dp[j][e].end=dp[j][e-1].end;
				}
				else if(dp[j][e-1].length<dp[j+1][e].length)
				{
					dp[j][e].length=dp[j+1][e].length;
					dp[j][e].start=dp[j+1][e].start;
					dp[j][e].end=dp[j+1][e].end;
				}
				else if(dp[j][e-1].length==dp[j+1][e].length)
				{
					dp[j][e].length=dp[j+1][e].length;
					if(s[dp[j][e-1].start-1]<s[dp[j+1][e].start-1])
					{
						dp[j][e].start=dp[j][e-1].start;
						dp[j][e].end=dp[j][e-1].end;
					}
					else
					{
						dp[j][e].start=dp[j+1][e].start;
						dp[j][e].end=dp[j+1][e].end;
					}
				}
			}
		}
		i=dp[1][l].start;
		j=dp[1][l].end;
		player1=player2=0;
		while(i<=j)
		{
			if(i%2==1)	player1++;
			else		player2++;
			if(j%2==1)	player1++;
			else		player2++;
			i=dp[i][j].start;
			j=dp[i][j].end;
		}
		printf("%d %d %d\n",dp[1][l].second,player1,player2);
	}
	return 0;
}