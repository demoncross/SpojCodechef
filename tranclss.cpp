#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int list[105][105];
int visited[105],n;

int bfs(int node)
{
	queue <int> q;
	q.push(node);
	visited[node]=1;
	int i,qr,c=0,out,flag=0;
	while(!q.empty())
	{
		qr=q.front();
		q.pop();
		for(i=0;i<n;i++)
		{
			if(list[qr][i])
			{
				if(!visited[i])
				{
					visited[i]=1;
					c++;
					q.push(i);
				}
				if(i==node)	flag=1;
			}
		}
	}
	out=0;
	for(i=0;i<n;i++)	
	{
		if(list[node][i])
		{
			if(i==node)	flag=0;
			else		out++;
		}
	}
	//printf("%d %d\n",c,flag);
	return (c-out+flag);
}
int l[105];
int main()
{
	int t=1,test,x,y,i,j,ans;
	scanf("%d",&test);
	while(test--)
	{
		for(i=0;i<=100;i++)	{
			for(j=0;j<=100;j++) list[i][j]=0;
			l[i]=0;
		}
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			list[x][y]=1;
			l[x]=1;
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			if(l[i]==0)	continue;
			for(j=0;j<=n;j++)	visited[j]=0;
			ans+=bfs(i);
		}
		printf("Case #%d: %d\n",t++,ans);
	}
	return 0;
}