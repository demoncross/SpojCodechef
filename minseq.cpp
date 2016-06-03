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

char s[100005],t[100005];

int main()
{
	int l1,l2,p1,p2,i,x,y;
	while(scanf(" %s",s)!=EOF)
	{
		scanf(" %s",t);
		l1=strlen(s);
		l2=strlen(t);
		p1=0;
		while(p1<=l1)
		{
			if(p1==l1)
			{
				printf("%s",t);
				break;
			}
			if(s[p1]<t[0])
				printf("%c",s[p1++]);
			else if(t[0]<s[p1])
			{
				printf("%s%s",t,&s[p1]);
				break;
			}
			else
			{
				x=p1+1;
				y=0+1;
				while(x<l1 && y<l2 && s[x]==t[y])	{x++;y++;}
				if(x==l1 && y==l2)
				{
					printf("%s%s",t,&s[p1]);
					break;
				}
				else if(x==l1)
				{
					while(y<l2)
					{
						if(t[y]!=t[y-1])	break;
						y++;
					}
					if(y==l2)
						printf("%s%s",t,&s[p1]);
					else if(t[y]>t[y-1])
						printf("%s%s",&s[p1],t);
					else
						printf("%s%s",t,&s[p1]);
					break;
				}
				else if(y==l2)
				{
					while(x<l1)
					{
						if(s[x]!=s[x-1])	break;
						x++;
					}
					if(x==l1)
						{printf("%s%s",t,&s[p1]);break;}	
					else if(s[x]>s[x-1])
						{printf("%s%s",t,&s[p1]);break;}
					else
					{
						char temp=s[x+1];
						s[x+1]=0;
						printf("%s",&s[p1]);
						s[x+1]=temp;
						p1=x+1;
					}
				}
				else if(s[x]<t[y])
				{
					char temp=s[x];
					s[x]=0;
					printf("%s",&s[p1]);
					s[x]=temp;
					p1=x;
				}
				else if(s[x]>t[y])
				{
					if(t[y]<t[0])	printf("%s%s",t,&s[p1]);
					else	
					{
						char temp=s[x];
						s[x]=0;
						printf("%s",&s[p1]);
						s[x]=temp;
						printf("%s%s",t,&s[x]);
					}
					break;
				}
				else
				{
					if(s[x]>s[x-1])
					{
						char temp=s[x];s[x]=0;
						printf("%s",&s[p1]);
						s[x]=temp;
						p1=x;
					}
					else
					{
						char temp=s[x+1];s[x+1]=0;
						printf("%s",&s[p1]);
						s[x+1]=temp;
						p1=x+1;	
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}