#include<stdio.h>
#include<string.h>
long long int exep(int a,int b)
{
long long int z=1;
int i;
for(i=1;i<=b;i++)
z*=a;
return z;
}
int main()
{
int test,count,i,l;
char s[100];
int t[100];
long long int ans;
scanf("%d",&test);
while(test-->0)
{
	count=0;
	ans=0;
	scanf(" %s",s);
	l=strlen(s);
	int a[36];
	int k=1;
	for(i=0;i<36;i++)
		a[i]=-1;
	for(i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			if(a[s[i]-'0']==-1)
			{
				a[s[i]-'0']=k;
				if(k==1)	k=0;
				else if(k==0)	k=2;
				else	k++;
				count++;
			}
			t[i]=a[s[i]-'0'];
		}
		else
		{
			if(a[s[i]-'a'+10]==-1)
			{
				a[s[i]-'a'+10]=k;
				if(k==1)	k=0;
				else if(k==0)	k=2;
				else	k++;
				count++;
			}
			t[i]=a[s[i]-'a'+10];
		}
	}
	if(count==1)	count=2;
//for(i=0;i<l;i++)	printf("%d ",t[i]);
	for(i=l-1;i>=0;i--)
	{
		ans=ans+t[i]*exep(count,l-1-i);
	}
	printf("%lld\n",ans);
}
return 0;
}

