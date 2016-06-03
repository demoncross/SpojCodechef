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
#include <utility>
#include <set>

#define MOD (1000000007)
#define MAXINT 1e9

using namespace std;
typedef long long int ll;

int list[17][4]={2,3,9,5,
				1,10,4,6,
				11,1,7,4,
				2,8,12,3,
				13,1,6,7,
				5,14,2,8,
				15,5,3,8,
				16,6,7,4,
				13,1,11,10,
				9,2,14,12,
				15,9,3,12,
				4,10,11,16,
				5,14,15,9,
				16,13,10,6,
				7,16,13,11,
				15,14,8,12};
int visited[1<<17];

void bfs(int state,int k)
{
	int i,j,x,make;
	visited[state]=k;
	
	queue<int> q;
	q.push(state);
	while(!q.empty())
	{
		state=q.front();
		q.pop();
		if(visited[state]==3)	return;
		for(i=0;i<16;i++)
		{
			if(state&(1<<i)==0)	continue;
			for(j=0;j<4;j++)
			{
				x=list[i][j];
				if(state&(1<<(x-1)))	continue;
				make=state;
				make^=(1<<i);
				make^=(1<<(x-1));
				if(visited[make]==-1)	
				{
					visited[make]=visited[state]+1;
					q.push(make);
				}
			}
		}	
	}
}

int main()
{
	int test,i,state,x,needed,j=1;
	needed=0x0000ff00;
	memset(visited,-1,sizeof(visited));
	scanf("%d",&test);
	bfs(needed,0);
	while(test--)
	{
		printf("Case #%d: ",j++);
		state=0;
		for(i=0;i<16;i++)
		{
			scanf("%d",&x);
			state|=(x<<i);
		}
		if(visited[state]!=-1 && visited[state]<=3)		printf("%d\n",visited[state]);
		else											printf("more\n");
	}
	return 0;
}