#include<stdio.h>
#include<stdlib.h>
#define MAX 50000
int count=0;
int freq[10]={0};
int a[3]={3,5,8};
int num[50]={0};
int l;
void form(int k)
{
int i,j;
for(i=0;i<3;i++)
{
	num[k]=a[i];
	freq[a[i]]++;
	if(k!=l-1)
	{
		form(k+1);
	}
	else
	{
		if(freq[8]>=freq[5] && freq[5]>=freq[3])
		{
			for(j=0;j<l;j++)	printf("%d",num[j]);
			printf("\n");
			count++;
			if(count==MAX)	exit(0);
		}
	}
	freq[a[i]]--;
}
}
int main()
{
for(l=1;;l++)
form(0);
return 0;
}
