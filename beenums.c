#include<float.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
int n,i;
double d,f;
while(1)
{
	scanf("%d",&n);
	if(n==-1)	break;
	if(n==1)	{printf("Y\n");continue;}
	d=9+12*(n-1);
	f=sqrt(d);
	f-=3;
	f/=6;
	i=f;
	if(f-i==0)	printf("Y\n");
	else		printf("N\n");
}
return 0;
}
