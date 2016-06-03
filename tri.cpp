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

vector < pair<int,int> > l;
int a[100005],b[100005],le[100005],ri[100005];
int tree[1000006];

void init(int node,int l,int r)
{
	if(l==r)
		tree[node]=0;
	else
	{
		int m=(l+r)>>1;
		int left=(node<<1);
		init(left,l,m);
		init(left+1,m+1,r);
		tree[node]=0;
	}
}

int query(int node,int n_l,int n_r,int q_l,int q_r)
{
	if(n_l>q_r || n_r<q_l)		return 0;
	if(n_l>=q_l && n_r<=q_r)	return tree[node];
	int m=(n_l+n_r)>>1;
	int left=(node<<1);
	int x=query(left,n_l,m,q_l,q_r);
	x+=query(left+1,m+1,n_r,q_l,q_r);
	return x;
}

void add(int node,int l,int r,int q)
{
	if(l==r)
	{
		if(r==q)
			tree[node]+=1;
		return;
	}
	int m=(l+r)>>1;
	if(q>=l && q<=m)	add(node<<1,l,m,q);
	else if(q<=r && q>m)	add((node<<1)+1,m+1,r,q);
	tree[node]+=1;
}

ll work(int n)
{
	int i;
	init(1,0,n-1);
	l.clear();
	for(i=0;i<n;i++)
		l.push_back(make_pair(a[i],i));
	sort(l.begin(),l.end());
	for(i=0;i<n;i++)
		b[l[i].second]=i;
	//for(i=0;i<n;i++)	cout<<b[i]<<" ";
	//cout<<endl;
	for(i=0;i<n;i++)
	{
		le[i]=query(1,0,n-1,0,b[i]);
		add(1,0,n-1,b[i]);
	}
	//for(i=0;i<n;i++)	cout<<le[i]<<" ";
	//cout<<endl;
	init(1,0,n-1);
	for(i=n-1;i>=0;i--)
	{
		ri[i]=query(1,0,n-1,b[i],n-1);
		add(1,0,n-1,b[i]);
	}
	//for(i=0;i<n;i++)	cout<<ri[i]<<" ";
	//cout<<endl;
	ll ans=0;
	for(i=1;i<n-1;i++)
	{
		ll q=((ll)le[i]*ri[i]);
		ans+=q;
	}
	ans*=2;
	return ans;
}

int main()
{
	int test,n,x,y,i;
	scanf("%d",&test);
	while(test--)
	{
		l.clear();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			l.push_back(make_pair(x,y));
		}
		sort(l.begin(),l.end());
		for(i=0;i<n;i++)	a[i]=l[i].second;
		printf("%lld\n",work(n));
	}
	return 0;
}