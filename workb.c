#include<stdio.h>
int arr[100005];
int min(int a,int b)
{
	return (a<b?a:b);
}
int main()
{
int t,n,a,b,i,j=1;
long long int q1,q2,ans;
scanf("%d",&t);
while(t--)
{
	ans=0;
	scanf("%d%d%d",&n,&a,&b);
	for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	for(i=0;i<n-1;i++)
	{
		q1=arr[i+1]-arr[i]-1;
		q1*=b;
		q2=2*a;
		ans+=min(q1,q2);
	}
	ans+=(n*b)+2*a;
	printf("Case #%d: %lld\n",j,ans);
	j++;
}
return 0;
}
