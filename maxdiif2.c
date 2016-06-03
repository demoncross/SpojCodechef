#include<stdio.h>
#define MAX 10000000
int vals[101];
void merge(int i,int j)
    {
    int c[1000],d[1000];
    int mid=(i+j)/2;
    int k,h=0,g=0;
    for(k=0;k<=mid-i;k++)
    c[k]=vals[i+k];
    c[k]=MAX;
    for(k=0;k<j-mid;k++)
    d[k]=vals[mid+1+k];
    d[k]=MAX;
    for(k=i;k<=j;k++)
    {
    if(c[g]<d[h])
    {
    vals[k]=c[g];
    g++;
    }
    else
    {
    vals[k]=d[h];
    h++;
    }
    }
    }
     
    int sort(int start,int end)
    {
    if(start==end)
    return start;
    sort(start,(start+end)/2);
    sort((start+end)/2+1,end);
    merge(start,end);
    }

int main()
{
long long int test,i,j,n,k,sum,ans;
scanf("%lld",&test);
while(test-->0)
{
sum=0;
ans=0;
scanf(" %lld %lld",&n,&k);
for(i=0;i<n;i++)
{
	scanf(" %d",&vals[i]);
	sum+=vals[i];
}
if(k>(n/2))	k=n-k;
sort(0,n-1);
for(i=0;i<k;i++)
	ans+=vals[i];
printf("%lld\n",sum-2*ans);
}
return 0;
}
