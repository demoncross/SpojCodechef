#include<stdio.h>
int a[10004],b[10004],sum_a[10004],sum_b[10004];

int search(int * array,int query,int start,int end)
{
int mid;
while(start<=end)
{
	mid=(start+end)/2;
	if(array[mid]==query)
		return mid;
	else if(array[mid]<query)
		start=mid+1;
	else
		end=mid-1;
}
return -1;
}

int main()
{
int t,option_a,option_b,i,n1,n2,p,q,ans;
scanf(" %d",&n1);
while(n1){
sum_a[0]=sum_b[0]=0;
for(i=1;i<=n1;i++)
{
	scanf(" %d",&a[i-1]);
	sum_a[i]=sum_a[i-1]+a[i-1];
}
scanf(" %d",&n2);
for(i=1;i<=n2;i++)
{
	scanf(" %d",&b[i-1]);
	sum_b[i]=sum_b[i-1]+b[i-1];
}
p=q=-1;
ans=0;
for(i=0;i<n1;i++)
{
	t=search(b,a[i],0,n2-1);
	if(t!=-1)
	{
		option_a=sum_a[i+1]-sum_a[p+1];
		option_b=sum_b[t+1]-sum_b[q+1];
		if(option_a>option_b)
			ans+=option_a;
		else
			ans+=option_b;
		p=i;
		q=t;
	}
}
option_a=sum_a[n1]-sum_a[p+1];
option_b=sum_b[n2]-sum_b[q+1];
if(option_a>option_b)
	ans+=option_a;
else
	ans+=option_b;
printf("%d\n",ans);
scanf(" %d",&n1);
}
return 0;
}
