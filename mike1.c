#include<stdio.h>
int a[505][505];
long long max(long long a,long long b)
{
	return (a>b?a:b);
}
int main()
{
	int t,n,m,q,i,x,y,j,take_1,take_2;
	long long int ans_1,ans_2;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)	scanf("%d",&a[i][j]);
	}
	scanf("%d",&q);
	ans_1=ans_2=0;
	take_1=take_2=1;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(x<=n && y<=m && take_1)
			ans_1+=a[x][y];
		else
		{
			take_1=0;
			ans_1=-1;
		} 
		if(x<=m && y<=n && take_2)
			ans_2+=a[y][x];
		else
		{
			take_2=0;
			ans_2=-1;
		}
		if(!take_1 && !take_2)
			break;
	}
	printf("%lld\n",max(ans_1,ans_2));
	return 0;
}