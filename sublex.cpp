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
int a[100005];

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

int ff(int s,int e,int q)
{
	int ans,mid;
	ans=e;
	while(s<=e)
	{
		mid=(s+e)>>1;
		if(a[mid]>=q)	ans=mid;
		if(a[mid]<q)	s=mid+1;
		else			e=mid-1;
	}
	return ans;
}

int main()
{
	int q,k,i,l,f;
	scanf(" %s",s);
	work(s);
	l=strlen(s);
	a[0]=l-SA[0];
	for(i=1;i<l;i++)
		a[i]=a[i-1]+l-SA[i]-lcp[i];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&k);
		f=ff(0,l-1,k);
		if(f!=0)	k=k-a[f-1];
		for(i=0;i<k+lcp[f];i++)	printf("%c",s[SA[f]+i]);
		printf("\n");
	}
	return 0;
}