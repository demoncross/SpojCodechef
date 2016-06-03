#include<stdio.h>
#include<string.h>
char s[100005];
int main()
{
	int i,l,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		l=strlen(s);
		if(l<3)
			printf("Bad\n");
		else
		{
			//a=(s[0]-'0')*10+(s[1]-'0');
			for(i=2;i<l;i++)
			{
				if((s[i-2]=='1' && s[i-1]=='0' && s[i]=='1')||(s[i-2]=='0' && s[i-1]=='1' && s[i]=='0'))
				{
					printf("Good\n");
					break;
				}
			}
			if(i==l)
				printf("Bad\n");
		}
	}
	return 0;
}