#include<stdio.h>
typedef long long int ll;
ll matrix[2][2],temp[2][2],ans[2][2];
void multipl(ll a[2][2],ll b[2][2])
{
int i,j,k;
for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{
		temp[i][j]=0;
		for(k=0;k<2;k++)
		{
			temp[i][j]+=(a[i][k]*b[k][j]);
		}
		temp[i][j]%=1000000007;
	}
}
for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
		ans[i][j]=temp[i][j];
}
}
void power(int n)
{
if(n==1)	{multipl(ans,matrix); return; }
power(n/2);
multipl(ans,ans);
if(n%2==1)
multipl(ans,matrix);
}
int main()
{
ll test,n,i,j,a;
scanf("%lld",&test);
matrix[0][0]=matrix[0][1]=2;
matrix[1][0]=1;
matrix[1][1]=0;
while(test-->0)
{
	ans[0][0]=ans[1][1]=1;
	ans[0][1]=ans[1][0]=0;
	scanf(" %lld",&n);
	if(n==1)	printf("1\n");
	else if(n==2)	printf("3\n");
	else{	
	power(n-2);
	a=0;
	a=((ans[0][0]*3)+(ans[0][1]*1))%1000000007;
	printf("%lld\n",a);
	}
}
return 0;
}
