#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main()
{
	int t,x,y,i,j,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d%d",&x,&y);
		scanf("%d%d",&x,&y);
		scanf("%d%d",&i,&j);
		printf("%d\n",2*abs(x-i)+3*abs(j-y));
	}
	return 0;
}