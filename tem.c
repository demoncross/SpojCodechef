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
	int test,i,j,k,l,t,q,q_s,q_e,x,y,z,i1,j1,k1,n,l1,ans,ans_s,ans_e;
	scanf("%d",&test);
	for(i=0;i<55;i++)
		for(j=0;j<55;j++)	m[i][0][j]=m[i][j][0]=0;
	while(test--)
	{
		scanf("%d%d%d",&x,&y,&z);
		ans=-10000000;
		for(i=0;i<x;i++)
		{
			for(j=0;j<y;j++)
			{
				for(k=0;k<z;k++)	scanf("%d",&a[i][j][k]);
			}
			for(j=1;j<=y;j++)
			{
				for(k=1;k<=z;k++)
				{
					m[i][j][k]=a[i][j-1][k-1]+m[i][j][k-1]+m[i][j-1][k]-m[i][j-1][k-1];
				}
			}
		}
		for(i=0;i<y;i++)
		{
			for(j=i+1;j<=y;j++)
			{
				for(k=0;k<z;k++)
				{
					for(l=k+1;l<=z;l++)
					{
						for(t=0;t<x;t++)
						{
							b[t]=m[t][j][l]-m[t][j][k]-m[t][i][l]+m[t][i][k];
						}
						q=kadanes(b,x,&q_s,&q_e);
						if(q>ans)
						{
							ans=q;
							ans_s=q_s;
							ans_e=q_e;
							i1=i,j1=j,k1=k,l1=l;
						}
					}
				}
			}
		}//printf("%d\n",ans);
		printf("%d %d %d %d %d %d\n",ans_s+1,i1+1,k1+1,ans_e+1,j1,l1);

	}
	return 0;
}