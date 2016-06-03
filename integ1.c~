#include<stdlib.h>
#include<stdio.h>
#define n 100002
#define MAX 1000000004	
int a[n];
void merge(int i,int j)
{
int c[n],d[n];
int mid=(i+j)/2;
int k,h=0,g=0;
for(k=0;k<=mid-i;k++)
c[k]=a[i+k];
c[k]=MAX;
for(k=0;k<j-mid;k++)
d[k]=a[mid+1+k];
d[k]=MAX;
for(k=i;k<=j;k++)
{
if(c[g]<d[h])
{
a[k]=c[g];
g++;
}
else
{
a[k]=d[h];
h++;
}
}
}

int sort(int start,int end)
{
if(start==end)
return start;
sort(start,(start+end)/2);
sort((start+end)/2+1,end);
merge(start,end);
}

int main()
{
int i,j,q,x,k;
long long int cost=0;
scanf(" %d",&q);
for(i=0;i<q;i++)	scanf(" %d",&a[i]);
scanf(" %d",&x);
sort(0,q-1);
for(k=q-1;k>=0;k--)
{
	if(a[k]<0)	break;
}
if(k+1<x)
{
	for(i=0;i<=k;i++)	cost=cost-a[i];
}
else
{
	for(i=0;i<x-1;i++)	cost=cost-a[i];
	cost+=(x-1)*a[i];
	cost-=x*a[i];	
}
printf("%lld",cost);
return 0;
}
