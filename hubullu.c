#include<stdio.h>
int main()
{
int t,c;
scanf("%d",&t);
while(t--)
{
	scanf("%*d%d",&c);
	if(c==0)	printf("Airborne wins.\n");
	else		printf("Pagfloyd wins.\n");
}
return 0;
}
