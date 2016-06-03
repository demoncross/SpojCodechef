#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector <int> list[10004];
int n,visited[10004],d[10004];
int bfs(int node)
{
	int i,x,ma;
	queue <int> q;
	q.push(node);
	visited[node]=1;
	d[node]=0;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(i=0;i<list[x].size();i++)
		{
			if(!visited[list[x][i]])
			{
				visited[list[x][i]]=1;
				d[list[x][i]]=d[x]+1;
				q.push(list[x][i]);
			}
		}
	}
	ma=-1;
	for(i=1;i<=n;i++)
	{
		if(ma==-1 || d[i]>d[ma])	ma=i;
	} 
	return ma;
}
int main()
{
	int x,y,i;
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		list[x].push_back(y);
		list[y].push_back(x);
	}
	for(i=0;i<=n;i++)	visited[i]=0;
	x=bfs(1);
	//printf("%d\n",x);
	for(i=0;i<=n;i++)	visited[i]=0;
	x=bfs(x);
	printf("%d\n",d[x]);
	return 0;
} 