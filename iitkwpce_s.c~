#include<string.h>
#include<stdio.h>
#define max 2005
char str[max];
int matrix[max][max];
int ans[max];
int main()
{
int i,j,k,l,test,q,min,len;
scanf("%d",&test);
while(test--)
{
	scanf(" %s",str);
	len=strlen(str);
	for(i=0;i<len;i++)	matrix[i][i]=1;
	for(l=2;l<=len;l++)
	{
		for(i=0;i<=len-l;i++)
		{
			j=i+l-1;
			if(l==2 && str[i]==str[j])
				matrix[i][j]=1;
			else if(l==2)
				matrix[i][j]=0;
			else if(str[i]==str[j] && matrix[i+1][j-1])
				matrix[i][j]=1;
			else
				matrix[i][j]=0;
		}
	}
	ans[0]=1;
	for(i=1;i<len;i++)
	{
		if(matrix[0][i])
		{
			ans[i]=1;
			continue;
		}
		min=1000000;
		for(j=0;j<i;j++)
		{
			if(matrix[j+1][i])
			{
				q=ans[j]+1;
				if(q<min)	min=q;
			}
		}
		ans[i]=min;
	}
	printf("%d\n",ans[len-1]);
}
return 0;
}
