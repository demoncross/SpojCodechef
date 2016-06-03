#include<cstdio>
#include<cstring>
#include<cstdlib>
typedef long long int ll;
ll count[1<<10];
int no_of_set_bits(ll n)
{
	int j,ans=0;
	for(j=0;j<=10;j++)
	{
		if(n&(1<<j))	ans++;
	}
	return ans;
}
int main()
{
	ll l,i,j,n,k,ans,q;
	char s[20];
	int taken[15];
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %s",s);
		l=strlen(s);
		for(k=0;k<=9;k++)	taken[k]=0;
		for(k=0;k<l;k++)
		{
			q=s[k]-'0';
			taken[q]=1;
		}
		//for(k=0;k<=9;k++)	printf("%d ",taken[k]);
		for(k=1;k<(1<<10);k++)
		{
			for(j=0;j<=10;j++)
			{
				if(k&(1<<j))
				{
					if(taken[j])	continue;
					else			break;
				}
			}
			if(j==11)
				count[k]++;
		}
	}
	ans=0;
	for(i=1;i<(1<<10);i++)
	{
		if(no_of_set_bits(i)%2)	
		{
			q=(count[i]*(count[i]-1))>>1;
			ans+=q;
		}
		else
		{
			q=(count[i]*(count[i]-1))>>1;
			ans-=q;	
		}
	}
	//for(i=1;i<(1<<5);i++)	printf("%d\n",count[i]);
	printf("%lld\n",ans);
	return 0;
}