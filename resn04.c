#include<stdio.h>
int main()
{
int t,n,i,q,ans;
scanf("%d",&t);
while(t--)
{
	ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&q);
		ans+=(q/i);
	}
	if(ans%2)
		printf("ALICE\n");
	else	
		printf("BOB\n");
}
return 0;
}
