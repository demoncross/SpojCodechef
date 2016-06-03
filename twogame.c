#include <stdio.h>
long long a[100];
void make(void)
{
	int i;
	a[0]=1;
	for(i=1;i<=64;i++)
	{
		a[i]=a[i-1]*2;
	}
}
int match(long long n)
{
	int i;
	for(i=0;i<=64;i++)
	{
		if(a[i]>n)	return 0;
		else if(a[i]==n)	return 1;
	}
}
int work(long long a,long long b)
{
	if(match(a) || match (b))	return 1;
	else if(a==0 || b==0)	return 0;
	else	return(work(b%a,a));
}
int main()
{
	int t;
	long long a,b,temp;
	make();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		if(work(a,b))	printf("Y\n");
		else			printf("N\n");
	}
}