#include<iostream>
#include<cstring>
#include<cmath>
#include<stdio.h>
#define MOD 1000000007
#define REM(x) if(x>=MOD)x%=MOD
using namespace std;
long long int a[101][101];
char s[101];
 
long long int power(int p)
{
    if(p==0) return 1;
        if(p==1) return 2;
        long long int x = power(p>>1);
        x=x*x;
    REM(x);
        if(p&1)
        {
                x<<=1;
                REM(x);
        }
        return x;
}
        
 
 
long long int count(int p)
{
   int i,j,cnt;
   for(i=p-1;i>=0;i--)
        {
            cnt=1;
            a[i][i]=1;
            if(i+1!=p){
            if(s[i]==s[i+1])
            {
                cnt++;
                a[i][i+1]=3;// in case aab-->a,a,aa
            }
            else
            a[i][i+1]=2;
            }
            for(j=i+2;j<p;j++)
            {
                if(s[i]==s[j])
                {
                    cnt++;
                                        REM(cnt);
                    cnt+=a[i+1][j-1];
                                        REM(cnt);
                }
                a[i][j] = a[i+1][j] + cnt;
                                REM(a[i][j]);
                //a[i][j]= a[i][j]%MOD;
            }
        }
            return a[0][p-1] ;
}
 
int main()
{
    int t,p;long long ans;
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%s",s);
        p = strlen(s);
        memset(a,0,sizeof(a));
        ans = power(p) -1 -count(p);
                if(ans<0)ans+=MOD;
        printf("%lld\n",ans);
        t--;
    }
}

