#include<stdio.h>
char a[100000000];
int si[5000006];
void sieve(void)
{
int i,j,z;
z=1;
for(i=0;i<=100000000;i++)
	a[i]=1;
for(i=2;i<=100000000;i++)
{
	if(a[i]==1)
	{
		si[z]=i;
		for(j=i;j*i<=100000000;j++)
			a[i*j]=0;
		z++;
	}
}
}
int main()
{
int q,n,i;
sieve();
scanf("%d",&q);
for(i=1;i<=q;i++)
{
	scanf("%d",&n);
	printf("%d\n",si[n]);
}
return 0;
}
