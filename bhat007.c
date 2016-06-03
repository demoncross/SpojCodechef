#include<stdio.h>
#include<string.h>
char a[100],b[100],ans1[100],ans2[100];

void add(char *ans,int base)
{
int l1,l2,p1,p2,p,c,x,y;
l1=strlen(a);
l2=strlen(b);
p1=l1-1;p2=l2-1,p=0,c=0;
while(p1>=0 || p2>=0)
{
	if(p1<0)	x=0;
	else		x=a[p1]-'0';
	if(p2<0)	y=0;
	else		y=b[p2]-'0';
	ans[p]=(x+y+c)%base+'0';
	c=(x+y+c)/base;
	p1--;
	p2--;
	p++;
}
if(c>0)	ans[p++]=c+'0';
ans[p]=0;
}

int main()
{
int t,b1,b2;
scanf("%d",&t);
while(t--)
{
	scanf("%s%s%d%d",a,b,&b1,&b2);
	add(ans1,b1);
	add(ans2,b2);
	if(strcmp(ans1,ans2))	printf("no\n");
	else			printf("yes\n");
}
return 0;
}
