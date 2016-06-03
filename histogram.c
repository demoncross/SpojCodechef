#include<stdio.h>
#define max 100005
#define la 20
typedef long long int ll;
ll dp[max][la];
ll a[max];

int rmq(int l,int r)
{
int m,j,b,c;
j=0;
while((1<<j)<=r-l+1) j++;
if(j!=0)	j--;
m=l+(1<<(j-1))-1;
b=0;
while((r-(1<<b))>=m) b++;
c=r-(1<<b)+1;
if(a[dp[l][j]]<=a[dp[r-(1<<j)+1][j]]) return dp[l][j];
else return dp[r-(1<<j)+1][j];
}

ll area(int start,int end)
{
ll a1,a2,a3;
if(start>end)
	return 0;
else if(start==end)
	return a[start];
int min=rmq(start,end);
a1=area(start,min-1);
a2=area(min+1,end);
a3=a[min]*(end-start+1);
if(a1>a2)
{
	if(a1>a3)	return a1;
	else		return a3;
}
else
{
	if(a3>a2)	return a3;
	else		return a2;
}	
}

int main()
{
int i,num,j;
while(1)
{
scanf("%d",&num);
if(num==0)	break;
for(i=0;i<num;i++)
scanf(" %lld",&a[i]);
for(i=0;i<num;i++)
dp[i][0]=i;
for(j=1;1<<j<=num;j++)
{
for(i=0;(i+(1<<j)-1)<num;i++)
{
if(a[dp[i][j-1]]<=a[dp[i+(1<<(j-1))][j-1]])
dp[i][j]=dp[i][j-1];
else
dp[i][j]=dp[i+(1<<(j-1))][j-1];
}
}
printf("%lld\n",area(0,num-1));
}
return 0;
}