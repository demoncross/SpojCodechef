#include<stdio.h>
int a[1005];
int main()
{
int n,i,j,l,r,max=-1,q;
scanf("%d",&n);
for(i=0;i<n;i++)	scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
	q=0;
	for(j=i;j<n;j++)
	{
		q=q^a[j];
		if((q>max)||(q==max && (i<l || (i==l && j<r))))
		{
			max=q;
			l=i;
			r=j;
		}
	}
}
printf("%d\n%d %d\n",max,l+1,r+1);
return 0;
}
