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

using namespace std;
typedef long long int ll;


int main()
{
	ll test,n,ans;
	scanf("%lld",&test);
	while(test--)
	{
		scanf("%lld",&n);
		if(n==1)	printf("0\n");
		else if(n==2)	printf("4\n");
		else{
			ans=(2*n*(n-1)*(n-1))+(2*n*(n-1)*(n-2))+(n*(n-1)*(n-2)*(n-2))+(n*(n-1)*(n-2)*(n-3));
		printf("%lld\n",ans );
	}
	}
	return 0;
}