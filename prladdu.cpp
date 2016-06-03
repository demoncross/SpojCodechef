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
int a[10005];
vector<pair<int,int> > demons,villagers;
int main()
{
	ll ans;
	int n,test,i,l,j,x;
	cin>>test;
	while(test--)
	{
		cin>>n;
		villagers.clear();
		demons.clear();
		for(i=0;i<n;i++)
		{
			cin>>x;
			if(x<=0)
				demons.push_back(make_pair(i,-x));
			else
				villagers.push_back(make_pair(i,x));
		}
		ans=0;
		j=0;
		for(i=0;i<villagers.size();i++)
		{
			l=villagers[i].second;
			for(;j<demons.size() && l;j++)
			{
				if(demons[j].second<=l)
				{
					l=l-demons[j].second;
					ans=ans+demons[j].second*abs(demons[j].first-villagers[i].first);
				}
				else
				{
					ans=ans+l*abs(demons[j].first-villagers[i].first);
					demons[j].second-=l;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}