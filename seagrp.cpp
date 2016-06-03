#include<cstdio>
#include<vector>
#include<cstdlib>
#include<queue>
using namespace std;
vector <int> adj_list[105];
int p[105],c[105];
int a[102][102];
int dp[105];
int work(int node)
{
	int i,q,j;
	int pair[105]={0},w[105]={0};
	if(dp[node]!=-1)	return dp[node];
	for(i=0;i<adj_list[node].size();i++)
	{
		q=adj_list[node][i];
		if(q==p[node])	continue;
		w[q]=work(q);
	}
	int k=0;
	for(i=0;i<adj_list[node].size();i++)
	{
		q=adj_list[node][i];
		if(q==p[node])	continue;
		if(w[q]==0 && k==0)
		{
			for(j=0;j<adj_list[q].size();j++)
			{
				if(adj_list[q][j]==q)	continue;
				if(!work(adj_list[q][j]))	break;
			}
			if(j==adj_list[q].size())
			{	
				pair[q]=1;
				k=1;
			}
			else						
			{
				pair[q]=0;
				dp[node]=0;
				return 0;
			}
		}
		else	
		{
			dp[node]=0;
			return 0;
		}
	}
	if(k==1)
		return (dp[node]=1);
	else
		return (dp[node]=0);
}


void bfs(int node)
{
	int i,query;
	queue <int> q;
	q.push(node);
	c[node]=1;
	p[node]=-1;
	while(!q.empty())
	{
		node=q.front();
		q.pop();
		for(i=0;i<adj_list[node].size();i++)
		{
			query=adj_list[node][i];
			if(c[query]==0)
			{
				c[query]=1;
				p[query]=node;
				q.push(query);
			}
		}
	}
}
int main()
{
	int t,i,x,y,n,m,j;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<=100;i++)	
		{
			c[i]=0;
			dp[i]=-1;
			adj_list[i].clear();
			for(j=0;j<=100;j++)	a[i][j]=0;
		}
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			if(a[x][y]==0 && a[y][x]==0)
			{
				adj_list[x].push_back(y);
				adj_list[y].push_back(x);
				a[x][y]=a[y][x]=1;
			}
		}
		vector <int> list;
		for(i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				list.push_back(i);
				bfs(i);
			}
		}
		for(i=0;i<list.size();i++)
		{
			if(!work(list[i]))	break;
		}
		if(i!=list.size())	printf("NO\n");
		else				printf("YES\n");
	}
	return 0;
}