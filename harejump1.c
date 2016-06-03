#include<stdio.h>
#define ll unsigned long long
#define MOD 1000000007
 
void mul(int sz, ll (*A)[sz], ll (*B)[sz]) {
	int i,j,k;
	ll res[sz][sz];
	for(i=0; i<sz; i++) for(j=0; j<sz; j++) res[i][j]=0;
 
	for(i=0; i<sz; i++) {
		for(j=0; j<sz; j++) {
			for(k=0; k<sz; k++) res[i][j]+=(A[i][k]*B[k][j]);
			res[i][j]%=MOD;
		}
	}
 
	for(i=0; i<sz; i++) {
		for(j=0; j<sz; j++) {
			A[i][j]=res[i][j];
		}
	}
}
 
void pow1(ll exp, int sz, ll (*M)[sz]) {
	ll res[sz][sz];
	int i,j;
	for(i=0; i<sz; i++) {
		for(j=0; j<sz; j++) res[i][j]=0;
		res[i][i]=1;
	}
 
	while(exp>0) {
		if(exp%2==1) {
			mul(sz,res,M);
		}
		mul(sz,M,M);
		exp/=2;
	}
	for(i=0; i<sz; i++) {
		for(j=0; j<sz; j++) {
			M[i][j]=res[i][j];
		}
	}
}
 
int main() {
	ll N;
	int t,k,i;
	scanf("%d\n",&t);
	i=0;
	while (i<t) {
		scanf("%llu\n",&N);
		scanf("%d ",&k);
		int j, A[16], V[16], tmp, max, x, y, c1;
 
		for(j=0; j<16; j++) {
			A[j]=0;
			V[j]=0;
		}
		tmp=max=j=0;
		while (j<k) {
			scanf("%d",&tmp);
			A[tmp]=1;
			V[tmp]=1;
			if(tmp>max) max=tmp;
			j++;
		}
		
		ll M[max][max];
		for(x=0; x<max-1; x++) {
			for(y=0; y<max; y++) M[x][y]=0;
			M[x][x+1]=1;
		}
		
		for(x=1;x<=max;x++) {
			if(A[x]) M[max-1][max-x]=1;
			else M[max-1][max-x]=0;
		}
		
		for(x=1;x<16;x++) {
			for(y=1;y<x;y++) {
				if(A[y]) V[x]+=V[x-y];
			}
		}
 
		if(N>max) {
			pow1(N-max,max,M);
			ll r1=0;
			
			for(y=0; y<max; y++) {
				r1=(r1+(M[max-1][y]*V[y+1]));
			}
			r1%=MOD;
			
			printf("%llu\n",r1);
		}
		else printf("%d\n",V[N]);
 
		i++;
	}
	return 0;
} 
