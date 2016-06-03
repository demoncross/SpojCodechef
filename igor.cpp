#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;
	
int dp[1<<16];

int main()
{

	int test,c,n,k,no,t,i,j,q,ans,a,query,tim,set;
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		char s[20];
		scanf("%d%d",&n,&k);
		no=0;
		scanf("%s",s);
		for(i=0;i<strlen(s);i++)
		{
			c=s[i];
			if(c=='+')
				no=(no<<1)+1;
			else
				no=(no<<1)+0;
		}
		dp[0]=0;
		q=1;
		tim=0;
		set=0;
		while(q!=0)
		{
			tim++;
			dp[tim]=q;
			if(q==no)	set=tim;
			if(q&(1<<(n-1)))
			{
				q^=1;
				q=q%(1<<(n-1));
				q<<=1;
			}
			else
			{
				q=q%(1<<(n-1));
				q=(q<<1)+1;	
			}
		}
		//for(i=0;i<(1<<n);i++)	printf("%d\n",dp[i]);
		printf("Experiment #%d:\n",t);
		if(n==1)
		{
			for(i=0;i<k;i++)
			{
				scanf("%d",&query);
				if(no==0 && query==0)	printf("-\n");
				else					printf("+\n");
			}
			continue;
		}
		for(i=0;i<k;i++)
		{
			scanf("%d",&query);
			a=(set+query)%(tim+1);
			ans=dp[a];
			//printf("%d %d\n",no,ans);
			for(j=n-1;j>=0;j--)
			{
				if(ans&(1<<j))	printf("+");
				else			printf("-");	
			}
			printf("\n");
		}
	}
	return 0;
}