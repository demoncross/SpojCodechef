#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<stdio.h>
#include<math.h>
#include<string>
#include<cstring>
using namespace std;
int dp[22][1001];
int ans[22][1001];
int cost[22][22];
int reward[22][22];
int arr[22];
int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--){
		int n,m,k,temp;
		scanf("%d%d%d",&n,&m,&k);
		memset(dp,0,sizeof(dp));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&cost[i][j]);
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&reward[i][j]);
			}
		}
	
		for(int weight=0;weight<=k;weight++){
			
			for(int i=1;i<=n;i++){
			  int temp=weight;
				if(arr[i]<=temp){
					temp-=arr[i];
				      for(int j=1;j<=m;j++){
						if(temp>=cost[i][j])
							dp[i][weight]=(max(dp[i][weight],dp[i][weight-cost[i][j]]+reward[i][j]));
						  if(temp>=cost[i][j])	
						  dp[i][weight]=max(dp[i][weight],ans[i-1][temp-cost[i][j]]+reward[i][j]);
						
					  }
					
				}
				for(int par=0;par<=k;par++)
					ans[i][par]=max(dp[i][par],ans[i-1][par]);
			//  cout <<i<<" "<<weight<<" "<<dp[i][weight]<<endl;	
			}
			
		 }
	
	
		printf("%d\n",ans[n][k]);
		
		
		}
	
	return 0;	
}