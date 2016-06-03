#include<stdio.h>
#define max 10000005
int flag[max];
long long int fun[max];

void make(void)
{
int i,j;
for(i=0;i<max;i++)	flag[i]=i;
flag[2]=2;
flag[3]=3;
for(i=2;(i-1)*(i-1)<=max;i++)
{
	if(flag[i]==i)
	{
		for(j=i;j*i<=max;j++)
		{
			if(flag[j*i]==j*i)
			flag[j*i]=i;
		}
	}
}
}
void func(void)
{
int i;
fun[0]=fun[1]=0;
for(i=2;i<max;i++)
	fun[i]=fun[i-1]+flag[i];
}
int main()
{
make();
func();
int n,test;
scanf("%d",&test);
while(test--){
scanf("%d",&n);
printf("%lld\n",fun[n]);
}
return 0;
}
