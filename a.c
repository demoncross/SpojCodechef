#include<stdio.h>
#define n 9
int i,j,z,p,max=0;
int a[]={10,22,9,33,21,50,41,60,80};
int maxendingat[n]={0};
int path[n];
int printpath(int p)
{
if(path[p]==-1)
{
printf("\n%d",a[p]);
return 0;
}
printpath(path[p]);
printf("\n%d",a[p]);
return 0;
}
int main()
{
for(i=0;i<n;i++)
{
	for(j=0;j<i;j++)
	{
		if(a[i]>=a[j] && maxendingat[i]<maxendingat[j]+1)
			{maxendingat[i]=maxendingat[j]+1;
			path[i]=j;}
	}
	if(maxendingat[i]==0)
		{maxendingat[i]=1;
		path[i]=-1;}
	if (max<maxendingat[i])
		{max=maxendingat[i];
		z=i;}
}
printf("\n%d\n",max);
printf("\nthe listis..\n");
printpath(z);
return 0;
}
