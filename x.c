#include<stdio.h>
 
int main()
{
	int t,n,i,val;
	long a[10001],nim_sum,b[10001],temp_sum=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		nim_sum=0;
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			b[i]=a[i]-a[i-1]-1;
		// if i is even i&1=0 else 1
			if((n-i+1) & 1)
			{
				nim_sum^=b[i];
			}
		}
		if(nim_sum==0)
			printf("Johnny wins\n");
		else
		{
			printf("Mary wins\n");
			for(i=1;i<=n;i++)
			{
				if(n-i+1 & 1)
				{
					if((nim_sum^b[i])<b[i])
					{
						printf("Move %ld to %ld\n", a[i], a[i]-b[i]+(nim_sum^b[i]));
						break;
					}
				}
				else if((nim_sum^b[i+1])>b[i+1] && b[i]+b[i+1] >= (nim_sum^b[i+1]))
				{
					printf("Move %ld to %ld\n", a[i], a[i] - (nim_sum^b[i+1])+b[i+1]);
					break;
				}
			}
		}
		printf("\n");
	}
}
