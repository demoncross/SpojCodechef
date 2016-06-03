#include<stdio.h>
#include<string.h>
#define n 1000
char str1[n],str2[n];
int dp[n][n],path[n][n];
int l1,l2;
void prin(int a, int b)
{
if(a==1 && dp[a][b]!=0)
{
printf("%c",str1[0]);
}
else if(b==1 && dp[a][b]!=0)
{
printf("%c",str2[0]);
}
else if(path[a][b]=='c')
{
prin(a-1,b-1);
printf("%c",str1[a-1]);
}
else if(path[a][b]=='l')
{
prin(a,b-1);
}
else if(path[a][b]=='u')
{
prin(a-1,b);
}
}
int main()
{
printf("\nenter the first string:\n");
scanf(" %s",str1);
printf("\nenter the second string:\n");
scanf(" %s",str2);
int i,j;
l1=strlen(str1);
l2=strlen(str2);
for(j=0;j<=l1;j++)
dp[j][0]=0;
for(j=0;j<=l2;j++)
dp[0][j]=0;
for(i=1;i<=l1;i++)
{
for(j=1;j<=l2;j++)
{
if(str1[i-1]==str2[j-1])
{
dp[i][j]=dp[i-1][j-1]+1;
path[i][j]='c';
}
if(dp[i][j]<dp[i-1][j])
{
dp[i][j]=dp[i-1][j];
path[i][j]='u';
}
if(dp[i][j]<dp[i][j-1])
{
dp[i][j]=dp[i][j-1];
path[i][j]='l';
}
//dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
}
}
printf("\nthe length of the lcs is %d\n",dp[l1][l2]);
printf("the lcs is:\n");
prin(l1,l2);
return 0;
}
