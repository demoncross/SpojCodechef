#define MAX 1000000002
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int x,y;
};
int main()
{
int n,i,k=0,o,p,min_x,min_y;
scanf("%d",&n);
char s[6];
struct node *a=(struct node*)malloc(n*sizeof(struct node));
for(i=0;i<n;i++)
a[i].x=a[i].y=-1;
while(n-->0)
{
	scanf(" %s %d %d",s,&o,&p);
	if(strcmp(s,"add")==0)
	{
		for(i=0;i<k;i++)
		{
			if(a[i].x==o && a[i].y==p)	break;
		}
		if(i==k)
		{
			a[i].x=o;
			a[i].y=p;
			k++;
		}	
	}
	else if(strcmp(s,"get")==0)
	{
		min_x=min_y=MAX;
		for(i=0;i<k;i++)
		{
			if(a[i].x>o && a[i].y>p && (a[i].x<min_x || (a[i].x==min_x && a[i].y<min_y)))
			{
				min_x=a[i].x;
				min_y=a[i].y;
			}
		}
		if(min_x==MAX)
			printf("-1\n");
		else
			printf("%d %d\n",min_x,min_y);
	}
	else
	{
		for(i=0;i<k;i++)
		{
			if(a[i].x==o && a[i].y==p)
			{
				a[i].x=a[i].y=-1;
				break;
			}
		}
	}
}
return 0;
}
