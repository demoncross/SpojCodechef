#include<stdio.h>
#include<stdlib.h>
typedef struct p
{
    int f,s;
}pp;
int ht[20];
pp dp[16][1<<17];
int main()
{
    pp ans,q,max;
    int i,j,k,l,n,left;
    scanf("%d",&n);
    while(n)
    {
        for(i=0;i<n;i++)    scanf("%d",&ht[i]);
        for(i=0;i<(1<<n);i++)
        {
            for(j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    left=i^(1<<j);
                    max.f=-1;
                    for(l=0;l<n;l++)
                    {
                        if(left&(1<<l))
                        {
                            q=dp[l][left];
                            q.f+=2+ht[j]-ht[l]+abs(ht[j]-ht[l]);
                            if(q.f>max.f)   max=q;
                            else if(q.f==max.f) max.s+=q.s;
                        }
                    }
                    if(left==0)    
                        {
                            dp[j][i].f=2*ht[j]+2;
                            dp[j][i].s=1;
                    }
                    else dp[j][i]=max;
                }
            }
        }
        ans.f=-1;
        for(i=0;i<n;i++)
        {
            if(dp[i][(1<<n)-1].f>ans.f) ans=dp[i][(1<<n)-1];
            else if(dp[i][(1<<n)-1].f==ans.f)   ans.s+=dp[i][(1<<n)-1].s;
        }
        printf("%d %d\n",ans.f,ans.s);
        scanf("%d",&n);
    }
    return 0;
}