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

vector<int> list[10004];
int visited[10004];
int no[10004];
int ht;

void work(void)
{
	queue<int> q;
	int i,k;
	visited[1]=1;
	q.push(1);
	no[1]=1;
	ht=1;
	while(!q.empty())
	{
		k=q.front();
		q.pop();
		for(i=0;i<list[k].size();i++)
		{
			if(!visited[list[k][i]])
			{
				visited[list[k][i]]=visited[k]+1;
				no[visited[k]+1]++;
				q.push(list[k][i]);
				ht=max(ht,visited[k]+1);
			}
		}
	}
}

int main()
{
	int test,i,u,v,n;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		ht=0;
		for(i=1;i<=n;i++)
		{
			list[i].clear();
			visited[i]=0;
			no[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&u,&v);
			list[u].push_back(v);
			list[v].push_back(u);
		}
		work();
		int alice,bob,ans;
		alice=1;
		bob=ht;
		ans=0;
		no[ht+1]=0;
		while(1)
		{
			if(no[alice]==0)	break;
			ans++;
			no[alice]=0;
			alice++;
			if(no[bob]==0)	break;
			ans++;
			no[bob]--;
			if(no[bob]==0)	bob--;
		}
		printf("%d\n",ans);
	}
	return 0;
}