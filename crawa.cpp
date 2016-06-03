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

bool work(int x,int y)
{
	if((!x && !y) || (x==1 && (y==0 || y==1 || y==2)) )	return 1;
	if(abs(y%2)==0)
	{
		if(y>0)
		{
			if(x>=-y && x<=y-1)	return 1;
		}
		else if(y<0)
		{
			if(x>=y && x<=-y+1)	return 1;
		}
	}
	if(1)
	{
		if(x>0)
		{
			if(x%2 && y>=-x+1 && y<=x+1)	return 1;
		}
		else if(x<0)
		{
			if((-x)%2==0 && y>=x && y<=-x)	return 1;
		}
	}
	return 0;
}

int main()
{
	int test,x,y;
	cin>>test;
	while(test--)
	{
		cin>>x>>y;
		if(work(x,y))	cout<<"YES\n";
		else			cout<<"NO\n";
	}
	return 0;
}