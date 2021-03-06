#include<stdlib.h>
#include<stdio.h>
#define MAX 1000000000
struct node
{
int x,ht,num;
};
void merge(struct node *a,int i,int j)
{
struct node c[1000],d[1000];
int mid=(i+j)/2;
int k,h=0,g=0;
for(k=0;k<=mid-i;k++)
c[k]=a[i+k];
c[k].x=MAX;
for(k=0;k<j-mid;k++)
d[k]=a[mid+1+k];
d[k].x=MAX;
for(k=i;k<=j;k++)
{
if(c[g].x<d[h].x)
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

void sort(struct node *a,int start,int end)
{
if(start==end)
return;
sort(a,start,(start+end)/2);
sort(a,(start+end)/2+1,end);
merge(a,start,end);
}
int main()
{
int i,j,n,test,count,range;
scanf("%d",&test);
while(test-->0)
{
scanf(" %d",&n);
int *ans=(int *)malloc(n*sizeof(int));
struct node *a=(struct node *)malloc(n*sizeof(struct node));
for(i=0;i<n;i++)
{
	scanf(" %d %d",&a[i].x,&a[i].ht);
	a[i].num=i;
}
sort(a,0,n-1);
//printf("as");
for(i=0;i<n;i++)
{
range=a[i].ht;
count=1;
for(j=i+1;j<n;j++)
{
if(range>(a[j].x-a[j-1].x))
	count++;
else
	break;
range=range-(a[j].x-a[j-1].x);
if(range<a[j].ht)
	range=a[j].ht;
}
ans[a[i].num]=count;
}
for(i=0;i<n;i++)
	printf("%d ",ans[i]);
printf("\n");
free(a);
free(ans);
}
return 0;
}
