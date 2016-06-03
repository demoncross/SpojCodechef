# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <queue>
# include <cmath>
# include <cstring>
# include <iostream>
# include <stack>
# include <map>
# include <vector>
# include <utility>
# include <set>
# include <deque>

# define MOD (1000000007)
# define MAXINT 1e9

using namespace std;
typedef long long int ll;

vector <pair<int,int> > factors_n;

void factorise(ll n, vector< pair<int,int> > &factors)
{
	ll x,i,c;
	factors.clear();
	x=sqrt(n);
	for(i=2;i<=x;i++)
	{
		if(n%i==0)
		{
			c=0;
			while(n%i==0)
			{
				n=n/i;
				c++;
			}
			factors.push_back(make_pair(i,c));
			if(n==1)	return;
		}
	}
	factors.push_back(make_pair(n,1));
}

int main()
{
	int q,i,x,y,t;
	ll n,k,ans;
	scanf("%lld%d",&n,&q);
	factorise(n,factors_n);
	while(q--)
	{
		scanf("%d%lld",&t,&k);
		if(t==1)
		{
			ans=1;
			for(x=0;x<factors_n.size();x++)
			{
				for(y=1;y<=factors_n[x].second;y++)
				{
					if(k%factors_n[x].first==0)
						k=k/factors_n[x].first;
					else
						break;
				}
				ans=ans*y;
			}
			printf("%lld\n",ans);
		}
		else
		{
			ans=1;
			for(x=0;x<factors_n.size();x++)
			{
				for(y=1;y<=factors_n[x].second;y++)
				{
					if(k%factors_n[x].first==0)
						k=k/factors_n[x].first;
					else
						break;
				}
				ans=ans*(factors_n[x].second-y+2);
			}
			if(k!=1)	ans=0;
			if(t==2){
			printf("%lld\n",ans);
			continue;}
			ll q=1;
			for(x=0;x<factors_n.size();x++)
				q=q*(factors_n[x].second+1);
			ans=q-ans;
			printf("%lld\n",ans);
		}
	}
	return 0;
}