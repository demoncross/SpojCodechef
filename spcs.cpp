#include<cstdio>
#include<cstring>
using namespace std;
char s[100005],a[100005];
int main()
{
	int l,q,t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		l=strlen(s);
		q=0;
		for(i=0;i<l;)
		{
			j=i+1;
			for(;j<l && s[j]==s[i];j++)
			{}
			a[q++]=s[i];
			i=j;
		}
		a[q]=0;
		for(i=0;i<q/2;i++)
		{
			if(a[i]!=a[q-1-i])	break;
		}
		if(i==(q/2))	printf("YES\n");
		else			printf("NO\n");
	}
	return 0;
}