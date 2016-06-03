#include<cstdio>
#include<vector>
#include<iostream>
#define scanint(n) scanf("%d", &n)
using namespace std;

int main(){
	
	vector<int> list[1025];
	for (int i=1; i<=1023; i++) {
		for (int j=i+1; j<=1024; j++) {
			if ((i&j)!=0) {
				list[i].push_back(j);
			}
		}
	}
	
	long long value[1025]={0};
	bool digitPresent[10];
	int t;
	int n;
	char str[20];
	scanint(t);
	while (t--) {
		long long total=0;
		scanint(n);
		for (int i=0; i<=1024; i++) {
			value[i]=0;
		}
		
		for (int i=0; i<n; i++) {
			scanf("%s", str);
			
			for (int i=0; i<=9; i++) {
				digitPresent[i]=false;
			}
			int i=0;
			while (str[i]) {
				digitPresent[str[i]-'0']=true;
				i++;
			}
			
			int numCheck=0;
			for (int i=0; i<=9; i++) {
				if (digitPresent[i]) {
					numCheck|=(1<<i);
				}
			}
			//cout << numCheck<<endl;
			value[numCheck]++;
		}
		long long tempTotal=0;
		for(int numCheck=1;numCheck<=1024;numCheck++){
		  for (int i=0; i<list[numCheck].size(); i++) {
			//cout <<"Yo-->"<< numCheck<<" "<<list[numCheck][i]<<" "<<value[numCheck]*value[list[numCheck][i]]<<endl;
			tempTotal+=(value[numCheck]*value[list[numCheck][i]]);
			}
			tempTotal+=(value[numCheck]*(value[numCheck]-1)/2);
		}
		//total+=tempTotal;
		
		printf("%lld\n", tempTotal);
	}
	
	
	return 0;
}