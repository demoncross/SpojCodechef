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
#define mod 1000000007

using namespace std;
typedef long long int ll;

ll C[25][25];
pair <int,int> a[25];
vector<int> v;
int n,k;
double ans=0.00;

void crt(void)
{
	int i,j;
	for(i=0;i<=20;i++)	C[i][i]=C[i][0]=1;
	for(i=1;i<=20;i++)
		for(j=1;j<i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
}

void work(int l,int sum,int e)
{
	if(l==n)
	{
		int len1,len2,x,y;
		len1=a[v[0]].first;
		len2=a[v[1]].first;
		if(k<sum)
			return;
		else if(k>sum+len2)
			y=len2;
		else
			y=k-sum;
		if(k<sum+len1)
			x=0;
		else if(k>sum+len1+len2)
			x=len2;
		else 
			x=k-sum-len1;
		ans+=((2*(double)(y-x))/((n-e)*C[n][e]));
		//printf("%d %f\n",e,((2*(double)(y-x))/((n-e)*C[n][e])));
	}
	else if(l==v[0] || l==v[1])
		work(l+1,sum,e);
	else
	{
		work(l+1,sum+a[l].first,e+1);
		work(l+1,sum,e);
	}
}

int main()
{
	int test,i,j,x,y;
	scanf("%d",&test);
	crt();
	while(test--)
	{
		ans=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			a[i]=(make_pair(x,y));
		}
		for(i=1;i<=n;i++)
		{
			v.clear();
			for(j=0;j<n;j++)
				if(a[j].second==i)	v.push_back(j);
			if(v.size()<2)	continue;
			work(0,0,0);
		}
		for(i=0;i<n;i++)
		{
			if(a[i].first<k)	continue;
			else	ans+=(a[i].first-k);
		}
		printf("%.7f\n",ans);
	}
	return 0;
}