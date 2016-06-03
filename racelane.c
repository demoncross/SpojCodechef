#include<stdio.h>
#include<stdlib.h>
int main()
{
int test,b,i,j,s,e,l,count;
int array[10][510]={0};
scanf("%d",&test);
while(test-->0)
{
count=0;
for(i=0;i<10;i++)
{
for(j=0;j<510;j++)
	array[i][j]=0;
}
scanf(" %d",&b);
for(i=0;i<b;i++)
{
scanf(" %d %d %d",&s,&e,&l);
for(j=s;j<=e;j++)
	array[l][j]=1;
}
for(i=1;i<=500;i++)
{
if((array[0][i]==1 && array[1][i]==1)||(array[1][i]==1 && array[2][i]==1)||(array[2][i]==1 && array[3][i]==1)||(array[3][i]==1 && array[4][i]==1)||(array[4][i]==1 && array[5][i]==1)||(array[5][i]==1 && array[6][i]==1)||(array[6][i]==1 && array[7][i]==1)||(array[7][i]==1 && array[8][i]==1)||(array[8][i]==1 && array[9][i]==1))
	count++;
}
printf("%d\n",500-count);
}
return 0;
}
