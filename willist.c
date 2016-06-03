#include<stdio.h>
int main()
{
long long int n;
scanf("%lld",&n);
if(n==0 ||n==1)	printf("TAK");
else
{
while(n>1)
{
if(n%2!=0)	break;
n=n/2;
}
if(n>1)	printf("NIE");
else printf("TAK");
}
return 0;
}
