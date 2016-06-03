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
#define MINI -100000000

using namespace std;

int p[4004][4004];

class BuildingHeights
{
public:
	int minimum(vector <int> heights)
	{
		int n,i,j,k,mini,ans;
		sort(heights.begin(),heights.end());
		n=heights.size();
		//for(i=0;i<=n;i++)
		//	for(j=0;j<=4000;j++)	p[i][j]=-1;
		for(i=0;i<n;i++)
		{
			k=i-1;
			p[heights[i]][1]=0;
			for(j=2;j<=i+1;j++)
			{
				p[heights[i]][j]=p[heights[i]][j-1]+heights[i]-heights[k];
				k--;
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			mini=1000000000;
			for(j=i-1;j<n;j++)
				mini=min(mini,p[heights[j]][i]);
			ans^=mini;
		}
		return ans;
	}
};/*
int main()
{
	BuildingHeights x;
	int a[]= {990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,
 2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,
 929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,
 1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,
 1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,
 1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888};
		vector <int> heights(a,a+sizeof(a)/sizeof(int));
	heights.push_back(1);
		heights.push_back(5);
			heights.push_back(4);
				heights.push_back(3);
					heights.push_back(8);
						//heights.push_back();
	printf("%d\n",x.minimum(heights));
	return 0;
}*/