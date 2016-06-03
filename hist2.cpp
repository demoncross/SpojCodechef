#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef struct p
{
	int first,second;
}pp;
int ht[20];
pp dp[20][1<<17];
pp work(int t,int f)
{
	int i,left;
	pp q,max_found;
	max_found.first=-1;
	max_found.second=0;
	if(dp[f][t].first!=-1)	return dp[f][t];
	left=t^(1<<f);
	if(left==0){
		dp[f][t].first=2+2*ht[f];
		dp[f][t].second=1;
		return dp[f][t];}
	for(i=0;i<16;i++)
	{
		if(left&(1<<i))
		{
			q=work(left,i);
			q.first+=2+ht[f]-ht[i]+abs(ht[f]-ht[i]);
			if(q.first>max_found.first)
				max_found=q;
			else if(q.first==max_found.first)
				max_found.second+=q.second;
		}
	}
	return (dp[f][t]=max_found);
}
int main()
{
	pp max_found,q;
	int test,n,i,j;
		scanf("%d",&n);
		while(n){
		for(i=0;i<16;i++)
			for(j=0;j<1<<16;j++)	dp[i][j].first=dp[i][j].second=-1;
		for(i=0;i<n;i++)	scanf("%d",&ht[i]);
		max_found.first=-1;
		for(i=0;i<n;i++)
		{
			q=work((1<<n)-1,i);
			if(q.first>max_found.first)	max_found=q;
			else if(q.first==max_found.first)	max_found.second+=q.second;
		}	
		printf("%d %d\n",max_found.first,max_found.second);
		scanf("%d",&n);}
	return 0;
}