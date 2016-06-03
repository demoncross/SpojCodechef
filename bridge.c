#include<stdio.h>
typedef struct rr
{
int x,y;
}node;
node a[1009];
int dp[1009];
int len;

void sort(int start,int end)
{
if(start>end) return;
int key,i,k;
node j;
key=a[end].x;
k=start;
for(i=start;i<end;i++)
{
if(a[i].x<key||(a[i].x==key && a[i].y<=a[end].y))
{
j=a[i];
a[i]=a[k];
a[k]=j;
k++;
}
}
j=a[end];
a[end]=a[k];
a[k]=j;
sort(start,k-1);
sort(k+1,end);
}
int lis(void)
{
	int i,j,max=1;
	dp[0]=1;
	for(i=1;i<len;i++)
	{
		dp[i]=1;
		for(j=0;j<i;j++)
		{
			if(a[i].y>=a[j].y && dp[i]<dp[j]+1)	dp[i]=dp[j]+1;
		}
		if(dp[i]>max)	max=dp[i];
	}
	return max;
}
int main()
{
int i,t;
scanf("%d",&t);
while(t--)
{
	scanf("%d",&len);
	for(i=0;i<len;i++)	scanf("%d",&a[i].x);
	for(i=0;i<len;i++)	scanf("%d",&a[i].y);
	sort(0,len-1);
	printf("%d\n",lis());
}
return 0;
}
