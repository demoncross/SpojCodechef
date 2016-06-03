#include<stdio.h>
int main()
{
int n,t,row,off;
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
if(n==1){
printf("poor conductor\n");
continue;}
row=(n+3)/5;
off=(n+3)%5;
printf("%d ",row);
if(row&1)
{
if(off==0)	printf("W L\n");
else if(off==1)	printf("A L\n");
else if(off==2)	printf("A R\n");
else if(off==3) printf("M R\n");
else		printf("W R\n");
}
else
{
if(off==0)	printf("W R\n");
else if(off==1)	printf("M R\n");
else if(off==2)	printf("A R\n");
else if(off==3) printf("A L\n");
else		printf("W L\n");
}
}
return 0;
}
