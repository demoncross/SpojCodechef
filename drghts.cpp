#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<stack>
#include<queue>

typedef long long int ll;
using namespace std;

ll visited[50005],window[50005];
ll a[50005][3];
vector < vector<ll> >adj_list(50005);
ll c=0;

ll work(ll n)
{
	ll l=0,j=c,t;
	ll i,below=0,q;
	visited[n]=1;
	for(i=0;i<adj_list[n].size();i++)
	{
		if(!visited[adj_list[n][i]])
		{
			c++;
			t=work(adj_list[n][i]);
			below+=t;
			if(t>0)	l++;
		}
	}
	a[j][0]=l;
	if(window[n])	a[j][1]=1;
	else			a[j][1]=0;
	a[j][2]=below;
	if(window[n])
		return(below+1);
	else
		return below;
}


int main()
{
	ll n,m,q,x,y,i,j,ans=0,b=0,tot_no_of_wins;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)	scanf("%lld",&window[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			tot_no_of_wins=work(i);
			for(j=0;j<=c;j++)
			{
				if(a[j][1]==1 && tot_no_of_wins>1)	b++;
				else if((a[j][1]==0 && a[j][0]>=2) || (a[j][1]==0 && a[j][0]>=1 && a[j][2]<tot_no_of_wins)) 	b++;
			}
			ans+=((tot_no_of_wins*(tot_no_of_wins-1))>>1);
			c=0;
		}
	}
	printf("%lld %lld",ans,b);
	return 0;
}