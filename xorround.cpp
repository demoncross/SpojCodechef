#include<stdio.h>
using namespace std;
int mat[505],a[505],ans[505],n;
void multiply(int a[505],int b[505])
{
	int arr[505],i,j,coun;
	for(i=0;i<n;i++)
	{
		coun=0;
		for(j=0;j<n;j++)
			coun+=(a[j]*b[(i+j)%n]);
		if(coun&1)
			arr[i]=1;
		else
			arr[i]=0;
	}
	for(i=0;i<n;i++)
		ans[i]=arr[i];
}
void power(int k)
{
	if(k==0)	return;
	power(k>>1);
	multiply(ans,ans);
	if(k&1)	
		multiply(ans,mat);
	return;
}
int main()
{
	int t,k,i,j,q;;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			ans[i]=mat[i]=0;
		}
		ans[0]=ans[1]=ans[n-1]=mat[0]=mat[1]=mat[n-1]=1;
		power(k-1);
		for(i=0;i<n;i++)
		{
			q=0;
			for(j=0;j<n;j++)
			{
				q^=(a[j]*ans[(j+i)%n]);
			}
			printf("%d ",q);
		}
		printf("\n");
	}
	return 0;
}