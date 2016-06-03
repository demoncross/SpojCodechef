#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;
 
#define df(i,a,b) for(typeof(b) i=a;i>=b;i--)
#define f(i,a,b) for(typeof(b) i=a;i<=b;i++)
#define fill(x,a) memset(x,a,sizeof(x))
#define Clear(x) memset(x,0,sizeof(x))
#define inf 2147000000
#define pb push_back
#define mp make_pair
#define Y second
#define X first
 
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
 
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
 
typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<string> VS;
typedef pair<int,int> ii;
typedef vector<int> VI;
 
 
 
template <class T>
inline void read(T &i)
{
bool minus=false;
char c;
for(c=getchar();(c<'0'||c>'9')&&(c!='-');c=getchar());
if(c=='-')
{minus=true;
c='0';}
for(i=0;c>='0'&&c<='9';c=getchar())
i=(i<<3)+(i<<1) + (c-48);
if(minus)
i=(~i)+1;
}
 
 
int gcd(int a,int b)
{
   if(a==b)
     return b;
     
   if(b<a)
     return gcd(a%b,b);
   
   return gcd( a, b%a);
} 
 
 
vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;
  
  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);
 
  return ans;
}
/*Solution code starts here */
                                         
#define maxi 10001
 
struct node
{
       int st,fn,gn;
       
       bool operator <( const node &a) const
        { return ( fn < a.fn);
        }
};
 
int test,n,dp[maxi],maks;
 
node data[maxi];
 
int main()
{
    
    int test;
   // fi;fo;
    
     read(test);
     
     while(test--)
      {
                   
                  read(n);
                  
                  int i,j,maks;
                  
                  for(i=0;i<n;i++)
                   { read(data[i].st);
                       read(data[i].fn);
                         read(data[i].gn);         
                          data[i].fn+=data[i].st;
                   }        
                   
                   sort(data,data+n);
                   
                     for(i=0;i<n;i++)
                      { maks=0;
                      
                         for(j=0;j<i;j++)
                           {
                              if( data[j].fn < data[i].st )
                                maks=max( maks , dp[j] );           
                              else
                                break;
                           }       
                           
                           dp[i]=maks+data[i].gn;
                      }      
                      
                      int mx=0;
                      for(i=0;i<n;i++)
                       mx=max(mx, dp[i] );
                       
                       printf("%d\n",mx);
              }
              
              return 0;
              }
                                
