#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef unsigned long long int ll;
ll n,mod,ans;
ll a[5][5]={0,0,0,0,0
			,0,1,1,1,0
			,0,1,0,0,0
			,0,0,0,1,1
			,0,0,0,0,1};
ll arr[5][5]={0,0,0,0,0
			 ,0,1,0,0,0
			 ,0,0,1,0,0
			 ,0,0,0,1,0
			 ,0,0,0,0,1};
ll b[5]={0,1,0,1,1};
void multiply(ll a[5][5],ll b[5][5])
{
	ll i,j,k,x[5][5],t;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			t=0;
			for(k=1;k<=4;k++)
			{
				t=(t+(a[i][k]*b[k][j]))%mod;
			}
			x[i][j]=t;
		}
	}
	for(i=1;i<5;i++)
	{
		for(j=1;j<5;j++)
			arr[i][j]=x[i][j];
	}
}
void compute(int n)
{
	if(n==0)
		return;
	compute(n/2);
	multiply(arr,arr);
	if(n%2)
		multiply(arr,a);
}
int main()
{
	int test,i,j;
	scanf("%d",&test);
	while(test--)
	{
		for(i=1;i<=4;i++)
		{
			for(j=1;j<=4;j++)
			{
				if(i==j)	arr[i][j]=1;
				else		arr[i][j]=0;
			}
		}
		scanf("%lld%lld",&n,&mod);
		if(n==0)	
		{
			printf("0\n");
			continue;
		}
		compute(n-1);
		ans=0;/*
		for(i=1;i<=4;i++)
		{
			for(j=1;j<=4;j++)
				printf("%lld ",arr[i][j]);
			printf("\n");
		}*/
		for(i=1;i<=4;i++)
		{
			ans=(ans+arr[1][i]*b[i])%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}