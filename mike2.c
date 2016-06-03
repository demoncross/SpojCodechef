#include<stdio.h>
int a[1000006];
typedef long long ll;
void sort(int start,int end)
{
if(start>end) return;
int key,i,j,k;
key=a[end];
k=start;
for(i=start;i<end;i++)
{
if(a[i]<=key)
{
j=a[i];
a[i]=a[k];
a[k]=j;
k++;
}
}
j=a[end];
a[end]=a[k];
a[k]=j;
sort(start,k-1);
sort(k+1,end);
}
int main()
{
	ll x,half_sums,remains,q,i,n,no,fail,suc,half;
	scanf("%lld%lld",&n,&x);
	for(i=1;i<=n;i++)	
		scanf("%d",&a[i]);
	sort(0,n-1);
	half_sums=no=0;
	for(i=1;i<=n;i++)
	{
		half=(a[i]+1)>>1;
		if(half_sums+half>x)
			break;
		half_sums+=half;
		no++;
	}
	fail=n-no;
	remains=x-half_sums;
	suc=0;
	for(i=1;i<=no && remains;i++)
	{
		half=(a[i]+1)>>1;
		q=a[i]-half;
		if(q<=remains)
		{
			suc++;
			remains-=q;
		}
	}
	printf("%lld %lld\n",fail,suc);
	return 0;
}