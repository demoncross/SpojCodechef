#include<stdio.h>
#include<string.h>
int memo[2005][2005],chec[2005][2005],ended[2005][2005];
char str[2005];
void palin(int len)
{
int i,l,p,j;
for(i=0;i<len;i++)
	chec[i][i]=1;
for(l=2;l<=len;l++)
{
	for(i=0;i<=len-l;i++)
	{
		j=i+l-1;
		if(((l==2) && (str[i]==str[i+1])) || ((str[i]==str[j]) && (chec[i+1][j-1])))
			chec[i][j]=1;
		else
			chec[i][j]=0;
	}
}
for(i=0;i<len;i++)
{
	p=1;
	for(j=i;j<len;j++)
	{
		if(chec[i][j])
		{
			ended[i][p]=j;
			p++;
		}
	}
	ended[i][0]=p-1;
}
}
int work(int s,int e)
{
int i,q,min=10000000;
if(s==e)	return 1;
else if(s>e) return 0;
else if(memo[s][e]!=-1)	return memo[s][e];
else
{
	for(i=1;i<=ended[s][0];i++)
	{
		q=1+work(ended[s][i]+1,e);
		if(q<min)
			min=q;
	}
	memo[s][e]=min;
	return min;
}
}
int main()
{
int i,j,test;
scanf(" %d",&test);
while(test-->0)
{
scanf(" %s",str);
for(i=0;i<2005;i++)
{
	for(j=0;j<2005;j++)
	{
		chec[i][j]=ended[i][j]=0;
		memo[i][j]=-1;
	}
}
palin(strlen(str));
printf("%d\n",work(0,strlen(str)-1));
}
return 0;
}
