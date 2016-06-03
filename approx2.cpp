#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
int a[1006];
pair <int,int> b[1006];
pair <int,int> answers[1006];

int b_search(int s,int e,int q)
{
	int ans=s,m;
	while(s<=e)
	{
		m=(s+e)>>1;
		if(b[m].first==q)	return m;
		if(q>b[m].first)
			s=m+1;
		else
			e=m-1;
		if(abs(b[m].first-q)<abs(b[ans].first-q))
			ans=m;
	}
	return ans;
}

int main()
{
	int test,n,k,i,j,l,q,f;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		j=0;
		for(i=0;i<n;i++)
		{
			b[j].first=a[i];
			b[j].second=1;
			for(l=i+1;l<n;l++)
			{
				if(a[l]!=a[l-1])	break;
				b[j].second++;
			}
			i=l-1;
			//printf("%d %d\n",b[j].first,b[j].second);
			j++;
		}
		for(i=0;i<j-1;i++)
		{
			int one=b[i].first;
			q=-(one-k);
			f=b_search(i+1,j-1,q);
			answers[i].first=abs(b[f].first+b[i].first-k);
			answers[i].second=b[i].second*b[f].second;
			if(b[i].second>1)
			{
				int query=abs(2*b[i].first-k);
				if(query<answers[i].first)
					answers[i].second=(b[i].second*(b[i].second-1))>>1;
				if(query==answers[i].first)
					answers[i].second+=(b[i].second*(b[i].second-1))>>1;
			}
			//printf("%d ",f);
			//printf("%d %d\n",answers[i].first,answers[i].second);
		}
			answers[i].first=abs(2*b[i].first-k);
			answers[i].second=(b[i].second*(b[i].second-1))>>1;
		sort(answers,answers+j);
		int pp=0;
		l=0;
		if(answers[0].second==0)	l=1;
		//printf("%d %d %d\n",answers[0].first,answers[0].second,b[0].second);
		for(i=l;i<j;i++)
		{
			if(answers[i].first!=answers[l].first)	break;
			pp+=answers[i].second;
		}
		printf("%d %d\n",answers[l].first,pp);
	}
	return 0;
}