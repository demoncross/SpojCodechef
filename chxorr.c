#include<stdio.h>
int a[2000];
int main()
{
int test,q,min,n,i,j,k;
scanf("%d",&test);
while(test--)
{
scanf(" %d",&n);
min=-1;
for(i=0;i<n;i++)
		scanf(" %d",&a[i]);
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
//if(i==j) continue;
for(k=j+1;k<n;k++)
{
//if(j==k||k==i) continue;
q=a[i]^a[j]^a[k];
if(min<q)	min=q;
}
}
}
if(min==-1)
printf("0\n");
else
printf("%d\n",min);
}
return 0;
}
