//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1015
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef unsigned long long int ll;
using namespace std;

int a[50001],primes[6000];
void sieve()
{
	int i,j;
	a[0]=a[1]=1;
	for(i=2;i*i<=50000;i++)
	{
		if(a[i]==0)
		{
			for(j=i;j*i<=50000;j++)	a[j*i]=1;
		}
	}
	int c=0;
	for(i=0;i<=50000;i++)
	{
		if(a[i]==0)	
		{
			primes[c++]=i;
		}
	}/*
	ll ans=1;
	for(i=0;i<2500;i++){
		ans=ans*primes[i];
		if(ans>1000000000000001LL)	{printf("***%d***%lld\n",i,ans);break;}}
	printf("%lld\n",ans);*/
}
int main()
{
	sieve();
	ll ans,aa;
	float rem;
	int c=1,n,j,i,ff;
	scanf("%d",&n);
	while(n)
	{
		ff=0;
		ans=1;
		aa=1000000000000000000ll;
		printf("Case %d: ",c);
		for(i=1;((1<<i)<=n);i++)
		{
			//rem=n-i;
			ans=1;
			ff=0;
			for(j=0;j<i;j++)
			{
				ans*=primes[j];
				if(ans>=1000000000000001LL)
				{
					ff=1;
					break;
				}
			}
			if(ff==0)
			{
				rem=(n/(1<<(i-1)));
				if(rem==(int)rem)
				{
				for(j=3;j<=rem;j++)
				{
					ans*=primes[0];
					if(ans>=1000000000000001LL)
					{
						ff=1;
						break;
					}		
				}
			}
			}
			if(ff==0 && ans<aa)
			{
				aa=ans;
			}
			printf("%lld\n",ans);
		}
		if(aa==1000000000000000000ll)	printf("Impossible\n");
		else		printf("%lld\n",aa );
		scanf("%d",&n);
		c++;
	}
	return 0;
}