#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;
int a[100005],c[100005];
int main()
{
    int i,j,ans,d,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)    scanf("%d",&a[i]);
    sort(a,a+n);
    ans=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            d=a[j]-a[i];
            if(c[d]==0)
            {
                ans++;
                c[d]=1;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}