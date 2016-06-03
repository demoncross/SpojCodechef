#include<cstdio>
#include<cstdlib>
#include<stack>
int a[100005];
using namespace std;
int main()
{
	int c,ans,i,n;
	c=1;
	while(~scanf("%d",&n))
	{
		stack <int> s;
		ans=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			if(s.empty() || a[i]>s.top())
			{
				ans+=(a[i]==0?0:1);
				s.push(a[i]);
			}
			else if(a[i]==s.top())	continue;
			else
			{
				while(!s.empty() && s.top()>a[i])	s.pop();
				if(!s.empty() && s.top()==a[i])		continue;
				if(s.empty() || s.top()<a[i])			
				{
					s.push(a[i]);
					ans+=(a[i]==0?0:1);
				}
			}
		}
		printf("Case %d: %d\n",c,ans);
		c++;
	}
	return 0;
}