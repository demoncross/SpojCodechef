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

#define MOD (1000000009)
#define MAXINT 1e9

using namespace std;
typedef long long int ll;

vector<pair<int,char> > list;

int main()
{
	int test,n,m,y,i;
	char x;
	ll ans;
	scanf("%d",&test);
	while(test--)
	{
		list.clear();
		scanf(" %d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf(" %c %d",&x,&y);
			list.push_back(make_pair(y,x));
		}
		sort(list.begin(),list.end());
		ans=1;
		for(i=0;i<list.size();i++)
		{
			if(i==(list.size()-1))	continue;
			else if(list[i].second==list[i+1].second)	continue;
			ans=(ans*(list[i+1].first-list[i].first))%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}