#include<stdio.h>
int values[2010];
int cum[2010];
int main()
{
int i,n,ans,start,end;
scanf(" %d",&n);
for(i=0;i<n;i++)
	scanf(" %d",&values[i]);
cum[0]=0;
for(i=1;i<=n;i++)
	cum[i]=cum[i-1]+values[i-1];
start=0;
end=n-1;
for(i=0;i<n;i++)
{
	if(values[start]<values[end])
	{
		ans+=values[start]+cum[end+1]-cum[start+1];
		start++;
	}
	else
	{
		ans+=values[end]+cum[end]-cum[start];
		end--;
	}
	
}
printf("%d\n",ans);
return 0;
}
