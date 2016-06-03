#include<stdio.h>
typedef struct rr
{
int x,y;
}node;
node a[1009];
int dp[1009],c[1009];
int len;

void sort(int start,int end)
{
if(start>end) return;
int key,i,k;
node j;
key=a[end].x;
k=start;
for(i=start;i<end;i++)
{
if(a[i].x<key||(a[i].x==key && a[i].y<=a[end].y))
{
j=a[i];
a[i]=a[k];
a[k]=j;
k++;
}
}
j=a[end];
a[end]=a[k];
a[k]=j;
sort(start,k-1);
sort(k+1,end);
}


int bin_search(int l,int r,int key)
{
	int m,ans;
   	while(r>l) 
	{
	        m =(l+r+1)>>1;
		if(c[m]<=key)	l=m;
		else		r=m-1;
    	}
	return r+1;
}
 
int lis(void)
{
	int i,z,k;
	z=1;
	c[1]=a[0].y;
	dp[0]=1;
	for(i=1;i<len;i++)
	{
		if(a[i].y<c[1])
		{
			c[1]=a[i].y;
			dp[i]=1;
		}
		else if(a[i].y>=c[z])
		{
			c[++z]=a[i].y;
			dp[i]=z;
		}
		else
		{
			k=bin_search(1,z,a[i].y);
			c[k]=a[i].y;
			dp[i]=k;
		}
	}
	return z;
}



int main()
{
int i,t;
scanf("%d",&t);
while(t--)
{
	scanf("%d",&len);
	for(i=0;i<len;i++)	scanf("%d",&a[i].x);
	for(i=0;i<len;i++)	scanf("%d",&a[i].y);
	sort(0,len-1);
	printf("%d\n",lis());
}
return 0;
}
