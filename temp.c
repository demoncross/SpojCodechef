#include<stdio.h>
#define k 1000000007
long long int mod(int a)
{
int i,x,y,z;
long long int value=1;
x=a/30;
y=a%30;
z=(1<<30)%k;
for(i=1;i<=x;i++)
{
value=value*z;
value=value%k;
}
value=value*(1<<y);
value=value%k;
return value;
}
int main()
{
int test,n;
long long int p,ans;
scanf("%d",&test);
while(test-->0)
{
scanf("%d",&n);
if(n%2==0)
{
p=mod(n/2);
ans=(p+(p-1)*2)%k;
}
else
{
p=mod((n+1)/2);
ans=(p+(p/2-1)*2)%k;
}
printf("%lld\n",ans);
}
//printf("%lld\n",((1<<27)%k)*((1<<27)%k)%k);
return 0;
}
