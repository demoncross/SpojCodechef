#include<stdio.h>
#define m 1000000007
long long int pow(int n)
{
long long int a;
	if(n==0)
		return 1;
	else if(n&1)
	{
		a=pow(n>>1);
		a=(a*a*2)%m;
		return a;
	}
	else
	{
		a=pow(n>>1);
		a=(a*a)%m;
		return a;
	}
}
int main()
{
int test,n;
scanf("%d",&test);
while(test--)
{
	scanf("%d",&n);
	printf("%lld\n",pow(n)-1);
}
return 0;
}
