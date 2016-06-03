#include<cstdio>
#include<deque>
#include<cstdlib>

typedef long long int ll;
using namespace std;

ll a[500005];
ll sum[500005];

int main()
{
	ll t,n,i,last_max_index,max_index,max_price,profit,no_of_shares,money_invested,money_returned;
	scanf("%lld",&t);
	while(t--)
	{
		deque < pair <int,int> > d;
		scanf("%lld",&n);
		a[0]=0;
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
			if(d.empty() || d.back().first>=a[i])	d.push_back(make_pair(a[i],i));
			else
			{
				while(!d.empty() && d.back().first<a[i])
					d.pop_back();
				d.push_back(make_pair(a[i],i));
			}
		}
		last_max_index=0;
		profit=0;
		//printf("%d\n",d.front().first);
		while(!d.empty())
		{
			pair<int,int> p=d.front();
			d.pop_front();
			max_index=p.second;
			max_price=p.first;
			money_invested=sum[max_index-1]-sum[last_max_index];
			no_of_shares=max_index-1-last_max_index;
			money_returned=no_of_shares*max_price;
			profit+=(money_returned-money_invested);
			last_max_index=max_index;
		}
		printf("%lld\n",profit);
	}
	return 0;
}
