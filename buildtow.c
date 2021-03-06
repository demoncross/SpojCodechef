#include<stdio.h>
typedef long long int ll;
ll a[2][2]={1,1,1,0};
ll ans[2][2];
void mull(ll a[2][2],ll b[2][2])
{
	ll c[2][2];
	c[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%1000000007;
	c[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%1000000007;
	c[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%1000000007;
	c[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%1000000007;
	ans[0][0]=c[0][0];
	ans[0][1]=c[0][1];
	ans[1][0]=c[1][0];
	ans[1][1]=c[1][1];
}
void power(ll n)
{
	if(n==0)	return;
	else if(n==1)	mull(ans,a);
	else if(n%2==1)
	{
		power(n/2);
		mull(ans,ans);
		mull(ans,a);
	}
	else
	{
		power(n/2);
		mull(ans,ans);
	}
}
int main()
{
int test,i,j;
ll a,b,n;
scanf("%d",&test);
while(test--)
{
	ans[0][0]=ans[1][1]=1;
	ans[0][1]=ans[1][0]=0;
	scanf("%lld",&n);
	power(n-1);
	a=(ans[0][0]*2+ans[0][1]*1)%1000000007;
	b=(ans[1][0]*2+ans[1][1]*1)%1000000007;
	printf("$%lld\n",((a*b-1)%1000000007));
}
return 0;
}
