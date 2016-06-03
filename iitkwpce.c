#include<stdio.h>
#include<string.h>
char str[2005];
int dp[2005][2005];
int chec[2005][2005];
int check(int a,int b)
{
int i;
for(i=0;i<=(b-a-1)/2;i++)
{
	if(str[i+a]!=str[b-i])	return 0;
}
return 1;
}



int main()
{
int test,i,j,k,l,len,q,min;
scanf("%d",&test);
while(test-->0)
{
	scanf(" %s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		for(j=i;j<len;j++)
			chec[i][j]=check(i,j);
	}
	for(i=0;i<len;i++)	dp[i][i]=1;
	for(l=2;l<=len;l++)
	{
		for(i=0;i<=len-l;i++)
		{
			j=i+l-1;
			if(str[i]==str[j] && chec[i][j])	dp[i][j]=1;
			else
			{
				min=1000000;
				for(k=i;k<=j-1;k++)
				{
					q=dp[i][k]+dp[k+1][j];
					if(q<min)
						min=q;
				}
				dp[i][j]=min;
			}
		}
	}
	printf("%d\n",dp[0][len-1]);
}
return 0;
}
