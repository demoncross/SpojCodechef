# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <queue>
# include <cmath>
# include <cstring>
# include <iostream>
# include <stack>
# include <map>
# include <vector>
# include <utility>
# include <set>
# include <deque>

# define MOD (1000000007)
# define MAXINT 1e9

using namespace std;
typedef long long int ll;

int gcd(int a,int b)
{
	if(b==0)	return a;
	return gcd(b,a%b);
}

int main()
{
	int test,ans,x,n,i;
	cin>>test;
	while(test--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(i!=0)	ans=((ans>x)?gcd(ans,x):gcd(x,ans));
			else		ans=x;
		}
		if(ans==1)	cout<<n<<endl;
		else		cout<<-1<<endl;
	}
	return 0;
}