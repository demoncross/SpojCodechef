#include<stdio.h>
int main()
{
long long int t;long long int n;long long int k;
scanf("%lld",&t);
while(t-->0)
{
scanf("%lld %lld",&n,&k);
if(n==0)
printf("0 0\n");
else if(k==0)
printf("0 %lld\n",n);
else
printf("%lld %lld\n",n/k,n%k);
}
return 0;
}
