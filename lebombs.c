#include<stdio.h>
#include<string.h>
int main()
{
int n,test,count,i;
char s[1005];
scanf("%d",&test);
while(test-->0)
{
count=0;
scanf(" %d",&n);
scanf(" %s",s);
for(i=0;i<n;i++)
{
if(s[i]=='1'||(i!=0 && s[i-1]=='1')||(i!=n-1 && s[i+1]=='1'))	count++;
}
printf("%d\n",n-count);
}
return 0;
}
