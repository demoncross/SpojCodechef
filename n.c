    #include<stdio.h>
    #define MOD 1000000007ll
     
    unsigned long long fun(unsigned long long a)
    {
    unsigned long long temp2;
    if(a==1) return 2;
    else
    {
    temp2=fun(a>>1);
    if(a&0x01) return (((temp2*temp2)%MOD)<<1ll)%MOD;
    else return ((temp2*temp2)%MOD);
    }
    }
    int main(void)
    {
    int T;
    unsigned long long sum,temp,N,i=0;
    scanf("%d",&T);
    while(T--)
    {
    scanf("%lld",&N);
    if(N<4)
    printf("%lld\n",N*2);
    else
    {
    sum=1ll;
    i=32;
    temp=N;
    temp=temp>>1;
    sum=fun(temp);
    if(N&0x01)printf("%lld\n",(((sum<<2)%MOD)-2ll)%MOD);
    else printf("%lld\n",(((sum*3)%MOD)-2ll)%MOD);
    }
    }
    return 0;
    } 
