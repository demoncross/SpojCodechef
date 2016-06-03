//suffix array using nlogn manber and myers and lcp in n 

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

char s[100005];
int SA[100005];
int iSA[100005];
int next[100005];
int cnt[100005];
bool bh[100005],b2h[100005];
int lcp[100005];

bool cmp(int a,int b)
{
	return s[a]<s[b];
}

void work(char *s)
{
	int i,j,k,x,l,head,buckets,h;
	l=strlen(s);
	for(i=0;i<l;i++)	SA[i]=i;
	sort(SA,SA+l,cmp);
	for(i=0;i<l;i++)
	{
		bh[i]=(i==0 || s[SA[i-1]]!=s[SA[i]]);
		b2h[i]=false;
	}
	for(h=1;h<l;h<<=1)
	{
		buckets=0;
		for(i=0;i<l;i=j)
		{
			j=i+1;
			while(j<l && !bh[j])	j++;
			next[i]=j;
			buckets++;
		}
		if(buckets==l)	break;
		for(i=0;i<l;i=next[i])
		{
			cnt[i]=0;
			for(j=i;j<next[i];j++)	iSA[SA[j]]=i;
		}
		cnt[iSA[l-h]]++;
		b2h[iSA[l-h]]=true;
		for(i=0;i<l;i=next[i])
		{
			for(j=i;j<next[i];j++)
			{
				k=SA[j]-h;
				if(k>=0)
				{
					head=iSA[k];
					iSA[k]=head+cnt[head]++;
					b2h[iSA[k]]=true;
				}
			}
			for(j=i;j<next[i];j++)
			{
				k=SA[j]-h;
				if(k>=0 && b2h[iSA[k]])
				{
					for(x=iSA[k]+1; !bh[x] && b2h[x];x++)	b2h[x]=false;
				}
			}
		}
		for(i=0;i<l;i++)
		{
			SA[iSA[i]]=i;
			bh[i]|=b2h[i];
		}
	}
	for(i=0;i<l;i++)	iSA[SA[i]]=i;
	lcp[0]=0;
	h=0;
	for(i=0;i<l;i++)
	{
		if(iSA[i]>0)
		{
			j=SA[iSA[i]-1];
			while(i+h <l && j+h<l && s[i+h]==s[j+h])	h++;
			lcp[iSA[i]]=h;
			if(h>0)	h--;
		}
	}
}

int main()
{
	int test,i,l;
	ll t;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",s);
		work(s);
		l=strlen(s);
		t=0;
		for(i=0;i<l;i++)	t=t+lcp[i];
		//t=(((ll)l)*(l+1))>>1 - t;
		ll ans=(((ll)l)*(l+1))>>1;
		ans=ans-t;
		printf("%lld\n",ans);
	}
}