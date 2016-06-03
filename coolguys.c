#include<stdio.h>

unsigned long long int find_gcd(unsigned long long int a,unsigned long long int b)
{
if(a==0)
	return b;
return find_gcd(b%a,a);
}
int main()
{
int test,b;
unsigned long long int count;
unsigned long long int gcd;
unsigned long long int s;
unsigned long long int n;
scanf("%d",&test);
while(test-->0)
{
count=0;
scanf(" %lld",&n);
for(b=1;b<=n/2;b++)
count+=(n/b);
count+=(n-(n/2));
s=n*n;
gcd=find_gcd(count,s);
printf("%lld/%lld\n",count/gcd,s/gcd);
}
return 0;
}
