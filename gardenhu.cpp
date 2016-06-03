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

using namespace std;
typedef long long int ll;

vector<pii> list;
vector<pair<int,int> > a;
pair<int,int> vertex;
stack<pair<int,int> > s;

bool cmp (pair<int,int> a,pair<int,int> b)
{
	int d1,d2,q;
	if(a==vertex)	return 1;
	if(b==vertex)	return 0;
	q=(a.first-vertex.first)*(b.second-vertex.second)-(a.second-vertex.second)*(b.first-vertex.first);
	if(q>0)	return 1;
	if(q<0)	return 0;
	d1=(a.first-vertex.first)*(a.first-vertex.first)+(a.second-vertex.second)*(a.second-vertex.second);
	d2=(b.first-vertex.first)*(b.first-vertex.first)+(b.second-vertex.second)*(b.second-vertex.second);
	return (d1<d2);
}

float distanc(pair<int,int> a,pair<int,int> b)
{
	float d=(a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
	d=sqrt(d);
	return d;
}

int main()
{
	int i,n,x,y,q=-1;
	pair<int,int> w,e;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		list.push_back(make_pair(x,y));
		if(q==-1 || list[q].second>y || (list[q].second==y && list[q].first<x))
			q=i;
	}
	vertex=list[q];
	sort(list.begin(),list.end(),cmp);
	s.push(list[0]);
	s.push(list[1]);
	i=2;
	while(i<n)
	{
		if(s.size()==1)	{s.push(list[i]);i++;}
		else
		{
			w=s.top();
			s.pop();
			e=s.top();
			s.pop();
			s.push(e);
			s.push(w);
			q=(list[i].first-w.first)*(e.second-w.second)-(list[i].second-w.second)*(e.first-w.first);
			if(q>0)
			{
				s.push(list[i]);
				i++;
			}
			else
				s.pop();
		}
	}
	while(!s.empty())
	{
		a.push_back(s.top());
		s.pop();
	}
	x=(int)a.size();
	float ans=distanc(a[0],a[x-1]);
	for(i=1;i<a.size();i++)
		ans+=distanc(a[i],a[i-1]);
	int aa=ans;
	cout<<aa<<endl;
	return 0;
}