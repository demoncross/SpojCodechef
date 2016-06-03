#include<stdio.h>
char sieve[10000005];
int prime[10000];
void sievise(void)
{
int i,k,j,t,v;
for(i=0;i<10000005;i++)
	sieve[i]=1;
sieve[2]=sieve[3]=1;
for(i=2;i*i<=10000005;i++)
{
	if(sieve[i])
	{
		for(j=i;j*i<=10000005;j+=i)
		{
			//v=6-v;
			sieve[j*i]=0;
		}
	}
}
prime[1]=2;
prime[2]=3;
k=3;
t=4;
for(i=5;i<=10000;i+=1)
{
	t=6-t;
	if(sieve[i])
	{
		prime[k]=i;
		k++;
	}
}
prime[0]=k-1;
}
int main()
{
int i,n,test;
//printf("%d",sieve[11]);
sievise();
//for(i=0;i<100;i++)	printf("%d ",sieve[i]);
while(scanf("%d",&n)!=EOF)
{
	if(n==1)
	{
		printf("1\n");
		continue;
	}
	else if(sieve[n]==1)
	{
		printf("1 x %d\n",n);
		continue;	
	}	
	printf("1");
	for(i=1;i<=prime[0];i++)
	{
		if(sieve[n])	break;
		else if(n%prime[i]==0)
		{
			printf(" x %d",prime[i]);
			n=n/prime[i];
			i--;
		}
	}		
	if(n>1)	printf(" x %d\n",n);
	else	printf("\n");
}
return 0;
}
