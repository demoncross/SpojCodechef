//diameter of a tree
#include<cstdio>
#include<queue>
using namespace std;
char s[1005][1005];
int adj_list[1000002][6];
// adj_list[i][0] stores the length of the list which is always <=4
// adj_list[i][5] stores the distance between i and the node on which bfs is performed
char c[1000005];
int bfs(int node,int *ans)
{
	int i,query,max=node,max_dist=1;
	for(i=1;i<=1000000;i++)	c[i]=0;
	queue <int> q;
	q.push(node);
	adj_list[node][5]=1;
	c[node]=1;
	while(!q.empty())
	{
		node=q.front();
		q.pop();
		for(i=1;i<=adj_list[node][0];i++)
		{
			query=adj_list[node][i];
			if(c[query]==0)
			{
				adj_list[query][5]=adj_list[node][5]+1;
				if(adj_list[query][5]>max_dist)
				{
					max_dist=adj_list[query][5];
					max=query;
				}
				q.push(query);
				c[query]=1;
			}
		}
	}
	*ans=max_dist;
	return (max);
}
int main()
{
	int t,i,j,n,m,ans,node;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(i=1;i<=n;i++)	scanf("%s",s[i]+1);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(s[i][j]=='.')
				{
					node=((i-1)*m)+j;
					adj_list[node][0]=0;
					if(j<m && s[i][j+1]=='.')
						adj_list[node][++adj_list[node][0]]=node+1;
					if(j>1 && s[i][j-1]=='.')
						adj_list[node][++adj_list[node][0]]=node-1;
					if(i>1 && s[i-1][j]=='.')
						adj_list[node][++adj_list[node][0]]=node-m;
					if(i<n && s[i+1][j]=='.')
						adj_list[node][++adj_list[node][0]]=node+m;
				}
			}
		}
		int ans;
		node=bfs(node,&ans);
		node=bfs(node,&ans);
		printf("Maximum rope length is %d.\n",ans-1);
	}
	return 0;
}