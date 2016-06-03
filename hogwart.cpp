#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> boy,girl;
	int t,n,k,i,x;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		boy.clear();
		girl.clear();
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			boy.push_back(x);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			girl.push_back(x);
		}
		sort(boy.begin(),boy.end());
		sort(girl.begin(),girl.end());
		for(i=0;i<n;i++)
			ans+=(boy[i]*girl[n-1-i]);
		if(ans<=k)	printf("YES\n");
		else		printf("NO\n");
	}
	return 0;
}