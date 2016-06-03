#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	int n,i,needed,days;
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	sort(a,a+n);
	days=0;
	for(i=n-1;i>=0;i--)
	{
		days--;
		needed=a[i];
		if(needed>days)	days=needed;
	}
	printf("%d\n",n+days+1);
	return 0;
}