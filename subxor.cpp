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
#define EPS (1e-9)
#define mp   make_pair
#define pb   push_back
#define pii  pair<int,int> 
#define se   second
#define fi   first
#define ll long long int

using namespace std;

int a[1000006];

typedef struct trie_node
{
	int l,r;
	struct trie_node * next[2];
}TN;

typedef struct trie
{
	int c;
	TN* root;
}T;

T t;


TN* getnode(void)
{
	TN *x=(TN*)malloc(sizeof(TN));
	x->l=x->r=0;
	x->next[0]=x->next[1]=NULL;
	return x;
}

void init(void)
{
	t.root=getnode();
	t.c=0;
}

void insert(int x,int l)
{
	int q;
	t.c++;
	TN *cr=t.root;
	while(l>=0)
	{
		q=(x&(1<<l));
		q=(q==0?0:1);
		if(cr->next[q] == NULL)
			cr->next[q]=getnode();
		if(q)	cr->r++;
		else	cr->l++;
		cr=cr->next[q];
		l--;
	}
}

ll work(int x,int l,int k)
{
	ll ans=0;
	int i,j;
	TN *cr=t.root,*z;
	while(l>=0 && cr)
	{
		i=(k&(1<<l));
		i=(i==0?0:1);
		j=(x&(1<<l));
		j=(j==0?0:1);
		if(i==0)
		{
			cr=cr->next[j];
		}
		else
		{
			if(j==1)
			{
				ans+=cr->r;
				cr=cr->next[0];
			}
			else
			{
				ans+=cr->l;
				cr=cr->next[1];
			}
		}
		l--;
	}
	return ans;
}

void delet(TN *x)
{
	if(x==NULL)	return;
	delet(x->next[0]);
	delet(x->next[1]);
	free(x);
}

int main()
{
	int test,i,l,n,maxx,ans,q,k;
	scanf("%d",&test);
	init();
	while(test--)
	{
		delet(t.root);
		init();
		scanf("%d%d",&n,&k);
		a[0]=0;
		maxx=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=a[i-1]^a[i];
			maxx=max(maxx,a[i]);
		}
		l=log2(maxx);
		l=21;
		for(i=0;i<=n;i++)	insert(a[i],l);
		ll ans=0;
		for(i=0;i<=n;i++)
		{
			ll q=work(a[i],l,k);
			ans+=q;
		}
		ans=ans-n-1;
		ans=ans/2;
		printf("%lld\n",ans);
	}
	return 0;
}
