#include<stdio.h>
int main()
{
long int i=1;
//scanf("%ld",&i);
i=i<<27;
printf("%ld\n",i);
i=i%100000007;
printf("\n%ld\n",i);
return 0;
}
