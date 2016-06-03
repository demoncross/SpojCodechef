#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int b[5003],c[5003];
long long int b_search(long long int start,long long int end,long long int f)
{
	long long int ans,q,m,min=1000000000;
	while(start<=end)
	{
		m=(start+end)>>1;
		if(c[m]>f)
		{
			q=abs(c[m]-f);
			if(q<min)	
			{
				ans=m;
				min=q;
			}
			end=m-1;
		}
		else
		{
			q=abs(c[m]-f);
			if(q<min)	
			{
				ans=m;
				min=q;
			}
			start=m+1;
		}
	}
	return ans;
}
int main()
{
	long long int n,m,ans,x,z,i;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)	scanf("%d",&b[i]);
	for(i=0;i<m;i++)	scanf("%d",&c[i]);
	sort(b,b+n);
	sort(c,c+m);
	z=m-1;
	ans=0;
	for(i=n-1;i>=0;i--)
	{
		x=b_search(i,z,b[i]);
		ans+=abs(c[x]-b[i]);
		z=x-1;
	}
	printf("%lld",ans);
	return 0;
}