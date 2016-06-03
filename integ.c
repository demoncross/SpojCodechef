#include<stdio.h>
#include<stdlib.h>
int *a;
int n;
#define MAX 327656	
void merge(int i,int j)
{
int *c,*d;
c=(int *)malloc(sizeof(int)*((n/2)+1));
d=(int *)malloc(sizeof(int)*((n/2)+1));
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
//free(c);
//free(d);
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
int i,j,made,cost,x;
scanf(" %d",&n);
a=(int *)malloc(sizeof(int)*n);
for(i=0;i<n;i++)	scanf(" %d",&a[i]);
scanf(" %d",&x);
cost=0;
made=0;
sort(0,n-1);
for(i=n-1;i>=0;)
{
	if(a[i]+made>=0)	i--;
	else
	{
		if(x<=i+1)
		{
			cost+=x;
			made++;
		}
		else
		{
			for(j=0;j<=i;j++)	cost=cost-a[j];
			cost=cost-(i+1)*made;
			break;
		}
	}
}
printf("%d\n",cost);
//free(a);
return 0;
}