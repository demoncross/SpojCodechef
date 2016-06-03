#include<stdio.h>
int main()
{
	long long int n,a[105],b[105],c[105],test,i,j;
	scanf("%lld",&test);
	for(j=1;j<=test;j++)
	{
		scanf("%lld",&n);
		a[0]=a[1]=b[1]=1;
		c[1]=1;
		c[0]=0;
		b[0]=0;
		for(i=2;i<=n;i++)
		{
			a[i]=a[i-1]+a[i-2]+b[i-1]+2*c[i-1];
			b[i]=a[i-1]+b[i-2];
			c[i]=a[i-1]+c[i-1];
		}
		printf("%lld %lld\n",j,a[n]);
	}
	return 0;
}