#include<stdio.h>
typedef long long ll;
ll power(int n)
{
	if(n==0)	return 1;
	ll ans=power(n>>1);
	ans*=ans;
	if(n%2)
		ans<<=1;
	return ans;
}
int main()
{
int t,i,n;
ll ans;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
	scanf("%d",&n);
	ans=power(n+1)-1;
	printf("Case %d: %lld\n",i,ans);
}
return 0;
}
