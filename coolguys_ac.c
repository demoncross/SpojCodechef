#include<stdio.h>
unsigned long long int find_gcd(unsigned long long int a,unsigned long long int b)
{
if(a==0)
	return b;
return find_gcd(b%a,a);
}
int main()
{
unsigned long long int a,b,n,s,g,ans;
int test,i;
scanf("%d",&test);
while(test-->0)
{
	scanf(" %lld",&n);
	ans=n;
	a=n;
	b=n;
	for(i=2;(i*i)<=n;i++)
	{
		b=n/i;
		ans+=b+(a-b)*(i-1);
		a=b;
	}
	if(i-1!=b)
	{
		for(;i<=b;i++)
			ans+=n/i;
	}
	s=n*n;
	g=(find_gcd(ans,s));
	printf("%lld/%lld\n",ans/g,s/g);
}
return 0;
}
