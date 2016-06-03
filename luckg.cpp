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

using namespace std;
typedef long long int ll;

int p[10000];
vector<int> list[1003];
int v[1003];
vector<int> w;

int main()
{
	int test,n,m,i,j,k,b,ma_d,x,flag,start;
	cin>>test;
	while(test--)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)	cin>>p[i];
		for(i=0;i<n;i++)	list[i].clear();
		for(i=0;i<n;i++)	v[i]=0;
		start=1;
		flag=0;
		if(n==1 || m==1)	
		{
			cout<<"No Solution\n";
			continue;
		}
		for(i=0;i<n;i++)
		{
			w.clear();
			if(v[i])	continue;
			x=p[i];
			while(x!=i)
			{
				v[x]=1;
				w.push_back(x);
				x=p[x];
			}
			v[x]=1;
			w.push_back(x);
			if(w.size()==1)
			{
				if(m<=2)
				{
					flag=1;
					break;
				}
				for(j=start;j<=start+m;j++)	list[w[0]].push_back(j);
				start=j;
				continue;
			}
			ma_d=(m/w.size())+(m%w.size()?1:0);
			if(ma_d>=m-ma_d)	
			{
				flag=1;
				cout<<"Err"<<ma_d<<w.size()<<i;
				break;
			}
			for(j=0;j<m;j++)
			{
				x=start+w.size()-1;
				b=j%w.size();
				for(k=0;k<w.size();k++)
				{
					list[w[(k+b)%w.size()]].push_back(x--);
				}
				start=start+w.size();
			}
		}
		if(flag)
			cout<<"No solution\n";
		else
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)	cout<<list[i][j]<<" ";
				cout<<endl;
			}
		}
	}
	return 0;
}