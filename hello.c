#include<stdio.h>
int main()
{
int test,u,f,m,c,mina,i;
float min,q,d,r;
scanf("%d",&test);
while(test-->0)
{
scanf("%f %d %d",&d,&u,&f);
min=d*u;
mina=0;
for(i=0;i<f;i++)
{
scanf("%d %f %d",&m,&r,&c);
q=(r*u)+((float)c/m);
if(q<min){
min=q;
mina=i+1;
}
}
printf("%d\n",mina);
}
return 0;
}
