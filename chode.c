#include<stdio.h>
#include<string.h>
typedef struct a
{
int v;
char c;
}node;

char freq[30];
char text[150005];
node a[28];
char map[28];

void sort(int start,int end)
{
if(start>end) return;
int i,k;
node key,j;
key=a[end];
k=start;
for(i=start;i<end;i++)
{
if(a[i].v<key.v ||((a[i].v==key.v) && (a[i].c<key.c)))
{
j=a[i];
a[i]=a[k];
a[k]=j;
k++;
}
}
j=a[end];
a[end]=a[k];
a[k]=j;
sort(start,k-1);
sort(k+1,end);
}


int main()
{
int t,l,i;
char c;
scanf("%d",&t);
while(t--)
{
	for(i=0;i<=25;i++)
	{
		a[i].v=0;
		a[i].c=i+'a';
	}
	scanf(" %s %[^\n]s",freq,text);
	l=strlen(text);
	for(i=0;i<l;i++)
	{
		c=text[i];
		if(c>='a' && c<='z')
			a[c-'a'].v++;
		else if(c>='A' && c<='Z')
			a[c-'A'].v++;
	}
	sort(0,25);
	for(i=25;i>=0;i--)
		map[a[i].c-'a']=freq[i];
	//for(i=0;i<=25;i++)
	//	printf("%c %c\n",i+'a',map[i]);	
	for(i=0;i<l;i++)
	{
		c=text[i];
		if(c>='A' && c<='Z' )		
			printf("%c",map[c-'A']-'a'+'A');
		else if(c>='a' && c<='z')
			printf("%c",map[c-'a']);
		else 	
			printf("%c",c);
	}
	printf("\n");
}
return 0;
}
