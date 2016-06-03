#include<stdio.h>
#define max 10009
int dp[max];
typedef struct to
{
int p,w;
}t;
t a[501];
void sort(int start,int end)
{
if(start>end) return;
int key,i,k;
t j;
key=a[end].w;
k=start;
for(i=start;i<end;i++)
{
if(a[i].w<=key)
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
int main()
{
int i,j,q,p,w,n,min,test;
scanf("%d",&test);
while(test--)
{
	scanf(" %d %d",&p,&w);
	w-=p;
	if(w==0)
	{
		printf("This is impossible.\n");
	}
	scanf(" %d",&n);
	for(i=0;i<n;i++)
		scanf(" %d %d",&a[i].p,&a[i].w);
	sort(0,n-1);
	for(i=0;i<max;i++)
		dp[i]=-1;
	dp[0]=0;
	for(i=1;i<=w;i++)
	{
		min=10000000;
		for(j=0;a[j].w<=i && j<n;j++)
		{
			if(dp[i-a[j].w]!=-1){
			q=dp[i-a[j].w]+a[j].p;
			if(q<min)
				min=q;}
		}
		if(min!=10000000)
		dp[i]=min;
		else dp[i]=-1;
	}
	if(dp[w]!=-1)
	printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
	else
	printf("This is impossible.\n");
}
return 0;
}
