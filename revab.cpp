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

char t[1003];
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

void sff(void)
{
	int i,j,l,coun;
	l=strlen(s);
	if(l==1)
		ans[0]=0;
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
	}
}

int main()
{
	int i,j,k,test,l,x,y;
	scanf("%d",&test);
	while(test--)
	{
		scanf(" %s",t);
		l=strlen(t);
		for(i=0;i<l;i++)	if(t[i]=='b')	break;
		if(i==l)
		{
			printf("0,0\n");
			continue;
		}
		k=0;
		for(j=l-1;j>=i;j--)
			s[k++]=t[j];
		s[k]=0;
		sff();
		x=i;
		y=l-1-ans[0];
		if(x==y)	x=y=0;
		printf("%d,%d\n",x,y);
	}
	return 0;
}