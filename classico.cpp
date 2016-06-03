#include<cstdio>
#include<queue>
#include<deque>

using namespace std;

int a[2005];

int main()
{
	int t,n,test,i;
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		printf("Case %d: ",t);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(n<11)
		{
			printf("go home!\n");
			continue;
		}
		deque <int> d;
		for(i=0;i<n-10;i++)
		{
			while(!d.empty() && d.back()<a[i])	d.pop_back();
			d.push_back(a[i]);
		}
		printf("%d",d.front());
		d.pop_front();
		for(;i<n;i++)
		{
			while(!d.empty() && d.back()<a[i])	d.pop_back();
			d.push_back(a[i]);	
			printf(" %d",d.front());
			d.pop_front();		
		}
		printf("\n");
	}
	return 0;
}