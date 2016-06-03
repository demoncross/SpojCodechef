#include<stdio.h>
#define n 1000000
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
int search(int s,int e,int f)
{
int mid;
while(s<=e)
{
	mid=(s+e)/2;
	if(f==a[mid])	return mid;
	else if(f>a[mid])	s=mid+1;
	else			e=mid-1;
}
return -1;
}
int main()
{
int q,k,i,ans=0;
scanf("%d %d",&q,&k);
for(i=0;i<q;i++)	scanf("%d",&a[i]);
sort(0,q-1);
for(i=0;i<q;i++)
{
	ans+=(search(i+1,q-1,a[i]+k)!=-1)?1:0;
}
printf("%d\n",ans);
return 0;
}
