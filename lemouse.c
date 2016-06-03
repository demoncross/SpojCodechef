    #include<stdio.h>
    #define n 100
    #define m 100
    #define maxint 32760
    char map[n][m];
    int check(int i,int j,int rowsize,int colsize)
    {
    if(i>=0&&i<rowsize &&j>=0&&j<colsize)
    {
    if(map[i][j]=='0') return 0;
    else return 1;
    }
    return 0;
    }
    int main()
    {
     
    int scares[n][m]={0};
    char lastcell[n][m];
    int test,i,j,rowsize,colsize,fromabove,fromside;
    scanf("%d",&test);
    while(test-->0)
    {
    scanf("%d %d",&rowsize,&colsize);
    for(i=0;i<rowsize;i++)
    {
    for(j=0;j<colsize;j++)
    scanf(" %c",&map[i][j]);
    }
    for(i=0;i<rowsize;i++)
    {
    for(j=0;j<colsize;j++)
    {
    fromabove=maxint;
    fromside=maxint;
    if(i)
    {
    fromabove=scares[i-1][j]+check(i,j+1,rowsize,colsize)+check(i+1,j,rowsize,colsize);
    if(lastcell[i-1][j]!='l')
    fromabove+=check(i,j-1,rowsize,colsize);
    if(i==1&&j==0)
    fromabove+=check(0,0,rowsize,colsize);
     
    }
    if(j)
    {
    fromside=scares[i][j-1]+check(i,j+1,rowsize,colsize)+check(i+1,j,rowsize,colsize);
    if(lastcell[i][j-1]!='u')
    fromside+=check(i-1,j,rowsize,colsize);
    if(i==0&&j==1)
    fromside+=check(0,0,rowsize,colsize);
    }
    if(!i&&!j)
    {
    scares[0][0]=check(i+1,j,rowsize,colsize)+check(i,j+1,rowsize,colsize);
    lastcell[i][j]=0;
    }
    else if(fromside<fromabove)
    {
    scares[i][j]=fromside;
    lastcell[i][j]='l';
    }
    else
    {
    scares[i][j]=fromabove;
    lastcell[i][j]='u';
    }
    }
    }
     
    printf("%d\n",scares[rowsize-1][colsize-1]);
     
    }
    return 0;
    } 
