#include<stdio.h>
#define n 1024
int dp[n][10];
int a[n];
int main()
{
int b,c,m,r,l,i,j,num;
printf("\nenter the number of numbers:\n");
scanf("%d",&num);
for(i=0;i<num;i++)
scanf(" %d",&a[i]);
for(i=0;i<num;i++)
dp[i][0]=i;
for(j=1;1<<j<=num;j++)
{
for(i=0;(i+(1<<j)-1)<num;i++)
{
if(a[dp[i][j-1]]<=a[dp[i+(1<<(j-1))][j-1]])
dp[i][j]=dp[i][j-1];
else
dp[i][j]=dp[i+(1<<(j-1))][j-1];
}
}
printf("\nenter the query:\n");
scanf("%d %d",&l,&r);
j=0;
while((l+(1<<j)-1)<=r) j++;
m=l+(1<<(j-1))-1;
b=0;
while((r-(1<<b))>=m) b++;
c=r-(1<<b)+1;
if(a[dp[l][j-1]]<=a[dp[c][b]]) printf("\n%d\n",a[dp[l][j-1]]);
else printf("\n%d\n",a[dp[c][b]]);
return 0;
}
