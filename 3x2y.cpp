#include<cstdio>
using namespace std;
typedef long long int ll;
ll f(ll x,ll y)
{
	if(x==0 && y==0)	return 0;
	if(x%3==0 && y%2==0)
		return f(x/3,y/2);
	else if(x%3==1 && y%2==0)	
		return (f(x/3,y/2)+1);
	else if(x%3==2 && y%2==0)
		return f(x/3,y/2);
	else if(x%3==0 && y%2==1)
		return (f(x/3,y/2)+1);
	else if(x%3==1 && y%2==1)
		return (f(x/3,y/2)+2);
	else
		return (f(x/3,y/2)+1);
}
int main()
{
	int t;
	ll x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",f(x,y));
	}
	return 0;
}