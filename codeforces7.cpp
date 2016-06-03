//http://codeforces.com/contest/22/problem/D
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector < pair<int, pair<int,int> > > v;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		v.push_back(make_pair(x,make_pair(1,i)));
		v.push_back(make_pair(y,make_pair(2,i)));
	}
	sort(v.begin(),v.end());
	for(i=0;i<n;i++)
	{
		
	}
	return  0;
}