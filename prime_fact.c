#include<stdio.h>
int main()
{
int i,n;
printf("\nENTER THE NUMBER:\n");
scanf("%d",&n);
while(n%2==0)
{
	printf("2 ");
	n=n/2;
}
i=3;
while(i*i<=n)
{
	if(n%i==0)
	{
		printf("%d ",i);
		n=n/2;
	}
	i=i+2;
}
if(n>1)	printf("%d ",n);
printf("\n");
return 0;
}
