#include<stdio.h>
#define mod 1000000007
long long int mat[2][2]={1,27,0,26};
long long int ans[2][2];
void mul(long long int a[2][2],long long int b[2][2])
{
	ans[0][0]=(a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0])%mod;
	ans[0][1]=(a[0][0]*b[0][1])%mod+(a[0][1]*b[1][1])%mod;
	ans[1][0]=(a[1][0]*b[0][0])%mod+(a[1][1]*b[1][0])%mod;
	ans[1][1]=(a[1][0]*b[0][1])%mod+(a[1][1]*b[1][1])%mod;
}
void expo(int n)
{
	if(n==0)	return;
	else if(n%2==0)
	{
		expo(n/2);
		mul(ans,ans);
		return;	
	}
	else
	{
		expo(n/2);
		mul(ans,ans);
		mul(mat,ans);
		return;
	}
	
}
int main()
{
int test,n;
long long int a,b;
scanf("%d",&test);
while(test--)
{
	ans[0][0]=ans[1][1]=1;
	ans[1][0]=ans[0][1]=0;
	//ans={1,0,0,1};
	scanf("%d",&n);
	if(n%2==0)
	{
		expo((n/2)-1);
		a=ans[0][0]*26+ans[0][1]*26;
		b=ans[1][0]*26+ans[1][1]*26;
		printf("%d\n",(a+b)%mod);
	}
	else
	{
		expo(n/2);
		a=ans[0][0]*26+ans[0][1]*26;
		printf("%d\n",a%mod);
	}
}
return 0;
}

