#include <stdio.h>

void main()
{
    int N,i,j;
    scanf("%d",&N);
    double **F=new double*[N];
    for(i=0;i<N;i++)
     {
        F[i]=new double[N];
        for(j=0;j<N;j++) F[i][j]=0;
        F[i][i]=1;
    }
    for(i=1;i<N;i++)
        for(j=i-1;j>=0;j--)  F[i][j]=F[i-j-1][j+1]+F[i][j+1];
    printf("%.0lf",F[N-1][0]-1);
}