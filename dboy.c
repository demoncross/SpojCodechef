#include<stdio.h>
int min(int a,int b)
{
	return (a<b?a:b);
}
int h[505],k[505],dp[1005];
void sort(int *a,int start,int end)
{
if(start>end) return;
int key,i,j,k;
key=a[end];
k=start;
for(i=start;i<end;i++)
{
if(a[i]<=key)
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
sort(a,start,k-1);
sort(a,k+1,end);
}

int main()
{
int t,i,j,n,ans;
scanf("%d",&t);
while(t--)
{
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&h[i]);
	for(i=0;i<n;i++)	scanf("%d",&k[i]);
	sort(k,0,n-1);
	for(i=0;i<1005;i++)	dp[i]=100000000;
	for(i=0;i<n;i++)	dp[k[i]]=1;
	for(i=1;i<=1000;i++)
	{
		for(j=0;j<n;j++)
		{
			if(k[j]>=i)	break;
			dp[i]=min(dp[i-k[j]]+1,dp[i]);
		}
	}
	ans=0;
	for(i=0;i<n;i++)
		ans+=dp[2*h[i]];
	printf("%d\n",ans);
}
return 0;
}
