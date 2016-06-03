#include<cstdio>
#include<cstdlib>
using namespace std;
typedef long long int ll;
ll a[100000];
int c=0;

ll more(ll q)
{
	ll left,right,ans,mid;
	left=0;
	right=c-1;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(a[mid]==q)	return mid;
		else if(a[mid]<q)
		{
			left=mid+1;
		}
		else if(a[mid]>q)
		{
			ans=mid;
			right=mid-1;
		}
	}
	return ans;
}

ll less(ll q)
{
	ll left,right,ans,mid;
	left=0;
	right=c-1;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(a[mid]==q)	return mid;
		else if(a[mid]>q)
		{
			right=mid-1;
		}
		else if(a[mid]<q)
		{
			ans=mid;
			left=mid+1;
		}
	}
	return ans;
}

int main()
{
	ll test,x,y,i,left,right;
	for(i=1;i<=100000;i++)	a[c++]=(ll)i*i;
	scanf("%lld",&test);
	while(test--)
	{
		scanf("%lld%lld",&x,&y);
		left=more(x);
		right=less(y);
		printf("%lld\n",right-left+1);
	}
	return 0;
}