#include <cstdio>
#include <cstdlib>
#include <queue>
typedef unsigned long long int ll;
using namespace std;
struct pp
{
	int parent;
	char c;
	bool visited;
}a[20005];
ll n;
void work()
{
	ll i,j,new_r,new_q;
	ll qr;
	queue< ll > q;
	q.push(1);
	a[1].visited=true;
	a[1].parent=-1;
	a[1].c='1';
	while(!q.empty())
	{
		qr=q.front();
		q.pop();
		new_r=qr*10;
		if(new_r%n==0)
		{
			a[0].parent=qr;
			a[0].visited=1;
			a[0].c='0';
			return;
		}
		else
		{
			//i=new_r/n;
			j=(new_r)%n;
			if(!a[j].visited){
				a[j].visited=true;
				a[j].parent=qr;
				a[j].c='0';
				q.push(j);
			}
		}
		new_r+=1;
		if(new_r%n==0)
		{
			
			a[0].parent=qr;
			a[0].visited=1;
			a[0].c='1';
			return;
		}
		else
		{
			j=new_r%n;
			if(!a[j].visited){
				a[j].visited=true;
				a[j].parent=qr;
				a[j].c='1';
				q.push(j);
			}
		}
	}
}
void ou(int p)
{
	if(p==-1)	return;
	ou(a[p].parent);
	printf("%c",a[p].c);
}
int main()
{
	ll test,m;
	scanf("%lld",&test);
	while(test--)
	{
		scanf("%lld",&n);
		for(int i=0;i<=n;i++)	a[i].visited=false;
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		work();
		ou(0);
		printf("\n");
	}
	return 0;
}
