#include<stdio.h>
#include<string.h>
typedef long long int ll;
ll a[20005];
int fr[20005];

void sort(int start,int end)
{
if(start>end) return;
ll key,i,j,k;
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



ll convert(char *s,int l)
{
	ll ans=0,p;
	int i,t;
	char c;
	for(i=l-1;i>=0;i--)
	{
		c=s[i];
		switch(c)
		{
			case 'A':t=0;
				 break;
			case 'C':t=1;
				 break;
			case 'G':t=2;
				 break;
			case 'T':t=3;	
		}
		p=l-1-i;
		p=p<<1;
		ans=ans|(t<<p);
	}
	return ans;
}
int main()
{
	int n,m,i,f,j,sum;
	char s[25];
	scanf("%d %d",&n,&m);
	while(n || m)
	{
		for(i=0;i<20003;i++)	fr[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			a[i]=convert(s,m);
		}
		sort(0,n-1);
		for(i=0;i<n;i++)	
		{
			f=1;
			for(j=i+1;j<n;j++)
			{
				if(a[i]==a[j])	f++;
				else		break;
			}
			fr[f]++;
			i+=f-1;
		}
		sum=0;
		for(i=1;i<=n;i++)
			printf("%d\n",fr[i]);	
		scanf("%d%d",&n,&m);	
	}
	return 0;
}
