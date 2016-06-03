#include<stdio.h>
int five[12],ten[12];
int check(int n)
{
	int s=1;
	while(n>0)
	{
		s=s*(n%10);
		n=n/10;
	}	
	return (s%2?0:1);
}
int work(int n,int d)
{
int l,a,b;
if(n==0)	return 0;
else if(d==1)	return (n+1)/2;
l=n/ten[d-1];
a=five[d-1]*(l/2);
b=work(n%ten[d-1],d-1);
return (a+((l%2)?b:0));
}


int no_of_dig(int m)
{
int d=0;
while(m>0)
{
	d++;
	m/=10;
}
return d;
}
int main()
{
int t,n,d_n,s,i,o,m,d_m,ans,odd,x,y,z;
scanf("%d",&t);
five[0]=1;
ten[0]=1;
for(i=1;i<=10;i++)
	five[i]=five[i-1]*5;
for(i=1;i<=10;i++)
	ten[i]=ten[i-1]*10;
while(t--)
{
	ans=0;
	scanf("%d %d",&n,&m);
	d_n=no_of_dig(n);
	d_m=no_of_dig(m);
	o=work(n,d_n);
	s=work(m,d_m);	
	if(d_m==d_n)
	{
		odd=s-o;
		ans=m-n+1-odd;
		ans-=(check(n)?0:1);
		//check L	
	}
	else
	{
		ans=0;
		for(i=d_n+1;i<d_m;i++)	ans+=(ten[i]-ten[i-1]-five[i]);	
		y=five[d_n];
		z=y-o;
		ans-=(check(n)?0:1);
		//check L
		ans+=ten[d_n]-n-z;
		ans+=m-ten[d_m-1]+1-s;
	}
	printf("%d\n",ans);
}
return 0;
}
