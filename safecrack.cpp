#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <utility>
#include <set>

#define MOD (1000000007)
#define MAXINT 1e9
using namespace std;
typedef long long int ll;
/*
ll m[10][10]={0};
ll ans[10][10]={0};

void mull(ll a[][10],ll b[][10])
{
	int i,j,k;
	ll x[10][10];
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			x[i][j]=0;
			for(k=0;k<10;k++)
				x[i][j]=(x[i][j]+(a[i][k]*b[k][j]))%MOD;
		}
	}
	for(i=0;i<10;i++)	for(j=0;j<10;j++)	ans[i][j]=x[i][j];
}

void expo(int n)
{
	if(n<=0)	return;
	expo(n/2);
	mull(ans,ans);
	if(n%2)	mull(ans,m);
}

int main()
{
	int test,n,i,j;
	ll a;
	m[0][7]=1;
	m[1][4]=m[1][2]=1;
	m[2][1]=m[2][3]=m[2][5]=1;
	m[3][2]=m[3][6]=1;
	m[4][1]=m[4][5]=m[4][7]=1;
	m[5][2]=m[5][4]=m[5][6]=m[5][8]=1;
	m[6][3]=m[6][5]=m[6][9]=1;
	m[7][0]=m[7][4]=m[7][8]=1;
	m[8][5]=m[8][7]=m[8][9]=1;
	m[9][6]=m[9][8]=1;
	cin>>test;
	while(test--)
	{
		cin>>n;
		for(i=0;i<10;i++)	for(j=0;j<10;j++)	ans[i][j]=0;
		for(i=0;i<10;i++)	ans[i][i]=1;
		expo(n-1);
		a=0;
		for(i=0;i<10;i++)	for(j=0;j<10;j++)	a=(a+ans[i][j])%MOD;
		printf("%lld\n",a);
	}
	return 0;
}*/
ll dp[100005][11];
int main()
{
	int i,j,n,test;
	ll ans;
	for(i=0;i<=9;i++)	dp[1][i]=1;
	for(i=2;i<=100000;i++)
	{
		dp[i][0]=(dp[i-1][7])%MOD;
		dp[i][1]=(dp[i-1][4]+dp[i-1][2])%MOD;
		dp[i][2]=(dp[i-1][1]+dp[i-1][3]+dp[i-1][5])%MOD;
		dp[i][3]=(dp[i-1][2]+dp[i-1][6])%MOD;
		dp[i][4]=(dp[i-1][1]+dp[i-1][5]+dp[i-1][7])%MOD;
		dp[i][5]=(dp[i-1][2]+dp[i-1][4]+dp[i-1][6]+dp[i-1][8])%MOD;
		dp[i][6]=(dp[i-1][3]+dp[i-1][5]+dp[i-1][9])%MOD;
		dp[i][7]=(dp[i-1][0]+dp[i-1][4]+dp[i-1][8])%MOD;
		dp[i][8]=(dp[i-1][5]+dp[i-1][7]+dp[i-1][9])%MOD;
		dp[i][9]=(dp[i-1][6]+dp[i-1][8])%MOD;
	}
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=0;i<=9;i++)	ans=(ans+dp[n][i])%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}