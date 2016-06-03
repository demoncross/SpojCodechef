#include<stdio.h>
int main()
{
float l,r,pi,a;
pi=3.1415926f;
scanf("%f",&l);
while(l)
{
	a=(l*l)/(2*pi);
	printf("%.2f\n",a);
	scanf("%f",&l);
}
return 0;
}
