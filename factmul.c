#include<stdio.h>
long long int m =109546051211LL;
typedef long long int ll;
long long multi(long long a, long long b, long long c) // a * b % c
{
    if (b == 0) {
        return 0;
    }
    long long ret = multi(a, b >> 1, c);
    ret = (ret + ret) % c;
    if (b & 1) {
        ret = (ret + a) % c;
    }
    return ret;
}

ll mult(ll a,ll b,ll c)
{
	ll x,y,co1,co2;
	x=a;
	co1=co2=0;
	while(x>0)
	{
		co1++;
		x=x/10;
	}
	y=b;
	while(y>0)
	{
		co2++;
		y=y/10;
	}
	if(co1+co2<=18)	return ((a*b)%m);
	return multi(a,b,c);
}
int main()
{
unsigned long long int ans,last,fact;
int i,n;
scanf("%d",&n);
//if(n>=587117)	printf("0\n");
//else{
ans=1;
last=1;
for(i=2;i<=n;i++)
{
	fact=(last*i)%m;
	ans=(ans*fact)%m;
	//ans=mult(fact,ans,m);
	last=fact;
}
printf("%lld\n",ans);//}
return 0;
}