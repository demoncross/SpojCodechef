#include<stdio.h>

int a[1000005];

int gcd(int a,int b)
{
if(b==0)	return a;
a=a%b;
return (gcd(b,a));
}


void sieve(void)
{
int i,j;
for(i=1;i<=1000000;i++)	a[i]=1;
for(i=2;i*i<=1000000;i++)
{
	if(a[i]==1){
	for(j=i;j*i<=1000000;j++)
	{
		if(a[i*j]==1)	a[i*j]=i;
	}}
}
}


int no_of_div(int n)
{
	int ans=1,div,ans_p;
	while(n!=1)
	{
		if(a[n]==1)	return ans*2;
		div=a[n];
		ans_p=0;
		while(n%div==0)
		{
			ans_p+=1;
			n=n/div;
		}
		ans*=(ans_p+1);
	}
	return ans;
}


int main()
{
int t,n,m;
sieve();
scanf("%d",&t);
while(t--)
{
	scanf("%d%d",&n,&m);
	printf("%d\n",no_of_div(gcd(n,m)));
}
return 0;
}
