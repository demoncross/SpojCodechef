#include <cstdio>
#include <cstdlib>
#include <stack>
#include <algorithm>
using namespace std;
int ht[10000];
int main()
{
	int n,x,i,q,ans=0;
	scanf("%d%d",&n,&x);
	for(i=0;i<n;i++)
		scanf("%d",&ht[i]);
	stack<int> s;
	s.push(0);
	for(i=1;i<n;i++)
	{
		if(ht[i]<=ht[s.top()])
			s.push(i);
		else
		{
			while(!s.empty() && ht[s.top()]<ht[i])
			{
				q=s.top();
				s.pop();
				if(s.empty())	break;
				ans+=(i-s.top()-1)*(min(ht[s.top()],ht[i])-ht[q]);
			}
			s.push(i);
		}
	}
	if(ans<x)	printf("%d\n",x-ans);
	else		printf("0\n");
	return 0;
}