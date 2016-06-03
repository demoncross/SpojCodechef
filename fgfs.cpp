#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int test,n,k,i,ans,last_f,s,f,p;
	scanf("%d",&test);
	vector<pair<int,pair<int,int> > > v;
	while(test--)
	{
		v.clear();
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&s,&f,&p);
			v.push_back(make_pair(p,make_pair(f,s)));
		}
		sort(v.begin(),v.end());
		ans=0;
		vector<pair<int,pair<int,int> > > :: iterator j,x,last;
		last=v.begin();
		for(j=v.begin() ; j!=v.end();)
		{
			while(j!=v.end() && j->first==last->first)	j++;
			last_f=0;
			for(x=last;x<j;x++)
			{
				if(x->second.second >= last_f)
				{
					ans++;
					last_f=x->second.first;
				}
			}
			last=j;
		}
		printf("%d\n",ans);
	}
	return 0;
} 