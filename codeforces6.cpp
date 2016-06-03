//http://codeforces.com/contest/1/problem/A
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	long long int x,y,n,m,a;
	scanf("%lld%lld%lld",&n,&m,&a);
	x=(n/a)+(n%a?1:0);
	y=(m/a)+(m%a?1:0);
	printf("%lld\n",x*y);
	return 0;
}