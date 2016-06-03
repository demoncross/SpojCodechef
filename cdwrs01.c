#include<stdio.h>
#include<math.h>
int main()
{
double a,b;
int n,test;
scanf("%d\n",&test);
a=sqrt(2);
while(test--)
{
scanf("%d",&n);
b=a*n;
printf("%0.6lf\n",b);
}
return 0;
}
