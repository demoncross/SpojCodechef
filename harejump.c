#include<stdio.h>
int main()
{
long long int test,n,i,w,j,k,l,min,t;
scanf("%lld",&test);
int jumps[16];
while(test-->0)
{
scanf(" %lld",&n);
long long int dp[16]={0};
dp[0]=1;
scanf(" %lld",&k);

for(i=0;i<k;i++)
	scanf(" %d",&jumps[i]);
jumps[k]=10000;

for(i=0;i<k-1;i++)
{
	min=i;
	for(j=i+1;j<k;j++)
	{
		if(jumps[j]<jumps[min])
			min=j;
	}
	t=jumps[i];
	jumps[i]=jumps[min];
	jumps[min]=t;
}
j=0;

for(i=jumps[j];i<=n;i++)
{
if(i>=jumps[j+1])	j++;
dp[i%16]=0;
for(l=0;l<=j;l++)	
{
	w=i%16-jumps[l];
	if(w<0)
		w+=16;
	dp[i%16]=(dp[i%16]+dp[w])%1000000007;
}
}
//for(i=0;i<=15;i++)	printf("%d ",dp[i]);
printf("%lld\n",dp[n%16]);
}
return 0;
}
