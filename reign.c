
#include<stdio.h>
typedef long long int ll;
int n,k;
ll a[100005];
ll sum[100005];
ll max(ll a,ll b)
{
	return (a<b?b:a);
}



ll max_subarrayd(int start,int end)
{
ll max_ending_at=0,i,max_so_far=-100000000000000000;
max_ending_at=a[start]+a[start+1];
for(i=start+2;i<=end;i++)
{
	max_ending_at=max(max_ending_at+a[i],a[i]+a[i-1]);
	if(max_so_far<max_ending_at)
		max_so_far=max_ending_at;
}
return max_so_far;
}



ll max_subarray(int start,int end)
{
ll max_ending_at=0,i,max_so_far=-100000000000000000;
for(i=start;i<=end;i++)
{
	max_ending_at=max(max_ending_at+a[i],a[i]);
	if(max_so_far<max_ending_at)
		max_so_far=max_ending_at;
}
return max_so_far;
}

int min_subarray_k(void)
{
int i,ans;
ll q,m=10000000000000000;
for(i=k;i<n-1;i++)
{
	q=sum[i]-sum[i-k];
	if(q<m)
	{
		m=q;
		ans=i-k;
	}
}
return ans;
}

int main()
{
int t,i,p,minimum;
ll ans,x,y;
scanf("%d",&t);
while(t--)
{
	scanf("%d%d",&n,&k);
	//minimum=0;
	for(i=0;i<n;i++)	
	{
		scanf("%lld",&a[i]);
	}
	sum[0]=a[0];	
	for(i=1;i<n;i++)	sum[i]=sum[i-1]+a[i];
	if(n==2)
	{
		printf("%lld\n",sum[1]);
		continue;
	}
	if(k==0)	
	{
		for(i=0;i<n;i++)
		{
			if(a[i]<0) break;
		}	
		if(i==n)	ans=sum[n-1];
		else
		{
			minimum=1;
			for(i=2;i<n-1;i++)
			{
				if(a[i]<a[minimum])	minimum=i;
			}
			x=max_subarray(0,minimum-1)+max_subarray(minimum+1,n-1);
			y=max_subarrayd(0,n-1);
			ans=max(x,y);
		}
	}	
	else
	{
		p=min_subarray_k();
		ans=max_subarray(0,p)+max_subarray(p+k+1,n-1);
	}
	//printf("%d ",k);
	//printf("%lld %d %d %d",max_subarray(0,p),p,p+k+1,n-1);
	printf("%lld\n",ans);
}
return 0;
}
;