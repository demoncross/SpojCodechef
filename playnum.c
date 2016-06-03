#include<stdlib.h>
#define MAX 1000009
#include<stdio.h>
void merge(int *a,int i,int j)
{
int c[1000],d[1000];
int mid=(i+j)/2;
int k,h=0,g=0;
for(k=0;k<=mid-i;k++)
c[k]=a[i+k];
c[k]=MAX;
for(k=0;k<j-mid;k++)
d[k]=a[mid+1+k];
d[k]=MAX;
for(k=i;k<=j;k++)
{
if(c[g]<d[h])
{
a[k]=c[g];
g++;
}
else
{
a[k]=d[h];
h++;
}
}
}

void sort(int *a,int start,int end)
{
if(start==end)
return ;
sort(a,start,(start+end)/2);
sort(a,(start+end)/2+1,end);
merge(a,start,end);
}

int main()
{
int *a,*freq;
int test,i,q,a1,a2,n,no,j;
long long int ans;
scanf("%d",&test);
while(test-->0)
{
	no=0;
	ans=0;
	scanf(" %d %d",&n,&q);
	freq=(int *)malloc((n+1)*sizeof(int));
	for(i=0;i<=n;i++)	freq[i]=0;
	a=(int *)malloc((n+1)*sizeof(int ));	
	for(i=0;i<n;i++)	scanf(" %d",&a[i]);
	for(i=1;i<=q;i++)
	{
		scanf(" %d %d",&a1,&a2);
		for(j=a1;j<=a2;j++)	freq[j]++;
	}
	sort(a,0,n);
	sort(freq,0,n);
	for(i=n;i>=0;i--)
	{
		ans=ans+freq[i]*a[i];
	}
	printf("%lld\n",ans);
	free(a);
	free(freq);
}
return 0;
}
