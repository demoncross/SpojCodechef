#include<cstdio>
using namespace std;
int a[1000000];
int c[1000000];

int main()
{
	int cs,n,i,q,qr;
	scanf("%d",&n);
	c[0]=0;
	cs=1;
	for(i=0;i<n;i++)	
	{
		scanf("%d",&a[i]);
		if(!a[i])	c[cs++]=i+1;
	}
	c[cs++]=n+1;
	//for(i=0;i<cs;i++)	printf("%d ",c[i]);
	q=-100;
	for(i=1;i<cs;i++)
	{
		qr=c[i]-c[i-1]-1;
		if(qr>q)	q=qr;
	}
	printf("%d\n",q);
	return 0;
}