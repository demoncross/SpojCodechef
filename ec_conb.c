#include<stdio.h>
int main()
{
int n,q,i,mask,a,ans;
scanf("%d",&n);
for(i=0;i<n;i++)
{
	a=0;
	ans=0;
	scanf("%d",&q);
	if(q%2==1)	printf("%d\n",q);
	else{
	mask=1;
	mask<<=30;
	//printf("%d ",mask);
	while(!(mask&q))	mask>>=1;
	//printf("%d ",mask&q);
	while(mask)
	{
		if(mask&q){	ans+=(1<<a); 	}
		mask>>=1;	
		a++;
	}
	printf("%d\n",ans);
	}
}
return 0;
}
