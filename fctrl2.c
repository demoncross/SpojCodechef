#include<string.h>
#include<stdio.h>
char s[100000];
int main()
{
int i,j,l,p,c,test,n;
scanf("%d",&test);
while(test--)
{
	scanf("%d",&n);
	s[0]='1';
	s[1]=0;
	if(n==0){printf("1\n");continue;}
	for(i=2;i<=n;i++)
	{	c=0;
		l=strlen(s);
		for(j=0;j<l;j++)
		{
			p=(s[j]-'0')*i+c;
			s[j]=p%10+'0';
			c=p/10;
		}
		while(c>0)
		{
			s[j]=c%10+'0';
			j++;
			c=c/10;
		}
		s[j]=0;
	}
	l=strlen(s);
	for(i=l-1;i>=0;i--)	printf("%c",s[i]);
	printf("\n");
}
return 0;
}
