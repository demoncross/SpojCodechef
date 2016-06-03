#include<stdio.h>
#include<string.h>
#define MOD 1000000007
typedef long long int ll;
char s[25];
int l=0;
void convert(int n)
{
	if(n==0)	return;
	convert(n/2);
	if(n%2==1)
		s[l]='1';
	else
		s[l]='0';
	l++;
}

ll power(void)
{
	ll x,ans;
	int len,sum,rem=0,j=0,i;
	len=strlen(s);
	if(len==1)
	{
		//printf("***2<<%d\n",s[0]-'0');
		return (1<<(s[0]-'0'));
	}
	for(i=0;i<len;i++)
	{
		sum=rem*10+(s[i]-'0');
		if(sum>=2)
		{
			s[j]='0'+(sum/2);
			j++;
			rem=sum%2;
		}
		else
		{
			if(i!=0)
			{
				s[j]='0';
				j++;
			}
			rem=sum;
		}
	}
	s[j]=0;
	x=power();
	ans=(x*x)%MOD;
	if(rem)
		return ((ans<<1)%MOD);
	else
		return ans;
}

int main()
{
int t,n;
ll ans;
scanf("%d",&t);
while(t--)
{
	l=0;
	scanf("%d",&n);
	convert(n);
	s[l]=0;
	//printf("%d:",strlen(s)); 
	//power();
	//printf("%s\n",s);
	ans=power();
	ans=(ans*ans)%MOD;
	printf("%lld\n",ans);
}
return 0;
}
