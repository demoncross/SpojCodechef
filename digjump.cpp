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
#define MAX 100000000

using namespace std;
typedef long long int ll;

vector<int> num[12];
int visited[1000006];
int all_taken[15];
int l;
char s[1000006];

void bfs(void)
{
	int i,qr;
	queue<int> q;
	q.push(0);
	visited[0]=0;
	while(!q.empty())
	{
		qr=q.front();
		q.pop();
		if(qr!=0 && visited[qr-1]==-1)
		{
			visited[qr-1]=visited[qr]+1;
			q.push(qr-1);
		}
		if(qr!=l-1 && visited[qr+1]==-1)
		{
			visited[qr+1]=visited[qr]+1;
			q.push(qr+1);
		}
		if(all_taken[s[qr]-'0']==-1)
		{
			for(i=0;i<num[s[qr]-'0'].size();i++)
			{
				if(visited[num[s[qr]-'0'][i]]==-1)
				{
					visited[num[s[qr]-'0'][i]]=visited[qr]+1;
					q.push(num[s[qr]-'0'][i]);	
				}
			}
			all_taken[s[qr]-'0']=1;
		}
	}
}

int main()
{
	int n,i,c;
	//scanf("%d",&n);
	scanf( " %s",s);
	l=strlen(s);
	for(i=0;i<l;i++)
		visited[i]=-1;
	for(i=0;i<l;i++)
	{
		c=s[i]-'0';
		num[c].push_back(i);
	}
	for(i=0;i<=10;i++)	all_taken[i]=-1;
	bfs();
	printf("%d\n",visited[l-1]);	
	return 0;
}