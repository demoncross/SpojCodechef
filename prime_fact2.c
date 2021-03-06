//FACTORISING A NUMBER INTO ITS PRIME FACTORS--using SIEVES
#include<stdio.h>
#include<stdlib.h>
int * make_sieves(int n)
{
int i,j;
int *a=(int *)malloc(sizeof(int)*(n+2));
for(i=0;i<=n;i++)	
	a[i]=0;	
a[0]=1;
a[1]=1;
for(i=2;i<=n;i++)
{
	if(a[i]==0)
	{
		a[i]=i;		
		for(j=i;j*i<=n;j++)
			a[i*j]=i;
	}
}
return a;
}
int main()
{
int n,i,j,p;
printf("\nENTER A INTEGER:\n");
scanf("%d",&n);
int *a=make_sieves(n);
while(n>1)
{
	p=a[n];
	for(i=0;(n%p)==0;i++)	n=n/p;
	printf("%d %d\n",p,i);
}
return 0;
}

