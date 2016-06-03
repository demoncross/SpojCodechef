#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>

using namespace std;
typedef long long int ll;

typedef struct nnode
{
	int data;
	nnode *one,*zero;
}node;
int a[1000000];

void insert(node *root,int x,int level)
{
	while(level>=0)
	{
		int t=x&(1<<level);
		if(t)
		{
			if( root->one)	root=root->one;
			else
			{
				root->one=(node *)malloc(sizeof(node));
				root->one->data=1;
				root->one->one=root->one->zero=NULL;
				root=root->one;
			}
		}
		else
		{
			if( root->zero)	root=root->zero;
			else
			{
				root->zero=(node *)malloc(sizeof(node));
				root->zero->data=0;
				root->zero->one=root->zero->zero=NULL;
				root=root->zero;
			}	
		}
		level--;
	}
}

int main()
{
	int n,ma,i,level,one_waala,zero_waala,l;
	node *test,*root;
	scanf("%d",&n);
	ma=0;
	a[0]=0;
	for(i=1;i<=n;i++)	
	{
		scanf("%d",&a[i]);
		if(a[i]>ma)	ma=a[i];
	}
	level=log2(ma);
	//printf("%d",level);
	root=(node *)malloc(sizeof(node));
	root->data=0;
	root->one=root->zero=NULL;
	for(i=1;i<=n;i++)
		insert(root,a[i],level);
	//insert(root,6,2);
	//printf("oo");
	test=root;
	level++;
	l=level;
	zero_waala=one_waala=0;
	//printf("%d\n",level);
	while(level>=0)
	{
		zero_waala+=((test->data)<<level);
		//printf("%d\n",test->data);
		if(test->zero)	test=test->zero;
		else if(test->one)			test=test->one;
		level--;
		//printf("%d\n",zero_waala);
	}
	//printf("%d\n",zero_waala);
	level=l;
	test=root;
	while(level>=0)
	{
		one_waala+=((test->data)<<level);
		if(test->one)	test=test->one;
		else if(test->zero)			test=test->zero;
		level--;
	}
	//printf("%d\n",one_waala);
	printf("%d\n",one_waala^zero_waala);
	return 0;
}