#include<stdio.h>
typedef long long ll;
 int a[100005];
ll max(ll a,ll b)
{
	return (a<b?b:a);
}
int main()
{
ll i,n,max_ending_at,max_so_far,t,max_ways_so_far,max_ways_ending_at;
scanf("%lld",&t);
while(t--)
{
	max_so_far=-1000000000;
	max_ending_at=-1;
	max_ways_so_far=0;
	max_ways_ending_at=1;
	scanf("%lld",&n);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		//max_ways_ending_at=(max_ending_at==0)?max_ways_ending_at+1:max_ways_ending_at;
		if(max_ending_at+a[i]>a[i])
			{}	
		else if(max_ending_at+a[i]<a[i])
			max_ways_ending_at=1;
		else
			max_ways_ending_at+=1;
		max_ending_at=max(max_ending_at+a[i],a[i]);		
		if(max_so_far<max_ending_at)
		{
			max_so_far=max_ending_at;
			max_ways_so_far=max_ways_ending_at;
		}
		else if(max_so_far==max_ending_at)
		{
			max_ways_so_far+=max_ways_ending_at;
		}
	}
	printf("%lld %lld\n",max_so_far,max_ways_so_far);
}
return 0;
}
