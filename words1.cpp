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

using namespace std;
typedef long long int ll;

char s[10000];
int in[40],out[40];
int ma[30][30];
int visited[30];

void search(int x)
{
	int i,qr;
	visited[x]=1;
	queue<int> q;
	q.push(x);
	while(!q.empty())
	{
		qr=q.front();
		q.pop();
		for(i=0;i<30;i++)
		{
			if(ma[qr][i] && !visited[i])
			{
				visited[i]=1;
				q.push(i);
			}
		}
	}
}

int main()
{
	int test,n,i,start,end,l,c,j;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for(i=0;i<30;i++)	for(j=0;j<30;j++)	ma[i][j]=0;
		for(i=0;i<30;i++)	visited[i]=in[i]=out[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			l=strlen(s);
			out[s[0]-'a']++;
			in[s[l-1]-'a']++;
			ma[s[0]-'a'][s[l-1]-'a']=ma[s[l-1]-'a'][s[0]-'a']=1;
			c=s[0]-'a';
		}
		search(c);
		end=start=0;
		for(i=0;i<30;i++)
		{
			if(in[i]==out[i])	continue;
			if(in[i]-out[i]==1)
			{
				if(!end)	end=1;
				else		break;
			}
			else if(in[i]-out[i]==-1)
			{
				if(!start)	start=1;
				else		break;
			}
			else		break;
		}
		if(i==30 && start==end)
		{
			for(i=0;i<30;i++)
				if((in[i]||out[i])&&!visited[i])	break;
			if(i==30)
				printf("Ordering is possible.\n");
			else	printf("The door cannot be opened.\n");
		}
		else	printf("The door cannot be opened.\n");
	}
	return 0;
}