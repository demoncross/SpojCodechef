#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

char s[105][105];
vector<int> list[10004];
int visited[10004],parent[10004];

void bfs(int node)
{
	queue<int> q;
	int t,i;
	q.push(node);
	visited[node]=1;
	parent[node]=-1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<list[t].size();i++)
		{
			if(!visited[list[t][i]])
			{
				q.push(list[t][i]);
				visited[list[t][i]]=1;
				parent[list[t][i]]=t;
			}
		}
	}
	return;
}
int main()
{
	int test,p,n,m,i,j,q,k,her,ex,c;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf(" %s",s[i]);
		scanf("%d",&k);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				q=i*m+j;
				list[q].clear();
				visited[q]=0;
				parent[q]=-1;
				if(s[i][j]=='M')	her=q;
				else if(s[i][j]=='*')	ex=q;
				if(j!=m-1 && s[i][j+1]!='X')
					list[q].push_back(q+1);
				if(j!=0 && s[i][j-1]!='X')
					list[q].push_back(q-1);
				if(i!=0 && s[i-1][j]!='X')
					list[q].push_back(q-m);
				if(i!=n-1 && s[i+1][j]!='X')
					list[q].push_back(q+m);
			}
		}
		bfs(her);
		c=0;
		p=parent[ex];
		while(p!=-1)
		{
			if((parent[p]==-1 && list[p].size()>=2)|| list[p].size()>2)
				c++;
			p=parent[p];
		}
		if(c==k)	printf("Impressed\n");
		else		printf("Oops!\n");
	}
	return 0;
}