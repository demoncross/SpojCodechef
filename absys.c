#include<stdio.h>
#include<string.h>
int see(char *s)
{
int i,l,num=0;
l=strlen(s);
for(i=0;i<l;i++)
{
	if(s[i]>'9' ||s[i]<'0')	return -1;
	num=num*10+(s[i]-'0');
}
return num;
}
int main()
{
char a[30],b[30],c[39];
int test,x,y,z;
scanf("%d",&test);
while(test--)
{
	scanf(" %s + %s = %s",a,b,c);
	int x,y,sum;
	x=see(a);
	y=see(b);
	z=see(c);
	if(x==-1)
	{
		printf("%d + %d = %d\n",z-y,y,z);
	}
	else if(y==-1)
	{
		printf("%d + %d = %d\n",x,z-x,z);	
	}
	else
		printf("%d + %d = %d\n",x,y,x+y);
}
return 0;
}

