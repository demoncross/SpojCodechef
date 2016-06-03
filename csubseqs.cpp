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

char s[5][55];
ll dp[51][51][51][51][3];
int look_up[5][55][30];

void work(int a,int b,int c,int d)
{
	int i,m,n,o,p;
	ll x;
	if(dp[a][b][c][d][0])	return;
	dp[a][b][c][d][0]=1;
	dp[a][b][c][d][1]=0;
	for(i='a';i<='z';i++)
	{
		m=look_up[0][a][i-'a'];
		n=look_up[1][b][i-'a'];
		o=look_up[2][c][i-'a'];
		p=look_up[3][d][i-'a'];
		if(m==-1 || n==-1 || o==-1 || p==-1)	continue;
		else if(m==0 || n==0 || o==0 || p==0)
		{
			dp[a][b][c][d][1]++;
			//if(s[0][a+1]==i)	dp[a][b][c][d][2]=1;
			continue;
		}
		work(m-1,n-1,o-1,p-1);
		x=dp[m-1][n-1][o-1][p-1][1]+1;//-dp[m-1][n-1][o-1][p-1][2];
		dp[a][b][c][d][1]+=x;
		//if(i==s[0][a+1])	dp[a][b][c][d][2]=x;	
	}
}

int main()
{
	int i,j,k,l;
	for(i=0;i<4;i++)	scanf(" %s",s[i]);
	for(i=0;i<4;i++)
	{
		for(j='a';j<='z';j++)
			look_up[i][0][j-'a']=-1;
		look_up[i][0][s[i][0]-'a']=0;
	}
	for(i=0;i<4;i++)
	{
		l=strlen(s[i]);
		for(j=1;j<l;j++)
		{
			for(k='a';k<='z';k++)
				look_up[i][j][k-'a']=look_up[i][j-1][k-'a'];
			look_up[i][j][s[i][j]-'a']=j;
		}
	}	
	work(strlen(s[0])-1,strlen(s[1])-1,strlen(s[2])-1,strlen(s[3])-1);
	printf("%lld\n",dp[strlen(s[0])-1][strlen(s[1])-1][strlen(s[2])-1][strlen(s[3])-1][1]);
	return 0;
}