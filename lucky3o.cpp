#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
using namespace std;
 
long long dp[1024][55], t, n, ans;
char str[55][15], temp[15];
 
long long fun(int mask, int pos, int len, int num)
{
    //printf("hello");
    if(pos>n)
    {
        if(mask==((1<<len)-1))
        {
            //printf("dshkjfhk");
            return 1;
        }
        //printf("%d  %d  %d  %d\n", mask, pos, len, num);
        return 0;
    }
    if(dp[mask][pos]==-1)
    {
        int mask2=mask;
        long long temp=fun(mask, pos+1, len, num);
        if(strlen(str[pos])<=len)
        {
            int flag=0;
            for(int i=0; i<strlen(str[pos]); i++)
            {
                if((1<<i)&(num))
                {
                    if(str[pos][i]>'7')
                    {
                        //printf("jhdjkdf");
                        flag=1;
                        break;
                    }
                    if(str[pos][i]=='7')
                        mask2|=(1<<i);
                }
                else
                {
                    if(str[pos][i]>'4')
                    {
                        //printf("fdklklj");
                        flag=1;
                        break;
                    }
                    if(str[pos][i]=='4')
                        mask2|=(1<<i);
                }
            }
            if(!flag)
                temp+=fun(mask2, pos+1, len, num);
        }
        dp[mask][pos]=temp;
    }
    return dp[mask][pos];
}
 
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        int len=0;
        ans=0;
        scanf("%lld",&n);
        getchar();
        for(int i=1; i<=n; i++)
        {
            scanf("%s",temp);
            len=max(len, (int)(strlen(temp)));
            str[i][strlen(temp)]='\0';
            int k=0;
            for(int j=strlen(temp)-1; j>=0; j--)
                str[i][k++]=temp[j];
        }
 
        for(int i=1; i<=len; i++)
        {
            for(int j=0; j<(1<<i); j++)
            {
                for(int k=0; k<(1<<i); k++)
                    for(int l=1; l<=n; l++)
                        dp[k][l]=-1;
                ans+=fun(0, 1, i, j);
                //printf("%lld\n",fun(0,1,i,j));
            }
        }
 
        printf("%lld\n", ans);
    }
    return 0;
}