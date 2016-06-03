#include<stdio.h>
#define max 1005
typedef struct p{
int n, k;
}t;
t a[max];
void sort(int start,int end)
{
if(start>end) return;
int i,k,key;
t j;
key=a[end].n;
k=start;
for(i=start;i<end;i++)
{
if(a[i].n<=key)
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
int ans[max];
int main()
{
int test,i,n,j,no,m;
scanf("%d",&test);
while(test--)
{
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&a[i].n);
	for(i=0;i<n;i++)	{scanf("%d",&a[i].k);ans[i]=100000000;}
	sort(0,n-1);
	for(i=0;i<n;i++)
	{
		no=a[i].k;
		m=0;
		for(j=0;j<n;j++)
		{
			if(ans[j]==100000000)	
			{
				if(m==no)	{ans[j]=a[i].n;break;}
				else m++;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");
}
return 0;
}
