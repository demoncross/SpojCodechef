#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int dp[105][105][2];
char s[105],a[100];
int main()
{
	int t,i,j,k,l,len,no,yes,m;
	scanf("%d ",&t);
	while(t--)
	{
		scanf(" %[^\n]",s);
		len=strlen(s);
		j=0;
		for(i=0;i<len;i++)
		{
			if(s[i]=='T')
			{
				a[j]='1';
				dp[j][j][1]=1;
				dp[j][j][0]=0;
				j++;
				i+=1;
			}
			else if(s[i]=='F')
			{
				a[j]='0';
				dp[j][j][1]=0;
				dp[j][j][0]=1;
				j++;
				i+=1;
			}
			else if(s[i]=='a')
			{
				a[j]='&';
				j++;
				i+=3;
			}
			else if(s[i]=='o')
			{
				a[j]='|';
				j++;
				i+=2;
			}
			else
			{
				a[j]='^';
				j++;
				i+=3;
			}
		}
		a[j]=0;
		//printf("%s\n",a);
		for(l=3;l<=j;l+=2)
		{
			for(i=0;i<=j-l;i+=2)
			{
				k=i+l-1;
				yes=no=0;
				for(m=i+1;m<=k;m+=2)
				{
					if(a[m]=='&')
					{
						no+=(dp[i][m-1][0]+dp[i][m-1][1])*(dp[m+1][k][0]+dp[m+1][k][1])
							-dp[i][m-1][1]*dp[m+1][k][1];
						yes+=dp[i][m-1][1]*dp[m+1][k][1];
					}
					else if(a[m]=='|')
					{
						no+=dp[i][m-1][0]*dp[m+1][k][0];
						yes+=(dp[i][m-1][0]+dp[i][m-1][1])*(dp[m+1][k][0]+dp[m+1][k][1])
							-dp[i][m-1][0]*dp[m+1][k][0];
					}
					else
					{
						no+=dp[i][m-1][0]*dp[m+1][k][0]+dp[i][m-1][1]*dp[m+1][k][1];
						yes+=dp[i][m-1][0]*dp[m+1][k][1]+dp[i][m-1][1]*dp[m+1][k][0];
					}
				}
				dp[i][k][1]=yes;
				dp[i][k][0]=no;
			}
		}
		printf("%d\n",dp[0][j-1][1]);
	}
	return 0;
}