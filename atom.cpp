#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
char s[1000006],t[1000006];
long long int a[150],b[150];
int main()
{
	long long int test,l,m,n,i,ans,j,max,min;
	scanf("%lld",&test);
	while(test--)
	{
		for(i=0;i<150;i++)	a[i]=b[i]=0;
		ans=0;
		scanf("%s %s",s,t);
		l=strlen(s);
		for(i=0;i<l;i++)
		{
				for(j=i+1;j<l && s[j]==s[i];j++){}
				if(a[s[i]]<j-i)
					a[s[i]]=j-i;
				i=j-1;
		}
		l=strlen(t);
		for(i=0;i<l;i++)
		{
				for(j=i+1;j<l && t[j]==t[i];j++){}
				if(b[t[i]]<j-i)
					b[t[i]]=j-i;
				i=j-1;
		}
		max=0;
		for(i=0;i<150;i++)
		{
			if(a[i]+b[i]>max)	max=a[i]+b[i];
		}
		printf("%lld",max);
	}
	return 0;
}