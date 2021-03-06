#include<stdio.h>
typedef long long int ll;
ll a[1000005];
int n,m;
ll sum[1000005];


void sort(int start,int end)
{
if(start>end) return;
int key,i,j,k;
key=a[end];
k=start;
for(i=start;i<end;i++)
{
if(a[i]<=key)
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




int work(int q)
{
int left,right,mid,r;
ll p,o;
left=a[q];
right=a[q+1];
p=sum[n]-sum[q];
r=n-q;
while(1)
{
	mid=(left+right)>>1;
	o=p-(mid*r);
	if(o==m)	return mid;
	else if(o<m && o+r>=m)	return (mid-1);
	else if(o>m)
		left=mid+1;
	else	
		right=mid+1;
}
}



int main()
{
int t,ans,i,start,end;
ll x,y;
t=1;
while(t--)
{
	scanf("%d%d",&n,&m);
	a[0]=0;
	for(i=1;i<=n;i++)	scanf("%d",&a[i]);
		//printf("*\n");
	sort(0,n);
	sum[0]=0;	
	for(i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
	start=0;
	end=n;
	while(start<=end)
	{
		i=(start+end)>>1;	
		x=sum[n]-sum[i]-(a[i]*(n-i));
		y=sum[n]-sum[i+1]-(a[i+1]*(n-i-1));
		if(x>=m && y<=m)
		{
			//printf("%d\n",i);
			ans=work(i);
			break;
		}
		else if(x>=m)
			start=i+1;
		else
			end=i-1;
	}
	printf("%d\n",ans);	
}
return 0;
}
