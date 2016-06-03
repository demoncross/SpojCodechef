#include<stdio.h>
int main()
{
int test,l,r,c,n,q,i;
scanf("%d",&test);
while(test--)
{
	scanf("%d%d%d",&n,&c,&q);
	for(i=0;i<q;i++)
	{
		scanf("%d%d",&l,&r);
		if(c>=l && c<=r)
			c=r-(c-l);
	}
	printf("%d\n",c);
}
return 0;
}

