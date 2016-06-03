#include <stdio.h>
#define n 1000

int a[n];

void sort(int start,int end)
{
if(start>end) return;
int key,i,j,k;
key=a[end];
k=start;
for(i=start;i<end;i++)
{
if(a[i]<=key)
{
j=a[i];
a[i]=a[k];
a[k]=j;
k++;
}
}
j=a[end];
a[end]=a[k];
a[k]=j;
sort(start,k-1);
sort(k+1,end);
}

int main()
{
int num,i;
printf("\nenter the number of integers:\n");
scanf(" %d",&num);
printf("enter the integers:\n");
for(i=0;i<num;i++)
scanf(" %d",&a[i]);
sort(0,num-1);
printf("\nsorted form:\n");
for(i=0;i<num;i++)
printf("%d ",a[i]);
printf("\n");
return 0;
}
