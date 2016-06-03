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
#define mod (1000000007)

using namespace std;
typedef long long int ll;

int a[500];
vector<int>having;
int main()
{
	int i,j,k,test,n,m,ans,mi,rep;
	cin>>test;
	while(test--)
	{
		ans=0;
		having.clear();
		cin>>n>>m;
		for(i=0;i<m;i++)	cin>>a[i];
		for(i=0;i<m;i++)
		{
			for(j=0;j<having.size();j++)
			{
				if(having[j]==a[i])	break;
			}
			if(j==having.size())
			{
				if(having.size()<n)	having.push_back(a[i]);
				else
				{
					mi=-10;
					for(j=0;j<n;j++)
					{
						for(k=i+1;k<m;k++)
						{
							if(a[k]==having[j])	break;
						}
						if(k==m)	{rep=j;break;}
						if(mi<k)
						{
							mi=k;
							rep=j;
						}
					}
					having[rep]=a[i];
				}
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}