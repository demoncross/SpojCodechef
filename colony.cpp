#include<cstdio>
using namespace std;
int f(long long int a)
{
	int c=0;
	while(a>0)
	{
		if(a&1==1)	c++;
		a>>=1;
	}
	return c;
}
int main()
{
	int y;
	long long int p;
	scanf("%d%lld",&y,&p);
	//printf("%d\n",f(p));
	if((y%2)==(f(p)%2))	printf("red");
	else			printf("blue");
	return 0;
}