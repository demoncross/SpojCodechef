#include<cstdio>
#include<vector>
#define scanint(n) scanf("%d", &n)
using namespace std;
int main(){
	
	vector<int> list[1025];
	for (int i=1; i<=1024; i++) {
		for (int j=1; j<=1023; j++) {
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
			
			long long tempTotal=0;
			for (int i=0; i<list[numCheck].size(); i++) {
				tempTotal+=value[list[numCheck][i]];
			}
			value[numCheck]++;
			total+=tempTotal;
		}
		
		printf("%lld\n", total);
	}
	
	
	return 0;
}