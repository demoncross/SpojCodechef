#include<string.h>
#include<stdio.h>
char s[50];
char q[50];
int main()
{
int i,r,d,j,k,l,ans,sum;
scanf(" %s",s);
while(s[0]!='-')
{
if(s[0]=='0')
{
	printf("0\n");
	scanf(" %s",s);
	continue;
}
l=strlen(s);
sum=0;
r=0;
k=1;
j=0;
for(i=0;i<l;i++)
{
	d=r*10+(s[i]-'0');
	if(d>=9)
	{
		q[j]=(d/9)+'0';
		j++;
		r=d%9;
	}
	else
	{
		r=d;
	}
	k=k*10;
}
if(r!=0)	
{
	for(i=0;i<j;i++)
	{
		if(q[i]!='9')	break;
	}
	if(i==j)
	{
		printf("1");
		for(i=1;i<=j;i++)
			printf("0");
		printf("\n");
		scanf(" %s",s);
		continue;
	}
	else
	{
		for(i=j-1;i>=0;i--)
		{
			if(q[i]!='9')
			{
				q[i]++;
				break;
			}
			else
				q[i]='0';
		}
	}
}
q[j]=0;
printf("%s\n",q);
scanf(" %s",s);
}
return 0;
}
