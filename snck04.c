#include<stdio.h>
#define max 1000000
long long int a[1000006];
void generate(void)
{
	int i,j,st1,st2;
	for(i=1;i<=max;i++)	a[i]=i;
	a[1]=0;
	for(i=2;i<=max;i++)
	{
		if(a[i]==i){
		for(j=1;j*i<=max;j++)
		{
			a[j*i]-=a[j*i]/i;	
		}
		}
	}
	//for(i=1;i<=max;i++)	a[i]-=1;
	st2=0;
	for(i=2;i<=max;i++)
	{
			a[i]=a[i]+a[i-1];
	}
}
int main()
{
	int t,n;
	generate();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",a[n]);
	}
	return 0;
}
