#include<stdio.h>
int main()
{
int test,no_g,no_mg,q,max_g,max_mg,i;
scanf("%d",&test);
while(test--)
{
	max_g=max_mg=-100000000;
	scanf("%d %d",&no_g,&no_mg);
	for(i=0;i<no_g;i++)
	{
		scanf("%d",&q);
		if(q>max_g)	max_g=q;
	}
	for(i=0;i<no_mg;i++)
	{
		scanf("%d",&q);
		if(q>max_mg)	max_mg=q;
	}
	if(max_g>=max_mg)	printf("Godzilla\n");
	else			printf("MechaGodzilla\n");
}
return 0;
}
