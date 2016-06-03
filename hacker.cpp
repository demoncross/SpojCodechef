#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
ll a[1000000],b[1000000],need[1000000];
ll max(ll a,ll b)
{
	return a>b?a:b;
}

int main()
{
	ll n,c,i,j,fuel,count;
	scanf("%lld%lld",&n,&c);
	//c=c+1;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		a[i+n]=a[i];
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&b[i]);
		b[i+n]=b[i];
	}
	for(i=0;i<n;i++)
	{
		//check the ith station for a valid start
		fuel=0;
		for(j=i;j<i+n;j++)
		{
			fuel=(fuel+min(a[j],c));
			fuel=min(fuel,c);
			fuel=fuel-b[j];
			if(fuel<0)
				break;
		}	
		if(j!=i+n){
			i=j;//if the ith isnt a valid start, and from from i we can reach only upto j, therefore i to j can also not be a valid start.
			continue;}
		else
		{
			count=1;
			// ith station is a valid start.
			need[n+i]=0;
			for(j=n+i-1;j>i;j--)
			{
				need[j]=max(0,need[j+1]+b[j]-min(c,a[j]));
				if(need[j]==0)	count++;
			}
			printf("%lld\n",count);
			break;
		}
	}
	if(i>=n)
		printf("0\n");
	return 0;
}