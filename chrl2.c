#include<stdio.h>
#include<string.h>
char s[100005];
int dp[4];
int main()
{
	int l,i;
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]=='C')
			dp[0]++;
		else if(s[i]=='H' && dp[0])
		{
			dp[0]--;
			dp[1]++;
		}
		else if(s[i]=='E' && dp[1])
		{
			dp[1]--;
			dp[2]++;
		}
		else if(s[i]=='F' && dp[2])
		{
			dp[2]--;
			dp[3]++;
		}
	}
	printf("%d\n",dp[3]);
	return 0;
}
