#include<stdio.h>
#define k 1000000007
int main()
{
long long int i,j,test,temp,ans;
long long int a[3];
scanf("%lld",&test);
while(test-->0)
{
ans=1;
scanf(" %lld %lld %lld",&a[0],&a[1],&a[2]);
for(i=0;i<3;i++)
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
for(i=0;i<3;i++)
{
a[i]=(a[i]-i)%k;
ans=(ans*a[i])%k;
}
printf("%lld\n",ans);
}
return 0;
}
