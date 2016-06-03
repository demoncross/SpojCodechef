#include<stdio.h>
int c[100],dp[100];
int a[100]={2,2,5,7,2,3,4};
int len=7;

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
		if(c[m]<=key)	l=m;
		else		r=m-1;
    	}
	return r+1;
	
}
 
int lis(void)
{
	int i,z,k;
	z=1;
	c[1]=a[0];
	dp[0]=1;
	for(i=1;i<len;i++)
	{
		if(a[i]<c[1])
		{
			c[1]=a[i];
			dp[i]=1;
		}
		else if(a[i]>=c[z])
		{
			c[++z]=a[i];
			dp[i]=z;
		}
		else
		{
			k=bin_search(1,z,a[i]);
			c[k]=a[i];
			dp[i]=k;
		}
	}
	return z;
}

int main()
{
	int i;
	printf("%d\n",lis());
	//for(i=1;i<=10;i++)	printf("%d\n",c[i]);
	return 0;
}
