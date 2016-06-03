#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
double a[16][16],ans[1<<16];
int main()
{
	int t,n,i,no_of_set_bits,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)	scanf("%lf",&a[i][j]);
		}
		ans[0]=1;
		for(i=1;i<(1<<n);i++)
		{
			ans[i]=0;
			no_of_set_bits=0;
			for(j=0;j<=15;j++)
			{
				if(i&(1<<j))
				{
					no_of_set_bits++;
				}
			}
			for(j=0;j<=15;j++)
			{
				if(i&(1<<j))
				{
					ans[i]+=(a[no_of_set_bits-1][j]*ans[i^(1<<j)]);
				}
			}
		}
		printf("%f\n",ans[(1<<n)-1]);
	}
	return 0;
}