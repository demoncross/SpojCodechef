#include<stdio.h>
#include<math.h>
#define max 100000008
int a[max];
void make(void)
{
	int i,j,l;
	l=1;
	for(i=2;i*i<=max;i++)
	{
		if(a[i]==0)
		{
			a[i]=l;
			l++;
			for(j=2;j*i<=max;j++)	a[j*i]=-1;
		}
	}
}
int main()
{
	make();
	int t,n,r,c;
	float f;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(a[n]==-1)
		{
			printf("-1\n");
			continue;
		}
		f=1+(8*a[n]);;
		f=(sqrt(f)-1)/2;
		r=f;
		if((float)r!=f)	r+=1;
		c=a[n]-((r*(r-1))>>1);
		printf("%d %d\n",r,c);
	}
	return 0;
}