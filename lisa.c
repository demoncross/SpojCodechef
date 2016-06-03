#include<stdio.h>
#include<string.h>
typedef long long int ll;
typedef struct node
{
ll min;
ll max;
}t;
t dp[105][105];
char str[105];
int main()
{
int test,i,j,k,l,len;
ll q1;
ll q2;
ll min;
ll max;
scanf("%d",&test);
while(test--)
{
	scanf(" %s",str);
	len=strlen(str);
	if(len==1)
	{
		printf("%c\n",str[0]);
		continue;
	}
	for(i=0;i<len;i+=2)
	{
		dp[i][i].min=dp[i][i].max=str[i]-'0';
	}
	for(l=3;l<=len;l+=2)
	{
		for(i=0;i<=len-l;i+=2)
		{
			j=i+l-1;
			max=0;
			min=1000000000000000000;
			for(k=i;k<j;k+=2)
			{
				switch(str[k+1])
				{
					case '*': q1=dp[i][k].max*dp[k+2][j].max;
						  q2=dp[i][k].min*dp[k+2][j].min;
						  break;
					case '+': q1=dp[i][k].max+dp[k+2][j].max;
						  q2=dp[i][k].min+dp[k+2][j].min;
						  break;
				}
				if(max<q1)	max=q1;
				if(q2<min)	min=q2;
			}
			dp[i][j].max=max;dp[i][j].min=min;
		}
	}
//	printf("%lld %lld\n",dp[0][len-1].max,dp[0][len-1].min);
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)	printf("%lld ",dp[i][j].max);
		printf("\n");
	}
}
return 0;
}
