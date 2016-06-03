#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
int tree[1000],n;

int work(int node,int *highest)
{
	int left,right,l,r,q1,q2,q3;
	left=node<<1;
	right=left+1;
	if(left>n || right>n)
	{
		*highest=tree[node];
		return tree[node];
	}
	q1=work(left,&l);
	q2=work(right,&r);
	q3=l+r+tree[node];
	*highest=max(l,r)+tree[node];
	return max(max(q1,q2),q3);
}

int main()
{
	int test,i;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&tree[i]);
		printf("%d\n",work(1,&i));
	}
	return 0;
} 