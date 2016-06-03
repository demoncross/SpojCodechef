#include<stdio.h>
#include<stdlib.h>
#define MAX 1000009
int a[109];
void merge(int i,int j)
{
int c[109],d[109];
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
int test,i,n,max_no,max_freq,cur_no,cur_freq;
scanf("%d",&test);
while(test-->0)
{
	max_freq=0;
	scanf(" %d",&n);
	for(i=0;i<n;i++)	scanf(" %d",&a[i]);
	sort(0,n-1);
	cur_no=a[0];
	cur_freq=1;
	for(i=1;i<n;i++)
	{
		if(a[i]==cur_no)	cur_freq++;
		else
		{
			if(cur_freq>max_freq)
			{
				max_freq=cur_freq;
				max_no=cur_no;
			}
			cur_freq=1;
			cur_no=a[i];
		}
	}
	if(cur_freq>max_freq)
	{
		max_freq=cur_freq;
		max_no=cur_no;
	}
	printf("%d %d\n",max_no,max_freq);
}
return 0;
}
