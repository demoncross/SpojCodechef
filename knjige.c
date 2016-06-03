#include<stdio.h>
int main()
{
int i,n,a[300001],look;
scanf("%d",&n);
for(i=0;i<n;i++)	scanf("%d",&a[i]);
look=n;
for(i=n-1;i>=0;i--)
{
	if(a[i]==look)	look--;
}	
printf("%d\n",look);
return 0;
}
