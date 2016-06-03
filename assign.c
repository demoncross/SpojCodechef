#include<stdio.h>
#define max (1+(1<<20))
typedef long long int ll;
ll dp[2][max];
int map[22][22];
int a[22];
int no_of_bits(int q)
{
int i=0,s,ans=0;
s=1;
while((s<<i)<=q)
{
	if(q&(s<<i))	
	{
		a[ans]=i;
		ans++;
	}	
	i++;
}
return ans;
}
int main()
{
ll ans;
int test,take,t,put,n,i,j,k,l,q;
scanf("%d",&test);
while(test--)
{
ans=0;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)	scanf("%d",&map[i][j]);
}
for(i=0;i<2;i++)
{
for(j=1;j<=(1<<(n));j++)	dp[i][j]=0;
}
for(i=0;i<n;i++)	dp[0][1<<i]=(map[1][n-i]==1)?1:0;
put=1;
take=0;
for(i=2;i<=n;i++)
{
	for(j=1;j<(1<<(n));j++)
	{
		dp[put][j]=0;
		if(no_of_bits(j)==i)
		{//printf("%d ",j);
			for(l=0;l<i;l++)
			{
				if(map[i][n-a[l]]){
				q=1<<a[l];
				dp[put][j]+=dp[take][j^q];}
			}
		}	
	}
	t=take;
	take=put;
	put=t;
}
for(j=0;j<(1<<(n));j++)
{
	ans+=dp[take][j];
}
printf("%lld\n",ans);
}
return 0;
}
