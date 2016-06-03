#include<stdio.h>
#define max 40005
int x[max],y[max];
void sort(int *a,int start,int end)
{
if(start>end) return;
int key,i,j,k;
key=a[end];
k=start;
for(i=start;i<end;i++)
{
if(a[i]<=key)
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
sort(a,start,k-1);
sort(a,k+1,end);
}
int main()
{
int i,test,n,r,c,q_x,q_y,max_x,max_y;
scanf("%d",&test);
while(test--)
{
	max_x=max_y=-1;
	scanf("%d %d %d",&c,&r,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	if(n==0)
	{
		printf("%d\n",r*c);
		continue;
	}
	x[n]=c;
	y[n]=r;
	sort(x,0,n);
	sort(y,0,n);
	max_x=x[0]-1;
	max_y=y[0]-1;
	for(i=0;i<n-1;i++)
	{
		q_x=x[i+1]-x[i]-1;
		q_y=y[i+1]-y[i]-1;
		if(q_x>max_x)	max_x=q_x;
		if(q_y>max_y)	max_y=q_y;
	}
	q_x=x[i+1]-x[i];
	q_y=y[i+1]-y[i];
	if(q_x>max_x)	max_x=q_x;
	if(q_y>max_y)	max_y=q_y;
	printf("%d\n",(max_y)*(max_x));
}
return 0;
}
