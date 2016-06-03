#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct n
{
int x,y,i;
}node; 
node a[50009];

float dis(node x,node y)
{
	float f=sqrt(((long long int)(x.x-y.x)*(x.x-y.x))+((long long int)(x.y-y.y)*(x.y-y.y)));
	return f;
}

float abs(float x)
{
	return (x<0?:-x:x);
}

void sort(int start,int end)
{
if(start>end) return;
int i,k;
node key,j;
key=a[end];
k=start;
for(i=start;i<end;i++)
{
if(a[i].x<=key.x)
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


float work(int start,int end,int *min_a.int *min_b)
{
int min_a_1,min_a_2,min_b_1,min_b_2,mid;

if(end -start<=3)	return (brute(start,end,min_a,min_b));
mid=(start+end)>>1;
ans1=work(start,mid,&min_a_1,&min_b_1);
ans2=work(mid+1,end,&min_a_2,&min_b_2);
if(ans1<ans2)
{
	query=ans1;
	*min_a=min_a_1;
	*min_b=min_b_1;
}
else
{
	query=ans2;
	*min_a=min_a_2;
	*min_b=min_b_2;
}
node b[50000];
for(i=start,i<=end;i++)
{
	if(abs(a[i].x-a[mid].x)<=query)
	{
		b[j]=a[i];
		t=b[j].x;
		b[j].x=b[j].y;
		b[j].y=t;
		j++;
	}
}
sort(0,j-1,&b);
for(i=0;i<j;i++)
{
	t=b[i].x;
	b[i].x=b[i].y;
	b[i].y=t;
}
ans_min=query;
for(i=0;i<j;i++)
{
	for(k=i+1;k<j && abs(b[k].y-b[i].y)<=query;k++)
	{
		ass=dis(b[i],b[k]);
		if(ass<ans_min)
		{
			ans_min=ass;
			*min_a=b[i].i;
			*min_b=b[k].i;
		}
	}
}
return ans_min;
} 



int main()
{
float d_min
long long int d,d_min_x,d_min_y;
int n,i,t,x_a,x_b,y_a,y_b,min_a,min_b;
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf("%d%d",&a[i].x,&a[i].y);
	a[i].i=i;
}
sort(0,n-1);
d_min=work(0,n-1,&min_a,&min_b);



return 0;
}
