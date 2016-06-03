#include<stdio.h>
int l(int a)
{
	int i=1,p=0;
	
	while(1)
	{
		if(i>=a)	break;
		p++;
		i=1<<p;	
	}	
	return p;
}
int in_range(int a,int b)
{
	if(a>b)	return 0;
	else if(a==b)	return 1;
	else if(in_range(a<<1,b) || in_range((a<<1)+1,b))
		return 1;
	else
		return 0;
}
float calculate(int x,int y,int w)
{
	int s;
	if(x==y)	return w;
	s=y/2;
	float q;
	q=calculate(x,s,w);
	if(s%2)
		q= q/4;
	else
		q= q/2;
	if(y%2==0)
		q=q*2;
	return q;
}
int main()
{
int t,x,y;
float w;
scanf("%d",&t);
while(t--)
{
	scanf("%d%d%f",&x,&y,&w);
	while(!in_range(x,y))
	{
		if(x%2)
			w/=2;
		w*=2;
		x/=2;
		if(x%2==0)
			w*=2;
	}
	printf("%f\n",calculate(x,y,w));	
}
return 0;
}
