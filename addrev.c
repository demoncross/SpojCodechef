#include<stdio.h>
#include<string.h>
int main()
{
char s1[20],s2[20],ans[20];
int c=0,d,sum,test,i,k,l1,l2,max;
scanf("%d",&test);
while(test-->0)
{
	k=0;
	scanf(" %s %s",s1,s2);
	l1=strlen(s1);
	l2=strlen(s2);
	max=(l1>l2?l1:l2);
	for(i=0;i<max;i++)
	{
		if(i<l1 && i<l2)
		{
			sum=s1[i]+s2[i]-2*'0'+c;
		}
		else if(i<l1)
		{
			sum=s1[i]-'0'+c;
		}
		else
		{
			sum=s2[i]-'0'+c;
		}
		d=sum%10;
		c=sum/10;
		if(!(k==0 && d==0))
		{
			ans[k]=d+'0';
			k++;
		}
	}
	while(c>0)
	{
		ans[k]=c%10+'0';
		c=c/10;
		k++;
	}
	ans[k]=0;
	printf("%s\n",ans);
}
return 0;
}
