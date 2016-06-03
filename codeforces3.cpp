//http://codeforces.com/contest/288/problem/A
#include<cstdio>
using namespace std;
int main()
{
	int n,k,i,p;
	scanf("%d%d",&n,&k);
	if(n==1 && k==1)	printf("a\n");
	else if((k<2) || k>n)	printf("-1\n");
	else
	{
		for(i=0;n-i>k-2;i++)
		{
			if(i%2==0)	printf("a");
			else		printf("b");
		}
		for(p=1;i<n;i++,p++)
			printf("%c",'b'+p);
		printf("\n");
	}
	return 0;
}