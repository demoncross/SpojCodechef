#include<stdio.h>
int main()
{
int test,n,i,j;
long long int q,m,temp,a[7];
scanf("%d",&test);
while(test-->0)
{
q=0;
scanf(" %d %lld",&n,&m);
for(i=0;i<n;i++)
scanf("%lld",&a[i]);
for(i=0;i<n;i++)
{
for(j=0;j<i;j++)
{
if(a[i]<a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
if(a[n-1]>=m) {printf("1\n"); continue;}
for(i=n-1;i>=0;i--)
{
q=q+a[i];
if(q>=m)
{
printf("%d\n",n-i);
break;
}
}
if(i==-1) printf("-1\n");
}
return 0;
}