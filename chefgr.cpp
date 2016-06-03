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
int a[106];

int main()
{
	int n,m,test,ma,i,ans;
	cin>>test;
	while(test--)
	{
		cin>>n>>m;
		ma=-1;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			ma=max(a[i],ma);
		}
		ans=0;
		for(i=0;i<n;i++)
			ans+=ma-a[i];
		if(ans>m)	cout<<"No\n";
		else if((m-ans)%n)	cout<<"No\n";
		else		cout<<"Yes\n";
	}
	return 0;
}