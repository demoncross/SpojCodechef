#include<stdio.h>
#include<string.h>
int min(int a,int b)
{
	return (a<b?a:b);
}
int main()
{
char a[1004],b[1004];
int f1[27],f2[27];
int x,j,l1,l2,i;
while(scanf("%s%s",a,b)!=EOF)
{
	for(i=0;i<27;i++)	f1[i]=f2[i]=0;
	l1=strlen(a);
	l2=strlen(b);
	for(i=0;i<l1;i++)
		f1[a[i]-'a']++;
	for(i=0;i<l2;i++)
		f2[b[i]-'a']++;
	for(i=0;i<26;i++)
	{
		x=min(f1[i],f2[i]);
		for(j=0;j<x;j++)	printf("%c",i+'a');
	}
	printf("\n");
}
return 0;
}
