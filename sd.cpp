#include<cstdio>
#include<cmath>
using namespace std;
typedef long long int ll;
ll work(ll a,ll b)
{
	if(b==0)	return 1;
	ll ans=((a*a)%10,b>>1);
	printf("*%d\n",ans);
	if(b%2)	ans=(ans*a)%10;
	return ans;
}
int main()
{
	ll test,n,a,b;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",work(a%10,b));
	}
	return 0;
}