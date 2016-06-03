# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <queue>
# include <cmath>
# include <cstring>
# include <iostream>
# include <stack>
# include <map>
# include <vector>
# include <utility>
# include <set>
# include <deque>

# define MOD (1000000007)
# define MAXINT 1e9

using namespace std;
typedef long long int ll;

bool b[16]={0};
ll ans[16][16],a[16][16];
ll dp[17];

void mul(ll x[][16],ll y[][16])
{
	ll temp[16][16],i,j,k;
	for(i=1;i<=15;i++)
	{
		for(j=1;j<=15;j++)
		{
			temp[i][j]=0;
			for(k=1;k<=15;k++)
				temp[i][j]=(temp[i][j]+(x[i][k]*y[k][j])%MOD)%MOD;
		}
	}
	for(i=1;i<=15;i++)	for(j=1;j<=15;j++)	ans[i][j]=temp[i][j];
}

void power(ll n)
{
	if(n==0)	return;
	power(n>>1);
	mul(ans,ans);
	if(n&1)	mul(ans,a);
}

int main()
{
	ll n,anss;
	int k,i,j,t;
	cin>>n;
	cin>>k;
	for(i=1;i<=k;i++)
	{
		cin>>t;
		a[1][t]=1;
	}
	dp[0]=1;
	for(i=1;i<=15;i++)
	{
		dp[i]=0;
		for(j=1;j<=15;j++)
		{
			if(a[1][j] && i-j>=0)	dp[i]+=dp[i-j];
		}
	}
	for(i=0;i<=15;i++) cout<<dp[i]<<" ";
		cout<<endl;
	if(n<=15)	cout<<dp[n]<<endl;
	else
	{
		for(i=0;i<=15;i++)	ans[i][i]=1;
		for(i=2;i<=15;i++)	a[i][i-1]=1;
		power(n-15);
		for(i=1;i<=15;i++)
		{
			for(j=1;j<=15;j++)	cout<<ans[i][j]<<" ";
			cout<<endl;
		}
		anss=0;
		for(i=1;i<=15;i++)
			anss=(anss+(ans[1][i]*dp[16-i])%MOD)%MOD;
		anss=anss*2;
		anss=anss%MOD;
		cout<<anss<<endl;
	}
	return 0;
}