#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
    {
    int test;
    long long int x,y,a,b,t1;
    scanf("%d",&test);
    while(test--)
        {
        scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
        t1=abs((long long)(x-a));
        if(t1%b)
            {
            printf("NO\n");
            continue;
        }
        if(y<b)
            {
            if(y==(a-b))
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
            {
            t1=y-b;
            if(t1%a)    printf("NO\n");
            else        printf("YES\n");
        }
    }
    return 0;
}

