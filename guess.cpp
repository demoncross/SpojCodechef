#include<cstdio>
#include<cmath>

using namespace std;
typedef long long int ll;

ll gcd(ll x,ll y)
{
	if(x==0)	return y;
	return gcd(y%x,x);
}

int main()
{
	ll test,n,m,den,num,x;
	scanf("%lld",&test);
	while(test--)
	{
		scanf("%lld%lld",&n,&m);
		den=(n*m);
		num=((n/2)*(m-(m/2)))+((n-(n/2))*(m/2));
		x=gcd(num,den);
		printf("%lld/%lld\n",num/x,den/x);
	}
	return 0;
}