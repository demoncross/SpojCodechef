#include<stdio.h>
int main()
{
int n,m,k,test;
scanf("%d",&test);
while(test-->0)
{
scanf("%d %d %d",&n,&m,&k);
if(k==1)
printf("1\n");
else if(n==1 && m==1)
printf("0\n");
else if(n==1 || m==1)
printf("%d\n",k);
else
printf("%d\n",(k%2==0?k/2:(k/2)+1));
}
return 0;
}
