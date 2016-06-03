#include <stdlib.h>
#include <stdio.h>
int a[55][55][55],m[55][55][55],b[55];
int kadanes(int *b,int n,int *s,int *e)
{
	int max_ending_at=b[0],max_ending_at_s=0,max_ending_at_e=0,max_so_far=b[0],i;
	*s=*e=0;
	for(i=1;i<n;i++)
	{
		//max_ending_at=max(max_ending_at+b[i],b[i]);
		//max_so_far=max(max_so_far,max_ending_at);
		if(max_ending_at+b[i]<b[i])
		{
			max_ending_at=b[i];
			max_ending_at_s=i;
			max_ending_at_e=i;
		}
		else if(max_ending_at+b[i]>=b[i])
		{
			max_ending_at=max_ending_at+b[i];
			max_ending_at_e++;
		}
		if(max_so_far<max_ending_at)
		{
			max_so_far=max_ending_at;
			*s=max_ending_at_s;
			*e=max_ending_at_e;
		}
	}
	return max_so_far;
}
int main()
{
	int n,i,ans,s,e;
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&b[i]);
	ans=kadanes(b,n,&s,&e);
	printf("%d %d %d\n",ans,s,e );
	return 0;
}