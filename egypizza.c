#include<stdio.h>
int main()
{
int n,a,b,half=0,ans=0,i,three_fourth=0,one_fourth=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d/%d",&a,&b);
if(a==1 && b==2)	half++;
else if(a==1 && b==4)	one_fourth++;
else			three_fourth++;
}
ans=three_fourth;
one_fourth-=three_fourth;
if(one_fourth<0)	one_fourth=0;
ans+=(half/2);
half=half%2;
one_fourth+=(half*2);
ans+=(one_fourth/4)+(one_fourth%4==0?0:1);
printf("%d",ans+1);
return 0;
}
