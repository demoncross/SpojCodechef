//http://codeforces.com/contest/392/problem/B
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll dp[50][4][4];
ll price[4][4];
ll work(ll n,ll s,ll e)
{
ll m,q1,q2;
if(n==0)	return 0;
if(dp[n][s][e]!=-1)	return dp[n][s][e];
m=6-s-e;
q1=work(n-1,s,m)+price[s][e]+work(n-1,m,e);
q2=work(n-1,s,e)+price[s][m]+work(n-1,e,s)+price[m][e]+work(n-1,s,e);
dp[n][s][e]=min(q1,q2);
return dp[n][s][e];
}
int main()
{
ll i,j,k,n;
for(i=0;i<=40;i++)
{
	for(j=0;j<=3;j++)
	{
		for(k=0;k<=3;k++)	dp[i][j][k]=-1;
	}
}
for(i=1;i<=3;i++)
{
	for(j=1;j<=3;j++)	scanf("%lld",&price[i][j]);
}
scanf("%lld",&n);
printf("%lld\n",work(n,1,3));
return 0;
}