#include<stdio.h>
int main()
{
int i,n,k,ans;
scanf("%d%d",&n,&k);
while(n!=0 && k!=0)
{
ans=1;
for(i=2;i<=n;i++)
	ans=(ans+k-1)%i+1;
printf("%d %d %d\n",n,k,ans);
scanf("%d%d",&n,&k);
}
return 0;
}
