#include<stdlib.h>
#include<stdio.h>
#define n 1000
#define MAX 327656	
int a[n];
void merge(int i,int j)
{
int c[1000],d[1000];
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
int i,num;
printf("\nenter the number of elements:\n");
scanf("%d",&num);
for(i=0;i<num;i++)
scanf(" %d",&a[i]);
sort(0,num-1);
for(i=0;i<num;i++)
printf("%d ",a[i]);
return 0;
}
