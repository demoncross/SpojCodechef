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

struct xx
{
	bool visited;
	int parent;
	int d;
}a[100005];

bool allowed[11];

void ou(int x)
{
	//cout<<x<<" ";
	if(a[x].parent==-1)
	{
		cout<<a[x].d;
		return;
	}
	ou(a[x].parent);
	cout<<a[x].d;
}

int main()
{
	int c=1,n,m,i,x;
	while(!cin.eof())
	{
		cin>>n;
		for(i=0;i<=n;i++)	a[i].visited=false;
		for(i=0;i<10;i++)	allowed[i]=1;
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>x;
			allowed[x]=0;
		}
		queue<int> q;
		for(i=1;i<10;i++)
		{
			m=i%n;
			if(allowed[i] && !a[m].visited)
			{
				a[m].visited=true;
				a[m].parent=-1;
				a[m].d=i;
				q.push(m);
			}
		}
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(i=0;i<10;i++)
			{
				m=((x*10)+i)%n;
				if(allowed[i] && !a[m].visited)
				{
					a[m].visited=true;
					a[m].d=i;
					a[m].parent=x;
					q.push(m);
				}
			}
		}
		cout<<"Case "<<c++<<": ";
		if(!a[0].visited)	cout<<"-1\n";
		else
		{
			ou(0);
			cout<<endl;
		}
	}
	return 0;
}