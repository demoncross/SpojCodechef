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

int a[1000];
int main()
{
	int test,i,n,q,ans;
	cin>>test;
	while(test--)
	{
		cin>>n;
		for(i=0;i<n;i++)	cin>>a[i];
		sort(a,a+n);
		ans=MAXINT;
		for(i=0;i<n-1;i++)
		{
			q=a[i+1]-a[i];
			ans=min(q,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}