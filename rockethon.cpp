#include<cstdio>
#include<cstring>
int dp[1003];
char s[1003];
int main()
{
	int i,j,l,ans=-1,max;
	scanf("%s",s);
	l=strlen(s);
	for(i=l-1;i>=0;i--)
	{
		max=0;
		for(j=i+1;j<=l-1;j++)
		{
			if(s[i]==s[j] && (j-i)%2 && dp[j]>max)	max=dp[j];
		}
		dp[i]=max+1;
		if(dp[i]>ans)	ans=dp[i];
	}
	printf("%d\n",ans);
	return 0;
}