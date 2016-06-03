# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <queue>
# include <cmath>
# include <cstring>
# include <iostream>
# include <stack>
# include <map>
# include <vector>
# include <utility>
# include <set>
# include <deque>

# define MOD (1000000007)
# define MAXINT 1e9

using namespace std;
typedef long long int ll;

vector<int> list[100005];

struct xx
{
	int index;
	int value;
	int t1,t2;
}a[100005];



void dfs(int node)
{
	stack<int> s;
}

int main()
{
	cin>>n>>q;
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
	for(i=1li<=n;i++)	cin>>value[i];
	dfs(1);
	return 0;
}