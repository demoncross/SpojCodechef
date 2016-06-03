#include<string.h>
#include<stdio.h>
int main()
{
char s[1005];
int i,l,ans,t;
while(scanf("%s",s)!=EOF)
{
	l=strlen(s);
	ans=0;
	if(s[0]>='a')	t=1;
	else				t=0;
	for(i=1;i<l;i++)
	{
		if((i%2 && s[i]>='a' && t==1)||(i%2 && s[i]<='Z' && t==0))
			ans++;
		if((i%2==0 && s[i]>='a' && t==0)||(i%2==0 && s[i]<='Z' && t==1))
			ans++;
	}
	if(ans>l-ans)	ans=l-ans;
	printf("%d\n",ans);
}
return 0;
}
