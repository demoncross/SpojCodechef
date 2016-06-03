//http://codeforces.com/problemset/problem/381/B
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

int c[5001];
int main()
{
	int i,n,a,k;
	vector<int> ans;
	vector<int> v;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		v.push_back(a);
		c[a]++;
	}
	for(i=1;i<=5000;i++)
	{
		if(c[i])
		{
			ans.push_back(i);
			c[i]--;
		}
	}
	k=ans[ans.size()-1];
	for(i=5000;i>=1;i--)
	{
		if(c[i] && i!=k)
		{
			ans.push_back(i);
			c[i]--;
		}	
	}
	printf("%d\n",ans.size());
	for(i=0;i<ans.size()-1;i++)	printf("%d ",ans[i]);
	printf("%d\n",ans[i]);
	return 0;
}