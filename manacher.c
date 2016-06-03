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
int l,c,r,i,m,max;
int p[200009];
l=strlen(s);
c=0,r=0;
max=0;
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
	if(max<p[i])
		max=p[i];
}
return max;
}
int main()
{
int a;
char q[100009];
scanf("%d%s",&a,q);
make(q);
printf("%d\n",max_pal());
return 0;
}
