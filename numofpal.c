#include<stdio.h>
#include<string.h>
int dp[1005][1005];
char s[1005];
int main()
{
int len,l,i,start,end,ans=0;
scanf("%s",s);
len=strlen(s);
for(i=0;i<len;i++)	dp[i][i]=1;
ans+=len;
for(l=2;l<=len;l++)
{
	for(start=0;start<=len-l;start++)
	{
		end=start+l-1;
		if(s[start]==s[end])
		{
			if(l==2)
			{
				dp[start][end]=1;
				ans++;
			}
			else if(dp[start+1][end-1])
			{
				dp[start][end]=1;
				ans++;
			}
		}
	}
}
printf("%d\n",ans);
return 0;
}
