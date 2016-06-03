#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
vector< pair<int,int> > v;
int a[100005],n;
int b[100005],c[100005];
typedef long long int ll;
ll count_inversions(int s,int e)
{
	ll m,i,q1,q2,co,size_b,size_c,p_b,p_c;
	if(s>=e)	return 0;
	//if(s==e-1)	return (a[s]<=a[e]?0:1);//equal allowed??
	m=(s+e)>>1;
	q1=count_inversions(s,m);
	q2=count_inversions(m+1,e);
	size_b=size_c=0;
	for(i=s;i<=m;i++)
		b[size_b++]=a[i];
	for(;i<=e;i++)
		c[size_c++]=a[i];
	p_b=0;
	p_c=0;
	co=0;
	for(i=s;i<=e;i++)
	{
		if(p_b==size_b)
			a[i]=c[p_c++];
		else if(p_c==size_c)
			a[i]=b[p_b++];
		else if(b[p_b]<=c[p_c])
			a[i]=b[p_b++];
		else
		{
			a[i]=c[p_c];
			co+=(size_b-p_b);
			p_c++;
		}
	}
	return q1+q2+co;
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	for(i=0;i<n;i++)
		a[i]=v[i].second;
	printf("%lld\n",count_inversions(0,n-1));
	return 0;
}