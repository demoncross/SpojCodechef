#include<cstdio>
#include<cstdlib>
#include<queue>
#include<deque>
#include<vector>
using namespace std;
int price[100005],sum[100005],maximum[100005];
int main()
{
	int test,n,i,max,profit,inv,ret,no_of_stocks,target,max_index;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)	scanf("%d",&price[i]);
		sum[0]=0;
		for(i=1;i<=n;i++)	sum[i]=sum[i-1]+price[i];
		max=-1000000000;
		max_index=-1;
		for(i=n;i>=1;i--)
		{
			if(max<=price[i])
			{
				maximum[i]=i;
				max=price[i];
				max_index=i;
			}
			else
				maximum[i]=max_index;
		}
		profit=0;
		for(i=1;i<=n;)
		{
			target=maximum[i];
			no_of_stocks=target-i;
			inv=sum[target-1]-sum[i-1];
			ret=no_of_stocks*price[target];
			profit+=(ret-inv);
			i=target+1;
		}
		printf("%d\n",profit);
		//for(i=1;i<=n;i++)	printf("%d ",maximum[i]);
	}
	return 0;
}