#include<cstdio>
#include<cmath>
using namespace std;
typedef unsigned long long int ll;
int is_perfect(double n)
{
	ll x=sqrt(n);
	double y=(double)x;
	return (n==(y*y));
}
int main()
{
	ll t;
	double a,b,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lf",&n);
		a=5*n*n-4;
		b=5*n*n+4;
		printf("%lf %lf\n",a,b);
		if(is_perfect(a)||is_perfect(b))
			printf("IsFibo\n");
		else
			printf("IsNotFibo\n");
	}
}