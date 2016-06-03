#include<cstdio>
#include<vector>
#include<cstdlib>
#include<queue>
using namespace std;
vector <int> adj_list[105];
int c[105],n;
int a[105][105];
int work(int node)
{
	int i,rest,q;
	if(node>n)	return 1;
	if(c[node])	return	(work(node+1));
	for(i=0;i<adj_list[node].size();i++)
	{
		q=adj_list[node][i];
		if(c[q]==0)
		{
			c[node]=c[q]=1;
			rest=work(node+1);
			if(rest)	return 1;
			else	c[node]=c[q]=0;
		}
	}
	return 0;
}
int main()
{
	int t,i,x,y,m,j;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<=100;i++)	
		{
			c[i]=0;
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
		if(n%2)
		{
			printf("NO\n");
			continue;
		}
		if(!work(1))	printf("NO\n");
		else				printf("YES\n");
	}
	return 0;
}