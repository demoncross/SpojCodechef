
#include<stdio.h>
typedef long long ll;
int cum_f[2005][2005],a[1005];
ll dp[1005][1005];
ll p[1005];
ll max(ll a,ll b)
{
	return (a>b?a:b);
}
int main()
{
int n,m,q,k,i,x,j,valid,s,a_x,a_y,b_x,b_y,area;
ll pissed;
scanf("%d%d%d%d",&n,&m,&q,&k);
for(i=0;i<1002;i++)	cum_f[i][0]=cum_f[0][i]=0;
for(i=1;i<=n;i++)
{
	cum_f[i][0]=0;
	for(j=1;j<=m;j++)
	{
		scanf("%d",&s);
		cum_f[i][j]=cum_f[i][j-1]+cum_f[i-1][j]-cum_f[i-1][j-1]+s;
	}
}
valid=0;
for(x=1;x<=q;x++)
{
	pissed=0;
	scanf("%d%d%d%d",&a_x,&a_y,&b_x,&b_y);
	pissed=cum_f[b_x][b_y]-cum_f[b_x][a_y-1]-cum_f[a_x-1][b_y]+cum_f[a_x-1][a_y-1];
	area=(b_y-a_y+1)*(b_x-a_x+1);
	if(pissed<=k)
	{
		p[valid]=pissed;
		a[valid]=area;
		valid++;
	}
}
for(i=0;i<=1002;i++)
	dp[i][0]=dp[0][i]=0;
for(i=1;i<=k;i++)
{
	for(j=1;j<=valid;j++)
	{
		if(p[j-1]<=i)
		{
			dp[i][j]=max(dp[i-p[j-1]][j-1]+a[j-1],dp[i][j-1]);
		}
		else
			dp[i][j]=dp[i][j-1];
	}
}
printf("%lld\n",dp[k][valid]);
//for(i=0;i<valid;i++)	printf("%d %lld\n",a[i],p[i]);
return 0;
}
