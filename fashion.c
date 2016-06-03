#include<stdio.h>
int men[1005],women[1005];
int n;
void sort(int *a,int start,int end)
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
sort(a,start,k-1);
sort(a,k+1,end);
}
int main()
{
int ans,test,i;
scanf("%d",&test);
while(test--)
{
ans=0;
scanf("%d",&n);
for(i=0;i<n;i++)	scanf("%d",&men[i]);
for(i=0;i<n;i++)	scanf("%d",&women[i]);
sort(men,0,n-1);
sort(women,0,n-1);
for(i=0;i<n;i++)	ans+=men[i]*women[i];
printf("%d\n",ans);
}
return 0;
}
