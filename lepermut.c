#include<stdio.h>
int a[105];
int main()
{
int i,t,n;
scanf("%d",&t);
while(t--)
{
	scanf("%d",&n);
	a[0]=-1000000000;
	for(i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(i=2;i<=n;i++)
	{
		if(a[i]>=a[i-1])	continue;
		if(a[i]>=a[i-2])	continue;
		else			{printf("NO\n");	break;}
	}
	if(i==n+1)	
		printf("YES\n");
}
return 0;
}
