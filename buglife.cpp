#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int adj_list[2005][2005];
char col[2005];
int main()
{
	queue <int> q;
	int x,t,i,k,j,a,node,b,flag,n,query,l;
	scanf("%d",&t);
	for(l=1;l<=t;l++)	
	{
		while(!q.empty())	q.pop();
		flag=0;
		for(i=0;i<2005;i++)	adj_list[i][0]=col[i]=0;
		scanf("%d%d",&n,&query);
		for(i=0;i<query;i++)
		{
			scanf("%d%d",&a,&b);
			k=++adj_list[a][0];
			adj_list[a][k]=b;
			k=++adj_list[b][0];
			adj_list[b][k]=a;
		}
		for(i=1;i<=n;i++)
		{
			while(!q.empty())	q.pop();
			if(col[i]==0)
			{
				q.push(i);
				col[i]=1;
				while(!q.empty())
				{
					node=q.front();
					q.pop();
					for(j=1;j<=adj_list[node][0];j++)
					{
						x = adj_list[node][j];
						if(col[x]==0)
						{
							col[x]=((col[node]==1)?2:1);
							q.push(x);
						}
						else if(col[x]==col[node])
						{
							flag=1;
							break;
						}
					}
					if(flag==1)	break;
				}
			}
			if(flag==1)	break;
		}
		if(flag==1)	printf("Scenario #%d:\nSuspicious bugs found!\n",l);
		else		printf("Scenario #%d:\nNo suspicious bugs found!\n",l);
	}
	return 0;
}