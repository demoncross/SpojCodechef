#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long int ll;

int array[20005],c[25],m;

int work(int conditio,int p)
{
	//printf("C::%d\n",conditio);
	if((conditio>=((1<<m)-1))||(p>=m))	
		{
		//	printf("%d ",conditio);
		//	printf("***\n");
			return 0;
		}
	int i,q,ma=work(conditio,p+1);
	if((conditio&(1<<p))==0)
	{
		q=1+work(conditio|c[p],p+1);
			//printf("%d\n",q);
		if(q>ma)	ma=q;
	}
	//printf("%d\n",ma);
	return (ma);
}

int main()
{
	int i,j,n,q,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)	array[i]=0;
	for(i=0;i<=m;i++)	c[i]=0;
	for(i=0;i<m;i++)
	{
		scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&q);
			array[q]|=(1<<i);
		}
	}
	//for(i=1;i<=n;i++)	printf("%d\n",array[i]);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(array[i]&(1<<j))
			{
				c[j]|=array[i];
			}
		}
	}
	//for(i=0;i<m;i++)	printf("%d\n",c[i]);
	printf("%d\n",work(0,0));
	return 0;
}