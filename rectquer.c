#include<stdio.h>
typedef struct a
{
	int array[11];
}node;
int a[305][305];
node dp[305][305]={0};
int count(int x)
{
	int i,c=0;
	for(i=0;i<=10;i++)
	{
		if(x&(1<<i))	c++;
	}
	return c;
}
int main()
{
int i,j,n,x_1,po,x_2,y_1,y_2,q,ans=0;
node m,p;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
	{
		scanf("%d",&a[i][j]);
		dp[i][j]=dp[i][j-1];
		dp[i][j].array[a[i][j]]++;
	}
}
scanf("%d",&q);
while(q--)
{
	ans=0;
	po=0;
	scanf("%d %d %d %d",&x_1,&y_1,&x_2,&y_2);
	for(i=x_1;i<=x_2;i++)
	{
		m=dp[i][y_1-1];
		p=dp[i][y_2];
		for(j=1;j<=10;j++)
		{
			if(m.array[j]!=p.array[j] && !(po&(1<<j)))	{	ans++;	po|=(1<<j);	}
		}
	}
	printf("%d\n",ans);

}
return 0;
}
