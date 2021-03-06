#include<stdio.h>
struct node
{
int bottom,left,right,top;
};
struct node data[506][506];



char map[502][502];
int r,c;
int sieve[262];
int a[262];
void create_sieve()
{
int i,j,n=260;
for(i=0;i<=n;i++)	
	a[i]=0;	//initialising array initially all are 0----representing prime
for(i=2;i*i<=n;i++)
{
	for(j=i;j*i<=n;j++)
		a[i*j]=-1;//-1 represents non prime
}
sieve[0]=sieve[1]=0;
sieve[2]=1;
for(i=3;i<260;i++)
sieve[i]=sieve[i-1]+(a[i]==0?1:0);
}

/*

int top(int i,int j)
{
int a,ans=0;
for(a=i-1;a>=0;a--)
{
if(map[a][j]=='^') ans++;
else	break;
}
return ans;
}

int bottom(int i,int j)
{
int a,ans=0;
for(a=i+1;a<r;a++)
{
if(map[a][j]=='^') ans++;
else	break;
}
return ans;
}

int left(int i,int j)
{
int a,ans=0;
for(a=j-1;a>=0;a--)
{
if(map[i][a]=='^') ans++;
else	break;
}
return ans;
}

int right(int i,int j)
{
int a,ans=0;
for(a=j+1;a<c;a++)
{
if(map[i][a]=='^') ans++;
else	break;
}
return ans;
}
*/
int min(int a,int b,int c,int d)
{
if(a<=b &&a<=c &&a<=d)	return a;
else if(b<=a &&b<=c &&b<=d)	return b;
else if(c<=a &&c<=b &&c<=d)	return c;
else	return d;
}

int main()
{
create_sieve();
int test,i,j,m,count;
char ch;
scanf("%d",&test);
while(test-->0)
{
count=0;
scanf(" %d %d",&r,&c);
for(i=0;i<r;i++)
{
scanf(" %s",map[i]);
}

for(i=0;i<c;i++)
{
data[0][i].top=0;
for(j=1;j<r;j++)
	data[j][i].top=map[j][i]=='^'?(data[j-1][i].top+(map[j-1][i]=='^'?1:0)):0;
}

for(i=0;i<c;i++)
{
data[r-1][i].bottom=0;
for(j=r-2;j>=0;j--)
	data[j][i].bottom=map[j][i]=='^'?(data[j+1][i].bottom+(map[j+1][i]=='^'?1:0)):0;
}

for(i=0;i<r;i++)
{
data[i][0].left=0;
for(j=1;j<c;j++)
	data[i][j].left=map[i][j]=='^'?(data[i][j-1].left+(map[i][j-1]=='^'?1:0)):0;
}


for(i=0;i<r;i++)
{
data[i][c-1].right=0;
for(j=c-2;j>=0;j--)
	data[i][j].right=map[i][j]=='^'?(data[i][j+1].right+(map[i][j+1]=='^'?1:0)):0;
}


for(i=2;i<r-2;i++)
{
for(j=2;j<c-2;j++)
{
if(map[i][j]=='^')
{	
m=min(data[i][j].left,data[i][j].right,data[i][j].top,data[i][j].bottom);
count+=sieve[m];
}
}
}/*
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
	printf("%d %d %d %d\n",data[i][j].top,data[i][j].right,data[i][j].bottom,data[i][j].left);
}*/
printf("%d\n",count);
}
return 0;
}
