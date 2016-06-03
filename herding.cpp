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

char s[1001][1005];
int visited[1001][1001]={0};
int main()
{
	int n,m,i,j,x,y,ans,path;
	cin>>n>>m;
	ans=0;
	path=1;
	for(i=0;i<n;i++)	scanf(" %s",s[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			x=i;y=j;
			while(!visited[x][y])
			{
				//cout<<x<<" "<<y<<endl;
				visited[x][y]=path;
				switch(s[x][y])
				{
					case 'N': x=x-1;break;
					case 'S': x=x+1;break;
					case 'E': y=y+1;break;
					case 'W': y=y-1;break;
				}
			}
			//cout<<endl;
			if(visited[x][y]==path)	ans++;
			path++;
		}
	}
	cout<<ans<<endl;
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)	cout<<visited[i][j]<<" ";
		cout<<endl;
	}*/
	return 0;
}