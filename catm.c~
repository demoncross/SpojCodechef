#include<stdio.h>
int main()
{
int t,x,y,m_x,m_y,c1_x,c1_y,c2_x,c2_y;
int time_top_m,time_bot_m,time_left_m,time_right_m;
int time_top_c1,time_bot_c1,time_left_c1,time_right_c1;
int time_top_c2,time_bot_c2,time_left_c2,time_right_c2;
scanf("%d %d",&x,&y);
scanf("%d",&t);
while(t--)
{
	scanf("%d%d%d%d%d%d",&m_x,&m_y,&c1_x,&c1_y,&c2_x,&c2_y);
	time_top_m=m_x-1;
	time_bot_m=x-m_x;
	time_left_m=m_y-1;
	time_right_m=y-m_y;
	time_top_c1=c1_x-1;
	time_bot_c1=x-c1_x;
	time_left_c1=c1_y-1;
	time_right_c1=y-c2_y;
	time_top_c2=c2_x-1;
	time_bot_c2=x-c2_x;
	time_left_c2=c2_y-1;
	time_right_c2=y-c2_y;
	if((time_top_m<time_top_c2+abs(c2_y-m_y) && time_top_m<time_top_c1+abs(c1_y-m_y))||(time_bot_m<time_bot_c2+abs(c2_y-m_y) && time_bot_m<time_bot_c1+abs(c1_y-m_y))||(time_left_m<time_left_c2+abs(c2_x-m_x) && time_left_m<time_left_c1+abs(c1_x-m_x))||(time_right_m<time_right_c2+abs(c2_x-m_x) && time_right_m<time_right_c1+abs(c1_x-m_x)))
		printf("YES\n");
	else
		printf("NO\n");
}
return 0;
}
