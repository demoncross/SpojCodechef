#include<string.h>
#include<stdio.h>
char s[5005];
unsigned long long int dp[5005];
int main()
{
int l,i;
while(1)
{
	scanf("%s",s);
	l=strlen(s);
	if(s[0]=='0')	break;
	dp[0]=1;
	if(l==1)		{printf("1\n");continue;}
	if(s[1]=='0')	
	{
		if(s[0]<='2')	dp[1]=1;
		else 		{printf("0\n");continue;}
	}
	else if(((s[0]-'0')*10+s[1]-'0')<=26)	dp[1]=2;
	else dp[1]=1;
	for(i=2;i<l;i++)
	{
		dp[i]=0;
		if(s[i]!='0')	dp[i]+=dp[i-1];
		if(s[i-1]!='0' && ((s[i-1]-'0')*10+s[i]-'0')<=26)	dp[i]+=dp[i-2];
	}
	printf("%lld\n",dp[l-1]);
}
return 0;
}
