#include<stdio.h>
#define max 2000000
int a[max];
int d[max];
int front=0;
int rear=0;
int empty(void)
{
	return (front==rear);
}

void pop_rear(void)
{
	rear--;
}
void pop_front(void)
{
	front++;
}
void push_rear(int n)
{
	d[rear]=n;
	rear++;
}
int main()
{
int i,n,k;
scanf("%d",&n);
for(i=0;i<n;i++)	scanf("%d",&a[i]);
scanf("%d",&k);
for(i=0;i<k;i++)
{
	while(!empty() && a[d[rear-1]]<a[i])	pop_rear();
	push_rear(i);
}
printf("%d",a[d[front]]);
for(;i<n;i++)
{
	if(a[d[front]]==a[i-k])	pop_front();
	while(!empty() && a[d[rear-1]]<a[i])	pop_rear();
	push_rear(i);
	printf(" %d",a[d[front]]);
}
return 0;
}
