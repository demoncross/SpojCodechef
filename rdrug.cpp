#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long int ll;

vector <int> sorted(100005);
vector <int> component [100005];  
vector <int> list [100005];
int ans[100005];
bool visited [100005];
int mass [100005];
int no;

void bfs(int node)
{
	queue<int> q;
	int qr,i;
	q.push(node);
	visited[node]=1;
	component[no].push_back(mass[node]);
	while(!q.empty())
	{
		qr=q.front();
		q.pop();
		for(i=0;i<list[qr].size();i++)
		{
			if(!visited[list[qr][i]]){
				visited[list[qr][i]]=1;
				component[no].push_back(mass[list[qr][i]]);		
				q.push(list[qr][i]);
			}
		}
	}
	sort(component[no].begin(),component[no].end());
	return;
}

void mergei(int x,int siz)
{
	if(component[x].size()==1)	return;
	if(siz==0)
	{
		for(int i=1;i<component[x].size();i++)	sorted[i-1]=component[x][i];
		//for(int i=0;i<1;i++)		printf("%d\n",sorted[i]);
		return;
	}
	int p1=1,p2=0;
	for(int i=0;i<siz+component[x].size()-1;i++)
	{
		if(p1>=component[x].size() || component[x][p1]>sorted[p2])
		{
			ans[i]=sorted[p2];
			p2++;
		}
		else if(p2>=siz || component[x][p1]<=sorted[p2])
		{
			ans[i]=component[x][p1];
			p1++;
		}
	}
	for(int i=0;i<siz+component[x].size()-1;i++)
		printf("**%d\n",sorted[i]=ans[i]);
}

int main()
{
	int test,n,m,i,x,y,siz;
	ll ans;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)	list[i].clear(),visited[i]=0,component[i].clear();
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			list[x].push_back(y);
			list[y].push_back(x);
		}
		for(i=1;i<=n;i++)	scanf("%d",&mass[i]);
		no=0;
		for(i=1;i<=n;i++)
		{
			if(!visited[i])
			{
				no++;
				bfs(i);
			}
		}
		if(no==1)	{
			printf("0\n");
			continue;
		}
		sorted.clear();
		ans=0;
		vector <int> :: iterator it;
		siz=0;
		for(i=1;i<=no;i++)
		{
			ans+=component[i][0];
			//if(component[i].size()==1)	continue;
			/*it=sorted.end();
			copy(component[i].begin()+1,component[i].end(),sorted.end());
			inplace_merge(sorted.begin(),it,sorted.end());
			for(int j=0;j<sorted.size();j++)
				printf("%d ",sorted[j]);
			printf("\n");*/
			mergei(i,siz);
			siz+=component[i].size()-1;	
		}
		//printf("%d\n",siz);
		i=0;
		if(siz<no-2)
				printf("-1\n");
		else
		{
			for(i=0;i<no-2;i++)	ans+=sorted[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
