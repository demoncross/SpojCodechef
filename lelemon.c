    #include<stdlib.h>
    #include<stdio.h>
    #define N 101
    #define MAX 327656
    int a[N][N]={0};
    int z;
    void merge(int i,int j)
    {
    int c[1000],d[1000];
    int mid=(i+j)/2;
    int k,h=0,g=0;
    for(k=0;k<=mid-i;k++)
    c[k]=a[z][i+k];
    c[k]=MAX;
    for(k=0;k<j-mid;k++)
    d[k]=a[z][mid+1+k];
    d[k]=MAX;
    for(k=i;k<=j;k++)
    {
    if(c[g]<d[h])
    {
    a[z][k]=c[g];
    g++;
    }
    else
    {
    a[z][k]=d[h];
    h++;
    }
    }
    }
     
    int sort(int start,int end)
    {
    if(start==end)
    return start;
    sort(start,(start+end)/2);
    sort((start+end)/2+1,end);
    merge(start,end);
    }
    int main()
    {
    int i,j,test,n,m,ca,sum;
    int p[10000],c[100];
    scanf("%d",&test);
    while(test-->0)
    {
    sum=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)	scanf("%d",&p[i]);
    for(z=0;z<n;z++)
    {scanf("%d",&ca);
    for(j=0;j<ca;j++)	scanf(" %d",&a[z][j]);
    c[z]=ca;
    sort(0,ca-1);
    }
    for(i=0;i<m;i++)
    {
    if(c[p[i]]==0)	sum+=0;
    else
    {
    sum+=a[p[i]][c[p[i]]-1];
    c[p[i]]--;
    }
    }
    printf("%d\n",sum);
    }
    return 0;
    } 
