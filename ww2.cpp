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
ll odd[31][31],even[31][31],ans[31][31],a[31][31];
int n,m;

void mul(ll x[][31],ll y[][31],bool f)
{
	ll temp[31][31];
	int i,j,k;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			temp[i][j]=0;
			for(k=0;k<m;k++)
			{
				temp[i][j]=(temp[i][j]+(x[i][k]*y[k][j])%MOD)%MOD;
			}
		}
	}
	for(i=0;i<m;i++)	
	{
		for(j=0;j<m;j++)	
		{
			if(f)	a[i][j]=temp[i][j];
			else	ans[i][j]=temp[i][j];
		}
	}
}

void power(int n)
{
	if(n==0)	return;
	power(n>>1);
	mul(ans,ans,0);
	if(n&1)	mul(ans,a,0);
}

int main()
{
	int test,i,j,x;
	ll anss;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)	{	for(j=0;j<m;j++)	odd[i][j]=even[i][j]=ans[i][j]=0;	ans[i][i]=1;}
		odd[0][1]=1;
		odd[m-1][m-2]=1;
		for(i=1;i<m-1;i++)
			odd[i][i-1]=odd[i][i+1]=1;
		even[0][1]=even[0][0]=1;
		even[m-1][m-1]=even[m-1][m-2]=1;
		for(i=1;i<m-1;i++)
			even[i][i-1]=even[i][i+1]=even[i][i]=1;
		mul(even,odd,1);
		x=(n-1)/2;
		power(x);
		if((n-1)%2)
			mul(odd,ans,0);
		anss=0;
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				anss=(anss+ans[i][j])%MOD;
		printf("%lld\n",anss);
	}
	return 0;
}