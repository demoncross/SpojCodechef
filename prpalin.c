#include<stdio.h>
#include<stdlib.h>
#define MAX 1005000
int palin(int n)
{
int i=0,j,r;
char s[10];
while(n>0)
{
r=n%10;
s[i]=r;
i++;
n=n/10;
}
for(j=0;j<i/2;j++)
{
if(s[j]!=s[i-j-1])	return 0;
}
return 1;
}
int main()
{
int i,j,n;
int *a=(int *)malloc(sizeof(int)*MAX);
for(i=0;i<MAX;i++)
	a[i]=1;
for(i=2;i*i<=MAX;i++)
{
if(a[i]==1)
{
for(j=i;j*i<=MAX;j++)
	a[j*i]=0;
}
}
scanf("%d",&n);
for(i=n;i<MAX;i++)
{
if(a[i]==1 && palin(i))
	{	
	printf("%d\n",i);
	break;
	}
}
free(a);
return 0;
}
