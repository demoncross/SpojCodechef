#include<string.h>
#include<stdio.h>
int gcd(int a,int b)
{
	if(b==0 )	return a;
	return (gcd(b,a%b));
}
int main()
{
int t,i,b,a,g,l;
char s[10];
scanf("%d",&t);
while(t--)
{
	s[0]=0;
	scanf("%*d.%s",s);
	l=strlen(s);
	if(l==0)
	{
		printf("1\n");
		continue;
	}
	b=1;
	a=0;
	for(i=0;i<l;i++)
	{
		a=a*10+(s[i]-'0');
		b*=10;	
	}
	g=gcd(b,a);
	printf("%d\n",b/g);
}
return 0;
}
