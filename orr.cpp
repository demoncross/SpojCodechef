#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
char s[100005],t[100005];

int main()
    {
    int test,l1,l2,plus1,plus2,minus1,minus2,i,r_e,c;
    long long int ans;
    scanf("%d",&test);
    while(test--)
        {
        scanf(" %s %s",s,t);
        l1=strlen(s);
        l2=strlen(t);
        plus1=plus2=minus1=minus2=0;
        for(i=0;i<l1;i++)
            {
            if(s[i]=='+')   plus1++;
            else            minus1++;
        }
        for(i=0;i<l2;i++)
            {
            if(t[i]=='+')   plus2++;
            else            minus2++;
        }
        if(plus1!=plus2 || minus1!=minus2)  
            {
            printf("-1\n");continue;
        }
        r_e=0;
        c=s[0];
        ans=0;
        for(i=0;i<l1;i++)
            {
            if(c==t[i]) 
            {
                if(r_e==i)  {r_e=i+1;c=s[i+1];}
                continue;
            }
            r_e++;
                for(;r_e<l1 && s[r_e]!=t[i];r_e++);
            ans=ans+r_e-i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}