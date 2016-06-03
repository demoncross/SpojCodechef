//SIEVEs OF ERATOSTHENES
//CALCULATES ALL THE PRIME NUMBERS IN THE FIRST N +VE INTEGERS
#include<stdio.h>
#include<stdlib.h>
int ar[100002]={0};
void create_sieve()
{
int i,j,n=100002;
for(i=2;i*i<=n;i++)
{
	for(j=i;j*i<=n;j++)
		ar[i*j]=-1;//-1 represents non prime
}/*
for(i=2;i<=n;i++)
{
	if(a[i]==0)
		printf("%d\n",i);
}*/
}
int main()
{
int i,a,b,j,test,count,*p;
create_sieve();
scanf("%d",&test);
while(test-->0)
{
	count=0;
	scanf(" %d %d",&a,&b);
	p=(int *)malloc((b-a+1)*sizeof(int));
	for(i=0;i<b-a+1;i++)
		p[i]=0; 	
	for(i=2;i*i<=b;i++)
	{
		if(ar[i]==-1)	continue;
		for(j=i;j*i<=b;j++)
		{
			if(i*j<a)	continue;
			p[(i*j)-a]=-1;
		}
	}
	for(i=0;i<b-a+1;i++)
		{
		if((p[i]==0&&(i+a)!=1)&&((a+i)%4==1||(a+i)==2))	count++; 
		//printf("%d ",a+i);
		}	
	//if(a==1)	count-=2;
	//if(count<0)	count=0;	
	printf("%d\n",count);
}
return 0;
}
