#include<stdio.h>
#include<string.h>
int sieve[10000050];
int main()
{
int i,j,k,v,t,l=0;
for(i=2;i<=10000005;i++){
                if(sieve[i]!=0)continue;
                for(j=2*i;j<=10000005;j+=i){
                        if(sieve[j]==0)
                        sieve[j]=i;
                }        
 }       
int n;
while(scanf("%d",&n)!=EOF)
{
if(n==1)
{
printf("1\n");
continue;
}
printf("1");
while(sieve[n]!=0)
{
		printf(" x %d",sieve[n]);
		n=n/sieve[n];
}
if(n>1)
printf(" x %d\n",n);
}
return 0;
}
