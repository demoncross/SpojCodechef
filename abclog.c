#include<stdio.h>
long long int w(long long int n)
{
	long long int ans=0;
	while(n)
	{
		ans<<=1;
		if(n%2)
		{
			ans+=1;
		}
		n/=2;
	}
	return ans;
}
int main()
{
long long int n;
scanf("%lld",&n);
while(n!=-1)
{
	printf("%lld\n",w(n));
	scanf("%lld",&n);
}
return 0;
}