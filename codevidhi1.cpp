#include <cstdio>
using namespace std;
int main()
{
	int a,b,used,have,ans;
	scanf("%d%d",&a,&b);
	have=a;
	used=0;
	ans=0;
	while(have>0)
	{
		ans+=have;
		used+=have;
		have=used/b;
		used=used%b;
	}
	printf("%d\n",ans);
	return 0;
}