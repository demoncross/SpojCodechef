#include<stdio.h>
//int dp[5][25];
//int a[25][5];
int min(int a,int b)
{
	return (a<b?a:b);
}
int main()
{
int t,n,i,a,b,c,min_a,min_b,min_c,t_a,t_b,t_c;
scanf("%d",&t);
while(t--)
{
	scanf("%d",&n);
	min_a=min_b=min_c=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		t_a=min_a;
		t_b=min_b,t_c=min_c;
		min_a=min(t_b,t_c)+a;
		min_b=min(t_a,t_c)+b;
		min_c=min(t_a,t_b)+c;
	}
	printf("%d\n",min(min(min_a,min_b),min_c));
}
return 0;
}
