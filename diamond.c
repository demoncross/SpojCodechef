#include<stdio.h>
#define n 2000
unsigned short int a[n]={0};
double dp[n][n]={0};
int sum[n+1]={0};
int main()
{
int test,num,i,j,s;
scanf("%d",&test);
while(test-->0)
{
s=0;
scanf("%d",&num);
for(i=0;i<num;i++)
{
scanf("%d",&a[i]);
sum[i+1]=sum[i]+a[i];
dp[i][i]=(double)a[i];
}
for(i=2;i<=num;i++)
{
for(j=0;j<=num-i;j++)
{
dp[j][i+j-1]=(a[j]+a[i+j-1]-dp[j+1][i+j-1]-dp[j][i+j-2]+sum[i+j]-sum[j+1]+sum[i+j-1]-sum[j])/2;
}
}
printf("%.2f\n",dp[0][num-1]);
}
return 0;
}
