#include<cstdio>
using namespace std;
int main()
{
	int t,i,x,n,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x>i)	ans=-1;
		}
		if(ans==1)	printf("YES\n");
		else		printf("NO\n");
	}
	return 0;
}