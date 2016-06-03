#include <cstdio>
#include <cstring>
#define MOD 1000000007

using namespace std;
typedef long long int ll;

char s[100006];
ll c[30];

int main()
{
	ll t,l,i,sum,q;
	scanf("%lld",&t);
	while(t--)
	{
		for(i=0;i<30;i++)	c[i]=0;
			c[0]=1;
		scanf("%s",s);
		l=strlen(s);
		sum=1;
		for(i=0;i<l;i++)
		{	
			q=c[s[i]-'A'+1]
;			c[s[i]-'A'+1]=sum;
			sum=(sum+sum-q);
			while(sum<0)	sum+=MOD;
			sum=sum%MOD;
		}
		printf("%lld\n",sum);
	}
	return 0;
}