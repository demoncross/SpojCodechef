#include<stdio.h>
#define n 100
int a[n]={0};
int num;
int ans=0;
int qabs(int a,int b)
{
if(a<0) a=0-a;
if(b<0) b=0-b;
return (b==a);
}
int findcand(int k,int *c)
{
int i,j,b,d;
b=0;
for(i=0;i<num;i++)
{d=1;
for(j=0;j<k;j++)
{
if(qabs(k-j,a[j]-i)||i==a[j])
{
d=0;
break;
}
}
if(d)
{
c[b]=i;
b++;
}
}
return b;
}
void backtrack(int k)
{
int cnum,i;
int c[n];
if(k==num)
{
ans++;
}
else
{
cnum=findcand(k,c);

for(i=0;i<cnum;i++)
{
a[k]=c[i];
backtrack(k+1);
}
}
}
int main()
{
printf("\nenter the dimension of the board:\n");
scanf(" %d",&num);
backtrack(0);
printf("\n%d\n",ans);
return 0;
}
