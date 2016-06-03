#include<stdio.h>
#include<math.h>
typedef long long int ll;
int main()
{
	int t;
	float l,d,s,c,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f%f%f%f",&l,&d,&s,&c);
		p=log(l/s)/log(1+c);
		if(p<=d-1)
			printf("ALIVE AND KICKING\n");
		else
			printf("DEAD AND ROTTING\n");
	}
	return 0;
}