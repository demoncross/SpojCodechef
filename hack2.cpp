#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstdlib>
#include <fstream>
#define si(i) scanf("%d",&i)
#define sl(i) scanf("%ld",&i)
#define sll(i) scanf("%lld",&i)
#ifndef ONLINE_JUDGE
    #define gc getchar
#else
    #define gc getchar_unlocked
#endif
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repi(i,a,b) for(int i=a;i>b;i--)
#define MOD 1000000007
using namespace std;

int dp[1000002];

void make()
{
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    int a,b,c;
    for(int i=4;i<1000002;i++)
    {
        a=b=c=10000000;
        if(i%2==0)
            a=dp[i/2]+1;
        if(i%3==0)
            b=dp[i/3]+1;
        c=dp[i-1]+1;
        dp[i]=min(a,min(b,c));
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    make();
    rep(i,0,n)
    {
        int p;
        scanf("%d",&p);
        printf("%d\n",dp[p]);
    }
    return 0;
}
