#include<stdio.h>
void work(long long int n)
{
	int r;
	if(n==0)	return ;
	r=(n<0?-n%2:n%2);
	if(n<0)
		work(((-n)/2)+r);
	else
		work(-(n/2));
	printf("%d",r);
}
int main()
{
long long int n;
scanf("%lld",&n);
if(n==0)	printf("0");
else		work(n);
return 0;
}