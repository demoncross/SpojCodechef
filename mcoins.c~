#include<stdio.h>
char game[1000005];
int main()
{
int i,m,k,l,n;
scanf("%d %d %d",&k,&l,&m);
game[0]='l';
for(i=1;i<1000005;i++)
{
	game[i]='l';
	if(i-1>=0 && game[i-1]=='l')	game[i]='w';
	else if(i-k>=0 && game[i-k]=='l') game[i]='w';
	else if(i-l>=0 && game[i-l]=='l')game[i]='w';
}
//for(i=1;i<100;i++)	printf("%c ",game[i]);
for(i=0;i<m;i++)
{
	scanf(" %d",&n);
	if(game[n]=='l')	printf("B");
	else if(game[n]=='w')			printf("A");
}
printf("\n");
return 0;
}
