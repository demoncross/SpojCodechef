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

char ma[100][100];
pair<int,int> list[20];
int ty[100][100];
int a[100];

int main()
{
	int test,n,m,x,y,i,j,k,f,l,p;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)	scanf("%s",&ma[i][1]);
		k=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(ma[i][j]=='L')	
				{
					list[k++]=make_pair(i,j);
					ty[i][j]=k-1;
				}
			}
		}
		k--;
		for(i=0;i<(1<<k);i++)
		{
			for(x=1;x<=m;x++)	a[x]=-1;
			for(j=0;j<k;j++)
			{
				if(i&(1<<j))
					a[list[j+1].second]=j+1;
			}
			for(x=1;x<=n;x++)
			{
				f=0;
				l=0;
				p=-1;
				for(y=1;y<=m;y++)
				{
					if(ma[x][y]=='E' && (a[y]==-1 || x>list[a[y]].first))	f=1;
					if(ma[x][y]=='L')	
					{
						int c=ty[x][y]-1;
						if(i&(1<<c))	continue;
						l++;p=y;
					}
				}
				//printf("%d %d %d %d\n",f,l,p,x);
				if(f==0 || l>=2)	continue;
				if(l==0)	break;
				for(y=1;y<=m;y++)
					if(ma[x][y]=='E' && (a[y]==-1 || x>list[a[y]].first))	break;
				if(p<y)	continue;
				for(y=p+1;y<=m;y++)	if(ma[x][y]=='E' && (a[y]==-1 || x>list[a[y]].first))	break;
				if(y!=m+1)	break;
			}
			if(x==n+1)	break;
		}
		if(i==(1<<k))	printf("Impossible\n");
		else			printf("Possible\n");
	}
	return 0;
}