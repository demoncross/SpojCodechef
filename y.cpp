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
#define mod 1000000007

using namespace std;
typedef long long int ll;

int main()
{
	ll a=1024*1024*1024,b;
	for(int i=1;i<=63;i++){
		b=pow(a,((long double)1.00)/i);
		printf("%d %lld\n",i,b);}
	//printf("%lld %lld\n",((1000000000000000000LL)%mod),(((1000000000000000000LL)%mod)*(1000000000))%mod);
	return 0;
}

