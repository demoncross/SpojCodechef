#include<cstdio>
#include<cstring>
using namespace std;
char s[100000];
int c[102];
int main()
{
	int test,i,l,ans,a,b,j,k,number;
	scanf("%d",&test);
	while(test--)
	{
		for(i=0;i<=9;i++)	c[i]=0;
		scanf("%s",s);
		l=strlen(s);
		for(i=0;i<l;i++)
			c[s[i]-'0']++;
		ans=0;
		if(l==1)
		{
			if((s[0]-'0')%8==0)	printf("YES\n");
			else printf("NO\n");
			continue;
		}
		if(l==2)
		{
			a=(s[0]-'0')*10+(s[1]-'0');
			b=(s[1]-'0')*10+(s[0]-'0');
			if(a%8==0 || b%8==0)	printf("YES\n");
			else	printf("NO\n");
			continue;
		}
		for(i=0;i<=9;i++)
		{
			if(c[i]==0)	continue;
			for(j=0;j<=9;j++)
			{
				if(j==i && c[i]==1)	continue;
				if(c[j]==0)	continue;
				for(k=0;k<=9;k++)
				{
					if(k==j && k==i && c[i]==2)	continue;
					if(k==j && c[k]==1)	continue;
					if(k==i && c[i]==1)	continue;
					if(c[k]==0)			continue;
					number=i*100+j*10+k;
					if(number%8==0)	ans=1;
				}
			}
		}
		if(ans)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}