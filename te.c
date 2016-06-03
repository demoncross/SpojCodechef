#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MOD 1000000007
#define MAX 100001
using namespace std;
vector <int> G[MAX];
bool visited[MAX];

int modulo(int a,int b,int c){
    // res is kept as long long because intermediate results might overflow in "int"
    long long res = 1; 
    for(int i=0;i<b;i++){
        res *= a;
        res %= c; // this step is valid because (a*b)%c = ((a%c)*(b%c))%c
    }
    return res%c;
}

int dfs(int i){ 
	int bnt=1;
	visited[i]=true;
	
	for(int j=0;j<G[i].size();j++){
		if(!visited[G[i][j]])
			bnt+=dfs(G[i][j]);
	}
	return bnt;	
}


int main() { 
	int t,n,m;
    scanf("%d",&t);
	while(t--) {
		for(int i=0;i<MAX;i++)
			G[i].clear();
		memset(visited,0,sizeof(visited));
		scanf("%d%d",&n,&m);
		int a,b;
		for(int i=0;i<m;i++){ 
			scanf("%d%d",&a,&b);
		    G[a].push_back(b);
			G[b].push_back(a);
		
		}
		int cnt=0;
		int compcnt[MAX];
		memset(compcnt,0,sizeof(compcnt));
		for(int i=1;i<=n;i++){
			if(!visited[i])
			compcnt[cnt++]=dfs(i);
		}
		long long mul=1;
	    for(int i=0;i<cnt;i++){
			mul=((mul%MOD)*(compcnt[i]%MOD))%MOD;
		}
		int miko=modulo(n,cnt-2,MOD);
		mul=((mul%MOD)*(miko%MOD))%MOD;
	
	  if(cnt==1)
		 printf("-1\n");
	 else
     printf("%lld\n",mul);		

	}
	return 0;
}