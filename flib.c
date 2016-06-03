#include<stdio.h>
#define m 1000000007
typedef long long int ll;
ll ans[3][3];
ll temp[3][3];
ll mat[3][3]={1,1,0,0,5,3,0,3,2};
int base[3][1]={0,2,1};
void mul(ll a[3][3],ll b[3][3])
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			temp[i][j]=0;
			for(k=0;k<3;k++)
			{
				temp[i][j]+=((a[i][k]*b[k][j])%m);
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)	ans[i][j]=temp[i][j];
	}
}

void expo(ll n)
{
	if(n==0)	return;
	expo(n>>1);
	mul(ans,ans);
	if(n&1)
		mul(ans,mat);
}

int main()
{
	ll n,all;
	int test,i,j;
	scanf("%d",&test);
	while(test--)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)	ans[i][j]=0;
			ans[i][i]=1;
		}
		scanf("%lld",&n);
		expo(n);
		all=0;
		for(i=0;i<3;i++)
		{
			all+=((ans[0][i]*base[i][0])%m);
		}
		printf("%lld\n",all%m);
	}
	return 0;
}
