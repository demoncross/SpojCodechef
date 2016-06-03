#include<cstdio>
#include<cstring>
using namespace std;
char s[1000000],p[10000];
int c1[30],c2[30],c[30];
int main()
{
	int test,tt,i,j,ls,lp;
	scanf("%d",&test);
	while(test--)
	{
		tt=0;
		for(i=0;i<30;i++)
			c1[i]=c2[i]=c[i]=0;
		scanf(" %s",p);
		for(i=0;i<p[i];i++)
			c1[p[i]-'a']++;
		scanf(" %s",s);
		ls=strlen(s);
		lp=strlen(p);
		j=0;
		for(i=0;i<ls;i++)
		{
			for(;i+j<ls && j<lp;j++)
			{
				c[s[i+j]-'a']++;
				if(c[s[i+j]-'a']>c1[s[i+j]-'a'])
				{
					c[s[i+j]-'a']--;
					if(j!=0)
					{	c[s[i]-'a']--;
						j--;
					}
					break;
				}
			}
			if(j==lp){
				printf("YES\n");tt=1;break;}
		}
		if(!tt)
		printf("NO\n");
	}
	return 0;
}