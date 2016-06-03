#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int first[100005],second[100005];
int main()
{
	int n,i,m,q,ans,x,y,a,b;
	scanf("%d",&n);
	for(i=0;i<100005;i++)	first[i]=second[i]=0;
	m=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		first[x]++;
		second[y]++;
		m=max(m,max(x,y));
	}
	ans=-1;
	for(i=0;i<=m;i++)
	{
		if((first[i]+second[i])>=(n+1)/2)
		{
			q=first[i];
			/*a=first[i];
			b=second[i];
			q=max(a,b);*/
			if(q>ans);
			ans=q;
		}
	}
	if(ans==-1)
		printf("Impossible\n");
	else if(ans>=(n+1)/2)
		printf("0\n");
	else
		printf("%d\n",((n+1)/2)-ans);
	return 0;
}