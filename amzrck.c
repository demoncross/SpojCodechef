#include<stdio.h>
int main()
{
int test,i,n;
long long int with,without,k;
scanf("%d",&test);
while(test--)
{
	with=0;without=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=with;
		with=without;
		without+=k;
	}
	printf("%lld\n",with+without);
}
return 0;
}
