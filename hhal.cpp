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

char s[1000006];

int main()
{
	int test,i,f,l;
	cin>>test;
	while(test--)
	{
		cin>>s;
		l=strlen(s);
		f=0;
		for(i=0;i<l/2;i++)
		{
			if(s[i]!=s[l-i-1])	f=1;
		}
		if(f)	printf("2\n");
		else	printf("1\n");
	}
	return 0;
}