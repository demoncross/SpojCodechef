#include<stdio.h>
#include<string.h>
int main()
{
int i,l;
char s[30];
long long int dp[30]={0};
scanf("%s",s);
l=strlen(s);
if(l==1)
	printf("1");
else
{
	dp[0]=1;
	if((s[0]-'0')*10+s[1]-'0'==0)	dp[1]=1;
	if((s[0]-'0')*10+s[1]-'0'<=20 && s[0]!='0')
		dp[1]=2;
	else dp[1]=1;
	for(i=2;i<l;i++)
	{
		dp[i]=dp[i-1];
		if(s[i-1]!='0' && (s[i-1]-'0')*10+s[i]-'0'<=20)
			dp[i]+=dp[i-2];
	}
	printf("%lld\n",dp[l-1]);
}
return 0;
}
