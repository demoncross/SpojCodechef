#include <stdio.h>
#define MOD 100000007

int prime[100000004];
int range[10004];
int factors[10004],final_factors[10004];
int no_of_factors,no_of_final_factors;

typedef long long int ll;

void sieve(void)
{
	int i,j;
	prime[1]=-1;
	prime[2]=0;
	for(i=2;i*i<=10000004;i++)
	{
		if(prime[i]==0)
		{
			for(j=i;j*i<=10000004;j++)
				if(prime[i*j]==0)	prime[i*j]=i;
		}
	}
}

int i;
void factorise(int n)
{
	int c,fact;
	if(n==1)	return;
	if(prime[n]==0){
		factors[no_of_factors++]=1;
		return;
	}
	c=0;
	fact=prime[n];
	while(prime[n]==fact || n==fact)
	{
		n=n/fact;
		c++;
	}
	factors[no_of_factors++]=c;
	factorise(n);
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
			factors[i]*=m;
			if(factors[i]>=k);
			final_factors[no_of_final_factors++]=factors[i];
		}
		for(i=0;i<no_of_final_factors;i++)
		{
			range[i]=-(final_factors[i]/(k+1))+(final_factors[i]/k);
			
			/*while((final_factors[i]-r*k)<r)
			{
				range[i]++;
				r--;
			}*/
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
					ans*=((final_factors[j]/k)+1);
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