#include<cstdio>
#include<cstring>
int main()
{
	int i,j,l,len,c=0;
	char s[105];
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(s[i]!=s[j])	break;
		}
		len=j-i;
		if(len%2==0)	c++;
		i=j-1;
	}
	printf("%d\n",c);
	return 0;
}