#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char *p;
int *a;

void process(void)
{
int i,len,k;
a[0]=0;
k=0;
len=strlen(p);
for(i=1;i<len;i++)
{
	while(k>0 && p[i]!=p[k])
		k=a[k-1];
	if(p[k]==p[i])
		k=k+1;
	a[i]=k;
}
}


int main()
{
int i,l,len,q,l_sofar,end;
char ch;
while(1)
{
	scanf("%d ",&l);
	p=(char *)malloc(l+2);
	a=(int *)malloc(sizeof(int)*(l+2));
	scanf("%s ",p);
	process();
	q=0;
	l_sofar=0;
	while(1)
	{
		end=scanf("%c",&ch);
		if(ch=='\n')
		{	
			printf("\n");
			break;
		}
		while(q>0 && ch!=p[q])
			q=a[q-1];
		if(ch==p[q])
			q++;
		if(q==l)
		{
			printf("%d\n",l_sofar-l+1);
			q=a[q-1];
		}
		l_sofar++;
		if(end==EOF)
			break;
	}
	if(end==EOF)	break;
}
return 0;
}
