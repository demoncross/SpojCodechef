#include<stdlib.h>
#include<stdio.h>
#define MAX 327656	
int *a;
int n;
void merge(int i,int j)
{
int *c,*d;
c=(int *)malloc(sizeof(int)*((n/2)+2));
d=(int *)malloc(sizeof(int)*((n/2)+2));
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
free(c);
free(d);
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
int m,i,j,max;
int *sum;
scanf(" %d %d",&n,&m);
a=(int *)malloc(sizeof(int)*n);
sum=(int *)malloc(sizeof(int)*(n+2));
for(i=0;i<n;i++)	scanf(" %d",&a[i]);
sort(0,n-1);
sum[0]=a[0];
for(i=1;i<n;i++)
sum[i]=sum[i-1]+a[i];
max=0;
for(i=1;i<n;i++)
{
if(sum[i-1]<=m)
	max=i+1;
else
{
	for(j=0;j<=i-1;j++)
	{
		if(sum[i-1]-sum[j]<=m)
		{
			if(max<i-j)
				{max=i-j;break;}
		}
	}
}
}
printf("%d\n",max);
free(a);
free(sum);
return 0;
}
