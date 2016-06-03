#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>
#define mod 1000000007
 
using namespace std;
typedef long long int ll;
 
ll dp[105][205];
int a[200005];
ll pow2[200005];
 
template <class T> inline T read()
{
    T ret=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        ret=10*ret+c-48;
        c=getchar();
    }
    return ret;
}
 
int main()
{
	int test,n,i,j,req,cd;
	test=read<int>();
	ll add,ans;
	pow2[0]=1;
	for(i=1;i<=200000;i++)	pow2[i]=(pow2[i-1]<<1)%mod;
	while(test--)
	{
		for(i=0;i<=100;i++)
			for(j=0;j<=203;j++)
				dp[i][j]=0;
		n=read<int>();
		for(i=0;i<n;i++)
			a[i]=read<int>();
		dp[a[0]][201]=1;
		for(i=1;i<n;i++)
		{
			dp[a[i]][201]=(dp[a[i]][201]+1);
			for(j=a[i];j<=a[i]+99;j++)
			{
				cd=j-100;
				req=a[i]-cd;
				if(j==100 || req<1 || req>100)	continue;
				dp[a[i]][j]=(dp[a[i]][j]+dp[req][201]+dp[req][j])%mod;
			}
		}
		ans=0;
		for(i=1;i<=100;i++)
			for(j=0;j<=200;j++)
				ans=(ans+dp[i][j])%mod;
		for(i=1;i<=100;i++)
		{
			add=((pow2[dp[i][201]]-1)+mod)%mod;
			ans=(ans+add)%mod;
		}
		ans=(pow2[n]-1-ans);
		while(ans<0)	ans+=mod;
		ans=(ans%mod);
		printf("%lld\n",ans);
	}
	return 0;
}  