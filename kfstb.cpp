#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#define mod 1000000007

using namespace std;

vector < vector<int> > adj_list(10004);
char v[10004];
int ways[10004];
vector <int> topo_list;

int paths(int s,int f)
{
	int i,j,q,qq;
	for(i=0;i<topo_list.size();i++)
	{
		if(topo_list[i]==s)	break;
	}
	ways[s]=1;
	while(i<topo_list.size() && topo_list[i]!=f )
	{
		q=topo_list[i];
		for(j=0;j<adj_list[q].size();j++)
		{
			qq=adj_list[q][j];
			ways[qq]=(ways[qq]+ways[q])%mod;
		}
		i++;
	}
	return ways[f];
}

void topo_sort(int node)
{
	int i,q;
	v[node]=1;
	for(i=0;i<adj_list[node].size();i++)
	{
		q=adj_list[node][i];
		if(v[q])	continue;
		topo_sort(q);
	}
	topo_list.push_back(node);
}

int main()
{
	int test,n,e,s,f,i,x,y;
	scanf("%d",&test);
	while(test--)
	{
		topo_list.clear();
		scanf("%d%d%d%d",&n,&e,&s,&f);
		for(i=1;i<=n;i++)
		{
			adj_list[i].clear();
			ways[i]=v[i]=0;
		}
		for(i=0;i<e;i++)
		{
			scanf("%d%d",&x,&y);
			adj_list[x].push_back(y);
		}
		for(i=1;i<=n;i++)
		{
			if(v[i]==0)
				topo_sort(i);
		}
		reverse(topo_list.begin(),topo_list.end());
		printf("%d\n",paths(s,f));
	}
	return 0;
}