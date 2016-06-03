#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

struct p
{
	int t,req,gain;
}a[105];

bool cmpr(struct p& a,struct p& b)
{
	if(a.t<b.t)	return true;
	else if(a.t>b.t)	return false;
	if(a.req<b.req)		return true;
	else if(a.req>b.req)	return false;
	else if(a.gain>b.gain)	return  true;
	else					return false;
}

struct qr
{
	int req,gain;
}list[105];
using namespace std;

int main()
{
	int n,t,x,i,j,till,m,minus,q;
	scanf("%d%d%d",&n,&t,&x);
	for(i=0;i<n;i++)
		scanf("%d%d%d",&a[i].req,&a[i].t,&a[i].gain);
	sort(a,a+n,cmpr);
	till=0;
	for(i=0;i<n;i++)
	{ 
		if(a[i].t+till<=t)	till+=a[i].t;
		else					break;
	}
	printf("%d ",i);
	for(j=0;j<i;j++)
	{
		list[j].req=a[j].req;
		list[j].gain=a[j].gain;
	}
	sort(list,list+i);
	minus=0;
	m=-1;
	for(j=0;j<i;j++)
	{
		q=list[j].req-minus;
		if(q>m)	m=q;
		minus+=list[j].gain
	}
	printf("%d\n",m);
	return 0;
}