#include<stdio.h>
#define max 100000000
int map[105][105];
int min(int a,int b)
{
	return (a<b?a:b);
}
int main()
{
int i,j,k,n,time,exit,edges,ans=0,u,v,w;
for(i=0;i<105;i++)
{
	for(j=0;j<105;j++)	map[i][j]=max;
	map[i][i]=0;
}
scanf("%d",&n);
scanf("%d",&exit);
scanf("%d",&time);
scanf("%d",&edges);
for(i=0;i<edges;i++)
{
	scanf("%d%d%d",&u,&v,&w);
	map[u][v]=w;
}
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
	{
		for(k=1;k<=n;k++)
		{
			//if(map[j][i]!=-1 && map[i][k]!=-1)
			map[j][k]=min(map[j][k],map[j][i]+map[i][k]);
		}
	}
}
for(i=1;i<=n;i++)
{
	if(map[i][exit]<=time)	ans++;
}
printf("%d",ans);
return 0;
}
