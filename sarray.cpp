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
#define mod (1000000009)

using namespace std;
typedef long long int ll;

typedef struct nn
{
	int x[2];
	int index;
}node;

char s[100005];
int list[20][100005];
node z[100005];
int ans[100005];

bool ff(node a,node b)
{
	if(a.x[0]<b.x[0])	return 1;
	else if(a.x[0]==b.x[0])
	{
		if(a.x[1]<=b.x[1])	return 1;
		else				return 0;
	}
	return 0;
}

int main()
{
	int i,j,l,coun;
	scanf(" %s",s);
	l=strlen(s);
	if(l==1)	printf("0\n");
	else{
	for(i=0;i<l;i++)	list[0][i]=s[i];
	for(i=1,coun=1;coun<l;i++,coun<<=1)
	{
		for(j=0;j<l;j++)
		{
			z[j].x[0]=list[i-1][j];
			z[j].x[1]=j+coun<l?list[i-1][j+coun]:-1;
			z[j].index=j;
		}
		sort(z,z+l,ff);
		for(j=0;j<l;j++)
			list[i][z[j].index]=(j>0 && z[j-1].x[0]==z[j].x[0] && z[j-1].x[1]==z[j].x[1])?list[i][z[j-1].index]:j;
	}
	for(j=0;j<l;j++)
		ans[list[i-1][j]]=j;
	for(j=0;j<l;j++)	printf("%d\n",ans[j]);
	}
	return 0;
}