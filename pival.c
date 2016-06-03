#include<stdio.h>
char s[109];
int main()
{
	int a=10,b=7,i=0;
	printf("3.");
	while(1)
	{
		s[i]='0'+(a/b);
		i++;
		a=(a%b)*10;
		if(i==100)
		{
			s[i]=0;
			printf("%s",s);
			i=0;
		}
	}
	return 0;
}