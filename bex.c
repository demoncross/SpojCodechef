#include<stdio.h>
#include<string.h>
struct node
{
int n;
char name[20];
};
struct node stack[1000005];
int tos=0;
int stack_min[1000005];
int tos_min=0;
void push(struct node a)
{
stack[tos]=a;
tos++;
}
struct node pop()
{
tos--;
return stack[tos];
}
void push_min(int m)
{
if(m>100000)	return;
stack_min[tos_min]=m;
tos_min++;
}
int pop_min()
{
if(tos_min==0)	return 100000;
tos_min--;
return stack_min[tos_min];
}
int main()
{
int tes,test,sample=0,count;
struct node a;
scanf("%d",&tes);
test=tes;
while(test-->0)
{
count=0;
scanf(" %d",&a.n);
if(a.n!=-1)
{
scanf(" %s",&a.name);
push(a);
sample=pop_min();
push_min(sample);
if(sample>=a.n)
push_min(a.n);
}
else
{
a=pop();
sample=pop_min();
while(a.n!=sample)
{
count++;
a=pop();
//push_min(sample);
}
//push(sample);
printf("%d %s\n",count,a.name);
}
}
return 0;
}