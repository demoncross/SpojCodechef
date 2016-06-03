#include<stdio.h>
#define dummy (sizeof(temp) / sizeof(2[temp]))
int temp[] = {1,2,3,4};
int main()
{
int d;
if(-1>(dummy-2))	printf("YO!\n");
printf("%d\n",temp[dummy-2]);
for(d=0;d <= (dummy-2);d++)
{
printf("%d\n",temp[d+1]);
}
return 0;
}