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
#define mod 1000000007

using namespace std;
typedef long long int ll;
typedef struct nnode
{
	int data;
	nnode *one,*zero;
}node;

vector <pair<int,int> > list[100005];
int visited[100005];

void insert(node *root,int x,int level)
{
	while(level>=0)
	{
		int t=x&(1<<level);
		if(t)
		{
			if( root->one)	root=root->one;
			else
			{
				root->one=(node *)malloc(sizeof(node));
				root->one->data=1;
				root->one->one=root->one->zero=NULL;
				root=root->one;
			}
		}
		else
		{
			if( root->zero)	root=root->zero;
			else
			{
				root->zero=(node *)malloc(sizeof(node));
				root->zero->data=0;
				root->zero->one=root->zero->zero=NULL;
				root=root->zero;
			}	
		}
		level--;
	}
}

int maxxor(int *a,int n)
{
	int ma,i,l,level,one_waala,zero_waala;
	node *test,*root;
	ma=0;
	a[0]=0;
	for(i=1;i<=n;i++)	
	{
		if(a[i]>ma)	ma=a[i];
	}
	level=log2(ma);
	root=(node *)malloc(sizeof(node));
	root->data=0;
	root->one=root->zero=NULL;
	for(i=1;i<=n;i++)
		insert(root,a[i],level);
	test=root;
	level++;
	l=level;
	zero_waala=one_waala=0;
	while(level>=0)
	{
		zero_waala+=((test->data)<<level);
		if(test->zero)	test=test->zero;
		else if(test->one)			test=test->one;
		level--;
	}
	level=l;
	test=root;
	while(level>=0)
	{
		one_waala+=((test->data)<<level);
		if(test->one)	test=test->one;
		else if(test->zero)			test=test->zero;
		level--;
	}
	return (one_waala^zero_waala);
}

void bfs(int node)
{
	int i,x;
	visited[node]=0;
	queue<int> q;
	q.push(node);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(i=0;i<list[x].size();i++)
		{
			if(visited[list[x][i].first]==-1)
			{
				visited[list[x][i].first]=visited[x]^list[x][i].second;
				q.push(list[x][i].first);
			}
		}
	}
}

int main()
{
	int test,i,n,x,y,z;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		{
			visited[i]=-1;
			list[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			list[x].push_back(make_pair(y,z));
			list[y].push_back(make_pair(x,z));
		}
		bfs(1);
		//for(i=1;i<=n;i++)	printf("%d\n",visited[i]);
		printf("%d\n",maxxor(visited,n));
	}
	return 0;
}