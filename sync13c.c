#include<stdio.h>
int main()
{
int t,n,m;
scanf("%d",&t);
while(t--)
{
	scanf("%d%d",&n,&m);
	if(n%2==0 || m%2==0)
		printf("Suresh\n");
	else
		printf("Ramesh\n");
}
return 0;
}
