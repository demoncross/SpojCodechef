#include<stdlib.h>
#include<stdio.h>
int * sieve (int n)
{
int i,j;
int *a=(int *)malloc(sizeof(int)*(n+2));
for(i=0;i<=n;i++)	
	a[i]=0;	//initialising array initially all are 0----representing prime
for(i=2;i*i<=n;i++)
{
	for(j=i;j*i<=n;j++)
		a[i*j]=-1;//-1 represents non prime
}
return a;
}
int main()
{
int i,j,k,test,*si,*a,a1,a2;
scanf("%d",&test);
si=sieve(100002);
while(test-->0)
{
	scanf(" %d %d",&a1,&a2);
	a=(int *)malloc(sizeof(int)*(2+a2-a1));
	for(i=0;i<2+a2-a1;i++)	a[i]=0;
	for(i=2;i*i<=a2;i++)
	{
		if(si[i]==0)
		{
			j=(a1/i);
			if(j<2)	j=2;
			for(;;j++)
			{
				if(i*j>a2)	break;
				else if((i*j)<a1)	continue;
				a[(i*j)-a1]=-1;
			}
		}
	}
	for(i=0;i<a2-a1+1;i++)
	{
		if(a[i]==0&&(i+a1)!=1)
		printf("%d\n",i+a1);
	}
	printf("\n");
}
free(a);
free(si);
return 0;
}
