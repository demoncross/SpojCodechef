#include<stdio.h>
int main()
{
int t,i;
long long int n,ans;
scanf("%d",&t);
while(t--)
{
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%*d");
	ans=(n*(n-1))/2;
	printf("%lld\n",ans);
}
return  0;
}
