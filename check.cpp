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
	int n,m,i,ans=0,mid,els;
	scanf("%d%d",&n,&m);
	for(i=1;;i++)
	{
		if(m*i>2*n-1)	break;
		mid=(m*i-1)>>1;
		els=(m*i+1)>>1;
		els=n-els;
		if(i*m>n)	ans+=els;
		else		ans+=mid;
	}
	printf("%d\n",ans);
	return 0;
}