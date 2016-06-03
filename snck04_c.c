#include<stdio.h>
 
long a[1000001]={0};
long long b[1000001]={0};
 
void init()
{
  a[1]=1;
  long i,j;
  for(i=2;i<=1000000;i++)
  {
	if(a[i]==0)
	 a[i]=i-1;
	else
	 continue;
	for(j=1;i*j<=1000000;j++)
	{
	  if(a[j] && !a[i*j])
	  {
		if(j%i)
		 a[i*j]=a[i]*a[j];
		else
		 a[i*j]=i*a[j];
	  }
	}
  }
 
 b[1]=0;
 for(i=2;i<=1000000;i++)
 {
  b[i]=b[i-1]+a[i];
 }
}
 
int main()
{
 init();
 int t;
 long n;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%ld",&n);
  printf("%lld\n",b[n]);
 }
return 0;
} 
