#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#define si(i) scanf("%d",&i)
#define sl(i) scanf("%ld",&i)
#define sll(i) scanf("%lld",&i)
#ifndef ONLINE_JUDGE
    #define gc getchar
#else
    #define gc getchar_unlocked
#endif
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repi(i,a,b) for(int i=a;i>b;i--)
#define mod 1000000009


using namespace std;


template <class T> inline T read()
{
    T ret=0;
    int f=0;
    char c=gc();
    while(c!='-'&&(c<'0'||c>'9'))
        c=gc();
    if(c=='-')	{f=1;c=gc();}
    while(c>='0'&&c<='9')
    {
        ret=10*ret+c-48;
        c=gc();
    }
    if(f)
    return -ret;
	else	return ret;
}


int c[8000005];
int a[2000000];

int main()
{
	int test,ma,n,p,m,i;
	ll ans,x;
	scanf("%d",&test);
	while(test--)
	{
		n=read<int>();
		p=read<int>();
		m=100000000;
		for(i=1;i<n;i++)
		{
			x=read<ll>();
			a[i-1]=p-x;
			m=min(m,a[i-1]);
			p=x;
		}
		ma=0;
		for(i=0;i<n-1;i++)
		{
			a[i]-=m;
			ma=max(ma,a[i]);
		}
		ans=1;
		for(i=0;i<=ma;i++)	c[i]=0;
		ans=1;
		for(i=0;i<n-1;i++)
		{
			x=c[a[i]];
			c[a[i]]=ans;
			ans=(ans+ans-x);
			while(ans<0)	ans+=mod;
			ans=ans%mod;
		}
		printf("%lld\n",ans-1);
	}
}