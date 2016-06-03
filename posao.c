#include<stdio.h>
int main()
{
long long int n,k,ans;
scanf("%lld %lld",&n,&k);
if(k>=n)
{
	printf("%lld\n",2*n-1);
}
else
{
	ans=(n*n)-(k*(k+1));
	if(ans%k)
	{
		ans=(ans/k)+1;
	}
	else
		ans=(ans/k);
	ans+=2*k;
	printf("%lld\n",ans);
}
return 0;
}
