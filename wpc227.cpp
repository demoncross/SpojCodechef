#include<cstdio>
#include<cstdlib>
#define mod 1000000007
typedef long long int ll;
using namespace std;
ll dp[1<<17],dep[18][18];
int main()
{
	int t,i,j,k,x,y,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<17;i++)	dep[i][0]=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			dep[y][++dep[y][0]]=x;
		}
		dp[0]=1;
		for(i=1;i<(1<<n);i++)
		{
			dp[i]=0;
			for(j=0;j<=n;j++)
			{
				if(i&(1<<j))
				{
					for(k=1;k<=dep[j][0];k++)
					{
						if(i&(1<<(dep[j][k]))==0)	break;
					}
					if(k>dep[j][0])
						dp[i]=(dp[i]+dp[i^(1<<j)])%mod;
				}
			}
		}
		for(i=0;i<(1<<n);i++)	printf("%d ",dp[i]);
		printf("\n%lld\n",dp[(1<<n)-1]);
	}
	return 0;
}
