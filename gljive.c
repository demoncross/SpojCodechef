#include<stdio.h>
int dif(int a,int b)
{
	int c=a-b;
	return (c<0?-c:c);
}
int a[10];
int main() {
	int  i, k, diff, res, tot;
	for(i = 0; i < 10; i++) scanf("%d", &a[i]);
	for(i = 1; i < 10; i++) a[i] += a[i-1];
	diff = 100 - a[0], res = a[0];
	for(i = 1; i < 10; i++) {
		k = dif(100 , a[i]);
		if(k < diff || (k==diff && a[i] > res)) {
			diff = k;
			res = a[i];
		}
	}
	printf("%d\n", res);
	return 0;
}
