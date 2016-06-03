#include <stdio.h>
#include <string.h>
#define mod 23102009

int max(int a,int b)
{
	return a>b?a:b;
}

char s1[1003],s2[1003];
int f[1003][30],s[1003][30];
int lcs[1003][1003],lcsn[1003][1003];

void clear_all(void)
{
	int l1,l2,i,j,x;
	l1=strlen(s1);
	l2=strlen(s2);
	for(i=0;i<=1000;i++)
		for(j=0;j<=28;j++)	f[i][j]=s[i][j]=-1;
}

void work(void)
{
	int l1,l2,i,j,c,fir,sec,x,y;
	l1=strlen(s1);
	l2=strlen(s2);
	for(i=l1-1;i>=0;i--)
	{
		for(c='a';c<='z';c++)
		{
			if(s1[i]==c)	f[i][c-'a']=i;
	

			else		f[i][c-'a']=f[i+1][c-'a'];
		}
	}
	for(i=l2-1;i>=0;i--)
	{
		for(c='a';c<='z';c++)
		{
			if(s2[i]==c)	s[i][c-'a']=i;
	

			else		s[i][c-'a']=s[i+1][c-'a'];
		}
	}
	for(i=l1;i>=0;i--)
	{
		for(j=l2;j>=0;j--)
		{
			lcs[i][j]=0;
			if(i==l1||j==l2)	lcs[i][j]=0;
			else
			{
				lcs[i][j]=max(lcs[i][j+1],lcs[i+1][j]);
				if(s1[i]==s2[j])
					lcs[i][j]=max(lcs[i][j],lcs[i+1][j+1]+1);
			}
		}
	}	
	for(i=l1;i>=0;i--)
	{
		for(j=l2;j>=0;j--)
		{
			lcsn[i][j]=0;
			for(c='a';c<='z';c++)
			{
				if(i==l1 || j==l2)	
				{
					lcsn[i][j]=1;
					continue;
				}
				x=f[i][c-'a'];
				y=s[j][c-'a'];
				if(x==-1 || y==-1)
				{
					if(lcs[i][j]==0)	lcsn[i][j]=1;
					continue;
				}
				if(lcs[x+1][y+1]==lcs[i][j]-1)
					lcsn[i][j]=(lcsn[i][j]+lcsn[x+1][y+1])%mod;
			}
		}
	}
	printf("%d %d\n",lcs[0][0],lcsn[0][0]);
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf(" %s %s",s1,s2);
		clear_all();
		work();
	}
	return 0;
}




