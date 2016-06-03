#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
char c[10005];
int main()
{
	int n,m,i,j,query,node,x,y;
	vector < vector<int> > v(10002);
	scanf("%d%d",&n,&m);
	if(m!=n-1)
		printf("NO");
	else{
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue <int> q;
	q.push(1);
	c[1]=1;
	while(!q.empty())
	{
		node=q.front();
		q.pop();
		for(i=0;i<v[node].size();i++)
		{
			query=v[node][i];
			if(!c[query])	
			{
				c[query]=1;
				q.push(query);
			}
		}			
	}
	for(i=1;i<=n;i++)	
	{
		if(c[i]==0)	break;
	}
	if(i==n+1)	printf("YES");
	else		printf("NO");
	}
	return 0;
}