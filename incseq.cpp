#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#define mod 5000000

using namespace std;
typedef long long int ll;
int a[10004];
int tree[51][100005];
int store[51];
int c=0;

void init(void)
{
	int i,j;
	for(i=0;i<=(100005);i++){
		for(j=1;j<=50;j++)
			tree[j][i]=0;
		tree[0][i]=1;
	}
	return;
}

int query(int index,int i)
{
	int ans=0;
	if(index==0)	return 1;
	if(i==0 && index==1)	return c;
	while(i>0)
	{
		//		printf("%d\n",i);

		ans=(ans+tree[index][i])%mod;
		i=i-(i&-i);
	}
	if(index==1)	ans=(ans+c)%mod;
	return ans;
}

void update(int index,int i,int m)
{
	if(i==0)	{c++;return;}
	while(i<=100000)
	{
		//printf("%d\n",i);
		tree[index][i]=(tree[index][i]+m)%mod;
		i=i+(i&-i);
	}
}

int main()
{
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	init();
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		if(a[i]==0){
			c++;
			continue;}
		for(j=1;j<=k;j++)
			store[j]=query(j-1,a[i]-1);
		for(j=1;j<=k;j++)
			update(j,a[i],store[j]);
	}
	//update(k,50,1000);
	printf("%d\n",query(k,100000));
	return 0;
}