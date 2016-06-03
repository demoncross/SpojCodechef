#include<stdio.h>
#include<string.h>
char dividend[50005];
int div(int divider)
{
int l,i,s=0;
l=strlen(dividend);
for(i=0;i<l;i++)
{
	s=s*10+(dividend[i]-'0');
	if(s>=divider)
		s=s%divider;
}
return s;
}
int main()
{
int test;
scanf("%d",&test);
while(test--)
{
scanf("%s",dividend);
if(div(252)==0)	printf("Yes ");
else		printf("No ");
if(div(525)==0)printf("Yes\n");
else		printf("No\n");
}
return 0;
}
