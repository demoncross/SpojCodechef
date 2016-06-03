// http:/ /www.hackerearth.com/remember-december/algorithm/sum-of-digits-8/
#include<stdio.h>
#include<string.h>
typedef long long int ll;
char a[20],b[20];
/*ll dp[17][150];
ll work(ll d,ll sum)
{
	ll i,ans;
	if(d==0)	return 0;
	else if(d==1)
	{
		if(sum<=9)	return 1;
		else		return 0;
	}
	ans=0;
	for(i=0;i<=9;i++)
	{
		if(i>sum)	return ans;
		ans+=work(d-1,sum-i);
	}
	return ans;
}*/
ll no_of_nums_less_than_equal(char *s,ll sum)
{
	ll ans,l,i;
	l=strlen(s);
	if(l==1)
	{
		if((s[0]-'0')>=sum)	return 1;
		else				return 0;
	}
	ans=0;
	for(i=0;i<=(s[0]-'0');i++)
	{
		if(i>sum)	return ans;
		ans+=no_of_nums_less_than_equal(s+1,sum-i);
	}
	return ans;
}
ll check(char *s,ll sum)
{
	ll ans=0,i,l=strlen(s);
	for(i=0;i<l;i++)
		ans+=s[i]-'0';
	return (ans==sum?1:0);
}
int main()
{
	ll l,i,sum,x,y,ans;
	scanf(" %s %s %lld",a,b,&sum);
	x=no_of_nums_less_than_equal(a,sum);
	y=no_of_nums_less_than_equal(b,sum);
	ans=y-x+check(a,sum);
	printf("%lld\n",ans);
	l=sum/9;
	if(sum%9)
		printf("%lld",sum%9);
	for(i=1;i<=l;i++)	printf("9");
	printf("\n");
	return 0;
}