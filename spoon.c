#include<stdio.h>
#include<string.h>
char map[101][101];
int check_h(int i,int j)
{
if((map[i][j+1]=='p' ||map[i][j+1]=='P')&& (map[i][j+2]=='o' ||map[i][j+2]=='O')  && (map[i][j+3]=='o' ||map[i][j+3]=='O') && (map[i][j+4]=='n'||map[i][j+4]=='N'))
	{return 1;}
else
	{return 0;}
}
int check_v(int i,int j)
{
if((map[i+1][j]=='p'||map[i+1][j]=='P' )&& (map[i+2][j]=='o'||map[i+2][j]=='O'  )&& (map[i+3][j]=='o' ||map[i+3][j]=='O')&& (map[i+4][j]=='n'||map[i+4][j]=='N'))
	{return 1;}
else
	{return 0;}
}
int main()
{
int test,i,j,r,c;
scanf("%d",&test);
while(test-->0)
{
	scanf(" %d %d",&r,&c);
	for(i=0;i<r;i++)
		scanf(" %s",map[i]);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(map[i][j]=='S' || map[i][j]=='s')
			{
				if(j<c-4)
				{
					if(check_h(i,j))
					{
						printf("There is a spoon!\n");
						break;
					}
				}
				if(i<r-4)
				{
					if(check_v(i,j))
					{
						printf("There is a spoon!\n");
						break;
					}
				}
			}
		}
		if(j!=c)	break;
	}
	if(i==r && j==c)
		printf("There is indeed no spoon!\n");
}
return 0;
}
