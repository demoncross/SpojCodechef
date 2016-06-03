#include<string.h>
#include<stdio.h>
char s[200009];
int min(int a,int b)
{
	return (a>b?b:a);
}
void make(char *q)
{
int l,i,k;
l=strlen(q);
s[0]='^';
s[1]='#';
k=2;
for(i=0;i<l;i++)
{
	s[k]=q[i];
	s[k+1]='#';
	k+=2;
}
s[k]='*';
s[k+1]=0;
}
int max_pal(void)
{
int l,c,r,i,m;
int p[200009];
l=strlen(s);
c=0,r=0;
for(i=1;i<l-1;i++)
{
	m=2*c-i;
	p[i]=(r>i)?min(p[m],r-i):0;
	while(s[i+1+p[i]]==s[i-1-p[i]])
		p[i]++;
	if(i+p[i]>r)
	{
		c=i;
		r=i+p[i];
	}
	if(i+p[i]==l-2)
		break;
}
return (i-p[i]-1)/2;
}
int main()
{
int a,l,i;
char q[100009];
char p[100009];
while(gets(q)!=NULL)
{
	int o=0;
	make(q);
	a=max_pal();
	printf("%s",q);
	l=strlen(q);
	for(i=a-1;i>=0;i--)
		{p[o]=q[i];o++;}
	p[o]=0;
	printf("%s\n",p);
}
return 0;
}
