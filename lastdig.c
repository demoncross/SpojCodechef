#include<stdio.h>
int main()
{
int test,i,b,a,k;
int d[100];
scanf("%d",&test);
while(test--)
{
	k=1;
	scanf("%d %d",&a,&b);
	if(a==0)
	{
		printf("0\n");
		continue;
	}
	else if(a==1)
	{
		printf("1\n");
		continue;
	}
	else if(b==0)
	{
		printf("1\n");
	}
	else
	{
		d[0]=-1;
		for(i=0;k*a%10!=d[0];i++)
		{			
			k*=a;
			d[i]=k%10;
		}
		printf("%d\n",d[(b-1)%(i)]);
	}
}
return 0;
}
