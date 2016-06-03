//SIEVEs OF ERATOSTHENES
//CALCULATES ALL THE PRIME NUMBERS IN THE FIRST N +VE INTEGERS
#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,j,n,count=0;
printf("\nENTER A INTEGER:\n");
scanf("%d",&n);
int *a=(int *)malloc(sizeof(int)*(n+2));
for(i=0;i<=n;i++)	
	a[i]=0;	//initialising array initially all are 0----representing prime
for(i=2;i*i<=n;i++)
{
	for(j=i;j*i<=n;j++)
		a[i*j]=-1;//-1 represents non prime
}
for(i=2;i<=n;i++)
{
	if(a[i]==0)
		count++;
}
printf("%d\n",count);
return 0;
}
