#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;
int a[100005],place[100005];
int p[100005];
int bin_search(int l,int r,int key)
{
	int m,ans;
   	while(r>l) 
	{
	        m =(l+r+1)>>1;
		/*if(c[m]>=key && c[m-1]<=key)
			ans= m;
	        if(c[m] > key)			
			  r = m-1;
		if(c[m] <= key)		
			l=m;*/
		if(p[m]<=key)	l=m;
		else		r=m-1;
    	}
	return r+1;
	
}
int lis(int n)
{
	int i,k,l;
	k=1;
	p[1]=a[1];
	for(i=2;i<=n;i++)
	{
		if(a[i]<p[1])	p[1]=a[i];
		else if(a[i]>p[k])
		{
			p[k+1]=a[i];
			k++;
		}
		else
		{
			l=bin_search(1,k,a[i]);
			p[l]=a[i];
		}
	}
	return k;
}

int main()
{
	int test,n,x,i;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)	
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			place[x]=i;
		}
		for(i=1;i<=n;i++)	a[i]=place[a[i]];
		printf("%d\n",lis(n));
	}
	return 0;
}