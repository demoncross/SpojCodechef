#include<stdio.h>
int a[10000009],b[10000009];
int main()
{
	int t,i,q,e,n;
	long long ans,q_1,q_2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<=10*n;i++)	a[i]=b[i]=0;
		q=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&e);
			q=q+e;
			if(q<0)
				b[-q]++;
			else
				a[q]++;
		}
		ans=a[0]+((((long long)a[0])*(a[0]-1))>>1);
		for(i=1;i<=10*n;i++)
		{
			q_1=(((long long)a[i])*(a[i]-1))>>1;
			q_2=(((long long)b[i])*(b[i]-1))>>1;
			ans+=q_1+q_2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}