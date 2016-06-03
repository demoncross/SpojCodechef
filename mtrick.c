#include<stdio.h>
typedef unsigned long long int ll;
ll l[1005];
char s[1005];
ll a,b,c,n;
int dig(ll x)
{
	int ans=0;
	while(x>0)
	{
		ans++;
		x/=10;
	}
	return ans;
}

ll f(ll x,ll y)
{
	ll ans,i,j,h;
	x%=c;
	y%=c;
	i=dig(x);
	j=dig(y);
	if(y==0 || x==0)	return 0;
	if(i+j<=19)
		return (x*y)%c;
	h=(c/x)+1;
	ans=(x*h)%c;
	ans=f(ans,(y/h));
	ans=(ans+f(x,y%h))%c;
	return ans;
}

int main()
{
	int t,k,i,po,j,temp;
	ll add,multiply,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)	scanf("%lld",&l[i]);
		scanf("%lld%lld%lld",&a,&b,&c);
		scanf("%s",s);
		j=n-1;
		k=1;
		i=-1;
		add=0;
		multiply=1;
		for(po=0;po<=n-1;po++)
		{
			i+=k;
			if(s[po]=='R')
			{
				temp=i;
				i=j;
				j=temp;
				k*=(-1);
			}
			else if(s[po]=='A')
			{
				add=(add+a)%c;
			}
			else
			{	
				multiply=f(multiply,b);
				add=f(add,b);
			}
			ans=f(l[i],multiply);
			ans=(ans+add)%c;
			printf("%lld ",ans);
		}
		printf("\n");
	}
	return 0;
}