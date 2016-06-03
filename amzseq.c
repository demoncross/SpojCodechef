#include<stdio.h>
int main()
{
unsigned long long int i,a,b,c,test,n,a2,a4,a6;

scanf("%lld",&n);
a2=a4=a6=1;
for(i=2;i<=n;i++)
{
a=a2;b=a4;c=a6;
a2=a+b;
a4=a+b+c;
a6=b+c;
}
printf("%lld\n",a2+a4+a6);

return 0;
}
