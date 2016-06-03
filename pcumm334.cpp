#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int a[200],b[4],c[4],t,i,n,k;
		k=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		b[0]=a[0];
		c[0]=1;
		c[1]=0;
		for(i=1;i<n;i++)
		{
			if(a[i]==b[k])	c[k]++;
			else if(k==0)
			{
				b[++k]=a[i];
				c[k]++;
			}
			else
				break;
		}
		if(i!=n)	
		{
			printf("-1\n");
		}
		else if(k==0)
		{
			if(b[k]==n-1)	printf("%d\n",n);
			else if(b[k]==0)	printf("0\n");
			else			printf("-1\n");
		}
		else if(c[0]==b[1])
			printf("%d\n",b[1]);
		else
			printf("-1\n");
	return 0;
}