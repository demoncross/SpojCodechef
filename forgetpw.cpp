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
#define mod 1000000007

using namespace std;
typedef long long int ll;
int rep[150];
char s[1000006];

int main()
{
	int test,i,j,l,n;
	char x,y;
	scanf("%d",&test);
	while(test--)
	{
		for(i=0;i<=150;i++)	rep[i]=i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf(" %c %c",&x,&y);
			rep[x]=y;
		}
		//printf("%c%c",'5',rep['5']);
		scanf(" %s",s);
		l=strlen(s);
		for(i=0;i<l;i++)
			s[i]=rep[s[i]];
		int none=1;
		for(i=0;i<l;i++)
		{
			if(s[i]!='0')	break;
		}	
		if(i==l)
		{
			printf("0\n");
			continue;
		}
		for(i;i<l;i++)
		{
			if(s[i]=='.')	break;
			printf("%c",s[i]);
			none=0;
		}
		for(j=l-1;j>i;j--)
		{
			if(s[j]!='0')	break;
		}
		if(i==j)	
		{
			if(none)	printf("0");
			printf("\n");
			continue;
		}
		for(i;i<=j;i++)	printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}