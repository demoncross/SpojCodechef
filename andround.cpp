#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <utility>
#include <set>

#define MOD (1000000007)
#define MAXINT 1e9
using namespace std;
typedef long long int ll;

int tree[1<<17],a[20004];

void initialise(int node ,int left,int right)
{
	if(left==right)	{tree[node]=a[left];return;}
	initialise(node<<1,left,(right+left)/2);
	initialise((node<<1)+1,(left+right)/2+1,right);
	tree[node]=tree[node<<1]&tree[(node<<1)+1];
}

int get(int node,int n_l,int n_r,int q_l,int q_r)
{
	if(n_l>q_r || n_r<q_l)	return 0xffffffff;
	else if(n_l>=q_l && q_r>=n_r)	return tree[node];
	int ans=get(node<<1,n_l,(n_l+n_r)>>1,q_l,q_r);
	ans=ans&get((node<<1)+1,((n_l+n_r)>>1)+1,n_r,q_l,q_r);
	return ans;
}

int main()
{
	int test,n,k,i,ans,left,right;
	//printf("%u\n",0xffffffff);
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)	scanf("%d",&a[i]);
		if(k>=n/2){
		ans=a[0];
		for(i=0;i<n;i++)	ans=ans&a[i];
		for(i=0;i<n;i++)	printf("%d ",ans);
		printf("\n");}
		else
		{
			initialise(1,0,n-1);
			for(i=0;i<n;i++)
			{
				ans=a[i];
				left=i+1;
				right=i+k;
				if(left>n-1)
					ans=ans&get(1,0,n-1,left%n,right%n);
				else if(right>n-1)
					ans=ans&get(1,0,n-1,left,n-1)&get(1,0,n-1,0,right%n);
				else
					ans=ans&get(1,0,n-1,left,right);
				right=i-1;
				left=i-k;
				if(right<0)
					ans=ans&get(1,0,n-1,left+n,right+n);
				else if(left<0)
					ans=ans&get(1,0,n-1,0,right)&get(1,0,n-1,left+n,n-1);
				else
					ans=ans&get(1,0,n-1,left,right);
				printf("%d ",ans);
			}
			printf("\n");
		}
	}
	return 0;
}