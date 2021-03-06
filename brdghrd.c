#include<stdio.h>
#define MAX 32765600	
typedef struct rr
{
int x,y;
}node;
node a[100009];
int c[100009];
int len;
//int a[n];
void merge(int i,int j)
{
node c[100009],d[100009];
int mid=(i+j)/2;
int k,h=0,g=0;
for(k=0;k<=mid-i;k++)
c[k]=a[i+k];
c[k].x=MAX;
for(k=0;k<j-mid;k++)
d[k]=a[mid+1+k];
d[k].x=MAX;
for(k=i;k<=j;k++)
{
if(c[g].x<d[h].x || (c[g].x==d[h].x && c[g].y<d[h].y))
{
a[k]=c[g];
g++;
}
else
{
a[k]=d[h];
h++;
}
}
}

int sort(int start,int end)
{
if(start==end)
return start;
sort(start,(start+end)/2);
sort((start+end)/2+1,end);
merge(start,end);
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
	//dp[0]=1;
	for(i=1;i<len;i++)
	{
		if(a[i].y<c[1])
		{
			c[1]=a[i].y;
	//		dp[i]=1;
		}
		else if(a[i].y>=c[z])
		{
			c[++z]=a[i].y;
	//		dp[i]=z;
		}
		else
		{
			k=bin_search(1,z,a[i].y);
			c[k]=a[i].y;
	//		dp[i]=k;
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
