#include<stdio.h>
int main()
{
int n,i,f=0;
char c;
int freq[27]={0};
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf(" %c%*s",&c);
	freq[c-'a']++;
}
for(i=0;i<=26;i++)
{
	if(freq[i]>=5)	{f=1;printf("%c",'a'+i);}
}
if(f==0)	printf("PREDAJA");
printf("\n");
return 0;
}
