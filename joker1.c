#include<stdio.h>
int a[100];
int main()
{
int test,n,i,j,min,q;
long long int ans;
scanf(" %d",&test);
while(test--)
{
	scanf(" %d",&n);
	for(i=0;i<n;i++)
		scanf(" %d",&a[i]);
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
				min=j;
		}
		q=a[min];
		a[min]=a[i];
		a[i]=q;
	}
	ans=1;
	for(i=0;i<n;i++)
		ans=(ans*(a[i]-i))%1000000007;
	printf("%lld\n",ans);
}
printf("KILL BATMAN\n");
return 0;
}
