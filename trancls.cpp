#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;
char visited[2505];
vector<int> list[2505];

int bfs(int node)
{
	int c,qr,i;
	c=0;
	queue<int> q;
	visited[node]=1;
	q.push(node);
	while(!q.empty())
	{
		qr=q.front();
		q.pop();
		for(i=0;i<list[qr].size();i++)
		{
			if(!visited[list[qr][i]])
			{
				visited[list[qr][i]]=1;
				c++;
				q.push(list[qr][i]);
			}
		}
	}
	return c;
}

int main()
{
	ll test,n,m,x,a=1,y,i,j,c,ans;
	scanf("%lld",&test);
	while(test--)
	{
		for(i=0;i<=2500;i++)	list[i].clear();
		scanf("%lld%lld",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&x,&y);
			list[x].push_back(y);
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)	visited[j]=0;
			c=bfs(i);
			ans=(ans+c);
		}
		printf("%lld\n",ans);
		a++;
	}
	return 0;
}