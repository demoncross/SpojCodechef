#include<stdio.h>
int main()
{
int i,n,test,ans,add,k;
scanf("%d",&test);
while(test-->0)
{
ans=0;
scanf("%d",&n);
for(i=0;i<=n;i++)
{
add=1;
k=n-i;
add=add<<(k/2);
ans+=add;
}
printf("%d\n",ans);
}
return 0;
}
