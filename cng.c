#include<stdio.h>
int min(int q,int w)
{
return (q<w?q:w);
}
int main()
{
int max,test,c,d,e,i;
scanf("%d",&test);
while(test-->0)
{
	scanf(" %d %d",&c,&d);
	e=min(c,d);
	max=e-1;
	if(e==2&&(c==3||d==2))
	{
		printf("1\n");
		continue;
	}
	for(i=e;i<10000000;i++)
	{
		if(i%c!=0 && i%d!=0)
		 max=i;
	}
	printf("%d\n",max);
}
return 0;
}
