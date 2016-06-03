#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;
typedef long long int ll;

ll a[1000000],sum[1000000];


int main()
{
	ll test,n,k,s,i,j,no,ans;
	scanf("%lld",&test);
	while(test--)
	{
		cin>>n>>k;
		for(i=1;i<=n;i++)	cin>>a[i];
		sum[0]=0;
		for(i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
		s=0;
		ans=0;
		for(j=1;j<=n;j++)
		{
			s+=j*a[j];
			if(s>k)	break;
			if(s==k)	ans=j;
		}
		no=j;
		for(i=2;i<=n;i++)
		{
			s=s-(sum[j]-sum[i-1]);
			no--;
			for(j=j+1;j<=n;j++)
			{
				no++;
				s+=no*a[j];
				if(s>k)	break;
				if(s==k)	ans=max(ans,no);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}