#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	return (a>b?a:b);
}
char s[10004];
int l;
void work(int *a,int *b,int n)
{
	if(n>=l-1 || s[n]=='l')
	{
		*a=0;
		*b=n;
		return;
	}
	int left,end,right,lp;
	work(&left,&end,n+1);
	work(&right,&lp,end+1);
	*a= (max(left,right)+1);
	*b= lp;
}
int main()
{
int test;
scanf("%d",&test);
while(test--)
{
scanf("%s",s);
l=strlen(s);
int ans,p;
work(&ans,&p,0);
printf("%d\n",ans);
}
return 0;
}
