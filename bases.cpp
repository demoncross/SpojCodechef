//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=346&page=show_problem&problem=2503
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MOD 100000007

using namespace std;

int prime[10004];
int range[10004];
pair <int,int> factors[10004],final_factors[10004];
int no_of_factors,no_of_final_factors;

typedef long long int ll;

void sieve(void)
{
	int i,j;
	prime[1]=1;
	prime[2]=0;
	for(i=2;i*i<=10004;i++)
	{
		if(prime[i]==0)
		{
			for(j=i;j*i<=10004;j++)
				prime[i*j]=1;
		}
	}
	prime[1]=2;
	for(j=2,i=3;i<=10004;i++)
	{
		if(prime[i]==0)
		{
			prime[j++]=i;
		}
	}
	prime[0]=j-1;
}

int i;
void factorise(int n)
{
	int c,fact;
	if(n==1)	return;
	for(;i<=prime[prime[0]];i++)
	{
		if(prime[i]*prime[i]>n)	break;
		if(n%prime[i]==0)
		{
			fact=prime[i];
			c=0;
			while(n%prime[i]==0)
			{
				n=n/prime[i];
				c++;
			}
			factors[no_of_factors++]=make_pair(c,fact);
			//printf("*");
			factorise(n);
			return;
		}
	}
	factors[no_of_factors++]=make_pair(1,n);
	return;
}

int main()
{
	int no=1,n,m,k,j,no_of_ones,r;
	ll ans,final_answer;
	sieve();
	scanf("%d%d%d",&n,&m,&k);
	while(n!=0 && m!=0 && k!=0)
	{
		i=1;
		int i;
		printf("Case %d: ",no++);
		no_of_factors=no_of_final_factors=0;
		factorise(n);
		for(i=0;i<no_of_factors;i++){
			factors[i].first*=m;
			if(factors[i].first>=k);
			final_factors[no_of_final_factors++]=factors[i];
		}
		for(i=0;i<no_of_final_factors;i++)
		{
			range[i]=0;
			r=final_factors[i].first/k;
			while((final_factors[i].first-r*k)<r)
			{
				range[i]++;
				r--;
			}
		}
		if(no_of_final_factors==0)
		{
			printf("0\n");
			scanf("%d%d%d",&n,&m,&k);
			continue;
		}	
		final_answer=0;
		for(i=1;i<(1<<no_of_final_factors);i++)
		{
			no_of_ones=0;
			ans=1;
			for(j=0;j<no_of_final_factors;j++)
			{
				if(i&(1<<j))
				{
					no_of_ones++;
					ans*=range[j];
				}	
				else
				{
					ans*=((final_factors[j].first/k)+1);
				}
			}
			if(no_of_ones%2)
			{
				final_answer=(ans+final_answer)%MOD;
			}
			else
			{
				final_answer-=ans;
				while(final_answer<0)	final_answer+=MOD;
				final_answer%=MOD;
			}
		}
		printf("%lld\n",final_answer);
		scanf("%d%d%d",&n,&m,&k);
	}
	return 0;
}