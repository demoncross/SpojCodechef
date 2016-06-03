#include<stdio.h>
int a[1000005];
void work(void)
{
	int i,j;
	for(i=1;i<1000005;i++)	a[i]=i;
	for(i=2;i<=1000000;i++)
	{
		if(a[i]==i)
		{
			for(j=1;j*i<=1000000;j++)
			{
				a[i*j]=a[i*j]-(a[i*j]/i);
			}
		}
	}
}

int main()
{
int t,n;
scanf("%d",&t);
work();
while(t--)
{
	scanf("%d",&n);
	printf("%d\n",a[n]);
}
return 0;
}
