#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
typedef long long int ll;
pair<int,int> a[1000006];
char s[1000006];

int main()
{
	int l,as,bs,cs,i,j;
	ll ans,f;
	scanf("%s",s);
	l=strlen(s);
	a[0]=make_pair(0,0);
	as=bs=cs=0;
	for(i=0;i<l;i++)
	{
		if(s[i]=='A')	as++;
		else if(s[i]=='B') bs++;
		else			cs++;
		a[i+1]=make_pair(-as+bs,-as+cs);
	}
	ans=0;
	sort(a,a+l+1);
	//for(i=0;i<l+1;i++)	printf("%d %d\n",a[i].first,a[i].second);
	for(i=0;i<l+1;i++)
	{
		for(j=i+1;j<l+1;j++)
		{
			if(a[i].first!=a[j].first || a[i].second!=a[j].second) break;
		}
		f=j-i;
		//printf("%d\n",f);
		ans+=(f*(f-1))>>1;
		i=j-1;
	}
	printf("%lld\n",ans);
	return 0;
}