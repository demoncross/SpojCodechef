#include<stdio.h>
int main()
{
	long long int a[105],b[105],c[105],n,i;
	scanf("%lld",&n);
	while(n!=-1)
	{
		b[1]=c[2]=a[0]=1;
		a[1]=c[1]=0;
		for(i=2;i<=n;i++)
		{
			a[i]=a[i-2]+2*b[i-1];
			b[i]=c[i-1];
			c[i]=a[i]+b[i-1];
		}	
		printf("%lld\n",a[n]);
		scanf("%lld",&n);
	}
	return 0;
}