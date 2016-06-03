//Given a matrix of only 1s and 0s, find the area of the largest submatrix(square/rectangle) containg only 1s
//very similar to the histogram problem

#include<cstdio>
#include<stack>
#include<cstdlib>

using namespace std;

char a[2001][2001];
int dp[2001][2001];
int main()
{
	int i,j,n,m,x,k,q,max;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)	
				{
					scanf(" %c",&a[i][j]);
					dp[i][j]=a[i][j]-'0';
				}
		}
		for(i=1;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='0')
					dp[i][j]=0;
				else
					dp[i][j]=dp[i-1][j]+1;
			}
		}
		stack < int > s;
		max=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(s.empty() || dp[i][s.top()]<=dp[i][j])
					s.push(j);
				else
				{
					while(!s.empty() && dp[i][s.top()]>dp[i][j])
					{
						x=s.top();
						s.pop();
						q=dp[i][x]*(s.empty()?j:j-s.top()-1);
						if(q>max)	max=q;
					}
					s.push(j);
				}
			}
			while(!s.empty())
			{
				x=s.top();
				s.pop();
				q=dp[i][x]*(s.empty()?j:j-s.top()-1);
				if(q>max)	max=q;	
			}
			//printf("%d ",max);
		}
		printf("%d\n",max);
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)	printf("%d ",dp[i][j]);
				printf("\n");
		}*/
	}
	return 0;
}