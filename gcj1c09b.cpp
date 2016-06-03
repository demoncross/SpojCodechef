#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;
int main()
{
	double vxf,vyf,vzf,xf,yf,zf,a,b,c,min_dist,min_time;
	int i,j,x,y,z,vx,vy,vz,test,n;
	scanf("%d",&test);
	for(i=1;i<=test;i++)
	{
		xf=yf=zf=vxf=vyf=vzf=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d%d%d%d%d%d",&x,&y,&z,&vx,&vy,&vz);
			xf+=x;
			yf+=y;
			zf+=z;
			vxf+=vx;
			vyf+=vy;
			vzf+=vz;
		}
		xf/=n;
		yf/=n;
		zf/=n;
		vxf/=n;
		vyf/=n;
		vzf/=n;
		a=(vxf*vxf)+(vyf*vyf)+(vzf*vzf);
		b=2*((xf*vxf)+(yf*vyf)+(zf*vzf));
		c=(xf*xf)+(yf*yf)+(zf*zf);
		if(a!=0)
		{
			min_time=-(b/(2*a));
		}
		else
		{
			min_time=0;
		}
		printf("%f %f %f\n",a,b,c);
		min_dist=a*(min_time*min_time)+b*(min_time)+c;
		printf("Case #%d: %f %f\n",i,min_dist,min_time);
	}
	return 0;
}