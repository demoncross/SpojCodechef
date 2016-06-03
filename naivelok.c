#include<stdio.h>
#include<string.h>
int main()
{
long long int t,l,a,b,ans,x=1;;
char s[105];
scanf("%lld",&t);
while(t--)
{
	scanf("%s",s);
	l=strlen(s);
	//if(l==1)
	//{printf("0\n");continue;}
	if(l<60)
	{
		a=(x<<l)-1;
		b=(x<<(l/2))-1;	
	}
	else
	{
		a=(x<<50)%1000000007;
		a=(a*(x<<(l-50))%1000000007)-1;
		b=(x<<(l/2))-1;
	}
	if(l%2)
	{
		ans=(a-l-2*b)%1000000007;
	}
	else
	{
		ans=(a-3*b)%1000000007;
	}
	printf("%lld\n",ans);
}
return 0;
}
