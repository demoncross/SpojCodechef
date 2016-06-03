#include<stdio.h>
struct as
{
	int c,w;
};
struct as a[15];
int main()
{
	int t,i,j,k,n,max,w,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].c,&a[i].w);
		max=0;
		for(i=0;i<(1<<n);i++)
		{
			w=0;
			b=k;
			for(j=0;j<n;j++)
			{
				if(i&(1<<j))
				{
					b-=a[j].c;
					w+=a[j].w;
				}
			}
			//printf("%d %d\n",b,w);
			if(b>=0 && w>max)
				max=w;
		}
		printf("%d\n",max);
	}
	return 0;
}