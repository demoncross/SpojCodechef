#include<stdio.h>
int main()
{
int t,sum,a,i,n;
scanf("%d",&t);
while(t--)
{
	sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		sum+=a;
	}
	if(sum%n==0)	printf("%d\n",n);
	else if(n!=2)		printf("%d\n",n-1);
	else		printf("0\n");
}
return 0;
}
