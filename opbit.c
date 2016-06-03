#include<stdio.h>
#include<math.h>
int c[1005];
int main()
{
	int t,f1,f2,a,k,i,b,and,x,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		f1=sqrt(a);
		f2=sqrt(b);
		k=0;
		for(i=f1;i<=f2;i++)
			c[k++]=i*i;
		if(f1==f2)
			and=x=c[0];
		else
		{
			and=x=c[1]-c[0];
			for(i=2;i<k;i++)
			{
				d=c[i]-c[i-1];
				and=and&d;
				x=x^d;
			}
		}
		printf("%d\n",and&x);
	}
	return 0;
}