#include<cstdio>
int a[1005];
int main()
{
	int n,i,last,first,aq,b,chance,q;
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	last=n-1;
	first=0;
	chance=1;
	aq=b=0;
	while(1)
	{
		if(last<first)	break;
		if(a[last]>a[first])
		{
			q=a[last];
			last--;
		}
		else
		{
			q=a[first];
			first++;
		}
		if(chance==1)
		{
			aq+=q;
			chance=2;
		}
		else
		{
			b+=q;
			chance=1;
		}
	}
	printf("%d %d\n",aq,b);
}