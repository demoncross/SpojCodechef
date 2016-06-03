#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct p
{
	double price,area;
	double d[20];
}a[20],dp[1<<17];
int main()
{
	double ans,q,x,y,m;
	int i,j,k,l,n;
	scanf("%d",&n);
	while(n)
	{
		dp[0].price=dp[0].area=0;
		for(i=0;i<=n;i++){
			for(j=0;j<=n;j++)	a[i].d[j]=0;}
		//for(i=0;i<(1<<n);i++)
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf",&a[i].price,&a[i].area,&m);
			for(j=1;j<=m;j++)	
				{scanf("%lf %lf",&x,&y); a[i].d[(int)x]=y;}
		}
		for(i=1;i<=n;i++)	dp[0].d[i]=a[i].price;
		for(i=1;i<(1<<n);i++)
		{
			dp[i].price=100000000.00;
			for(j=0;j<n;j++)
			{
				if(i&(1<<j))
				{
					q=dp[i^(1<<j)].price+dp[i^(1<<j)].d[j+1];
					if(q<dp[i].price)
					{
						dp[i]=dp[i^(1<<j)];
						dp[i].price=q;
						for(k=1;k<=n;k++)
							dp[i].d[k]=dp[i].d[k]*(100-a[j+1].d[k])/100;
						dp[i].area+=a[j+1].area;
					}
				}
			}
		}
		ans=10000000.00;
		for(i=1;i<(1<<n);i++)
		{
			q=dp[i].price/dp[i].area;
			if(q<ans)	ans=q;
		}
		//for(i=0;i<(1<<n);i++)	printf("%f %f %f %f \n",dp[i].price,dp[i].area,dp[i].d[1],dp[i].d[2]);
		printf("%.4lf\n",ans);
		scanf("%d",&n);
	}
	return 0;
}