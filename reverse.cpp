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
#define mod (1000000007)

using namespace std;
typedef long long int ll;

vector <int> list[100005],list_r[100005];
bool visited[100005];
int d[100005];
queue<int> Q;

void bfs(int node,int x)
{
	int i,z;
	visited[node]=1;
	d[node]=x;
	queue<int> qq;
	qq.push(node);
	Q.push(node);
	while(!qq.empty())
	{
		z=qq.front();
		qq.pop();
		for(i=0;i<list[z].size();i++)
		{
			if(!visited[list[z][i]])
			{
				visited[list[z][i]]=1;
				d[list[z][i]]=x;
				qq.push(list[z][i]);
				Q.push(list[z][i]);
			}
		}
	}
}

int main()
{
	int n,m,i,j,x,k,y;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		list[x].push_back(y);
		list_r[y].push_back(x);
	}
	for(i=1;i<=n;i++)	{visited[i]=0;d[i]=-1;}
	bfs(1,0);
	while(!Q.empty())
	{
		k=Q.size();
		for(i=0;i<k;i++)
		{
			x=Q.front();
			Q.pop();
			for(j=0;j<list_r[x].size();j++)
			{
				if(!visited[list_r[x][j]])	bfs(list_r[x][j],d[x]+1);
			}
		}
	}
	cout<<d[n]<<endl;
	return 0;
}