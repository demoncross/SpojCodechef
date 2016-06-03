#include<stdio.h>
#include<string.h>
int main()
{
int dp[5005];
int l,a,b,q,i,ans;
char s[5005];
while(1)
{
	scanf(" %s",s);
	if(s[0]=='0')	break;
	l=strlen(s);
	if(l==1)
	{
		printf("1\n");
		continue;
	}
	dp[0]=1;
 	if(s[1]=='0' &&s[0]>'2')
	{
		printf("0\n");
		continue;
	}
	else if(s[1]=='0')
	{
		dp[1]=1;
	}
	else if(((s[0]-'0')*10+s[1]-'0')<=26)
	{
		dp[1]=2;
	}
	else
	{
		dp[1]=1;
	}
	for(i=2;i<l;i++)
	{
		if(s[i]=='0' && s[i-1]=='0')
		{
			printf("0\n");
			break;
		}
		else if(s[i]=='0')
		{
			if(s[i-1]>'2')
			{
				printf("0\n");
				break;
			}
			dp[i]=dp[i-2];
		}
		else if(s[i-1]=='0')
			dp[i]=dp[i-1];
		else if(((s[i-1]-'0')*10+s[i]-'0')<=26)
			dp[i]=dp[i-1]+dp[i-2];
		else
			dp[i]=dp[i-1];
	}
	if(i==l)
		printf("%d\n",dp[l-1]);	
}
return 0;
}
