#include<stdio.h>
int a[10000009]={1};
#define max 10000007
void sieve(void)
{
int i,j;
for(i=0;i<=max;i++)	a[i]=1;
for(i=2;i*i<=max;i++)
{
	if(a[i]==1)
	{
		for(j=i;j*i<=max;j++)
		{
			if(a[i*j]==1)	a[i*j]=i;
		}
	}
}
//for(i=2;i<=max;i++)	printf("%d ",a[i]);
}
int main()
{
int n,last,q,no,f,odd,even,test;
sieve();
scanf("%d",&test);
while(test--)
{
	scanf("%d",&n);
	no=0;
	odd=even=0;
	last=a[n];
	f=0;
	while(1)
	{
		q=a[n];
		if(q==1)
		{
			if(n==last)
			{
				no++;
				if(no%2==1)	odd++;
				else		even++;
			}
			else
			{
				odd++;
				if(no%2==1)	odd++;
				else		even++;
			}
			break;
		}
		if(q==last)
			no++;
		else if(no%2==1)
		{
			odd++;
			last=q;
			no=1;
		}
		else if(no%2==0)
		{
			even++;
			last=q;
			no=1;
		}
		n=n/a[n];
	}
	if(odd<even)
		printf("Psycho Number\n");
	else
		printf("Ordinary Number\n");
		
}
return 0;
}


