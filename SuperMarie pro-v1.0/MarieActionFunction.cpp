#include"MarieActionfunction.h"
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include "Mdefine.h"
#include "main.h"
#include "MarieDisplayFunction.h"
#include <time.h>
struct Blank
{
	double begin_x;
	double final_x;
};
Blank blank[2];

struct Block
{
	double begin_x;
	double final_x;
	double high;
};
Block block[4];
void HpSleep(int ms)
{
	static clock_t oldclock = clock();		// 静态变量，记录上一次 tick

	oldclock += ms * CLOCKS_PER_SEC / 1000;	// 更新 tick

	if (clock() > oldclock)					// 如果已经超时，无需延时
		oldclock = clock();
	else
		while (clock() < oldclock)			// 延时
			Sleep(1);						// 释放 CPU 控制权，降低 CPU 占用率
}  //精准时间控制 

void hero_move()
{
	//用GetAsynckeyState函数解决按键延迟问题
	if (GetAsyncKeyState(VK_LEFT)&&cur_positionX>0)
	{
		if (cur_positionX > 45)
		{
			cur_positionX += shift_x(&hero_vx, TIME, FRICTION - ACCELERATION); //设定一个加速度，改变水平坐标
			//real_positionX += shift_x(&hero_vx, TIME, FRICTION - ACCELERATION);
			real_positionX += shift_x(&hero_vx, TIME, FRICTION - ACCELERATION);
			num++;
			if (num == 4)
				num = 1;
		}

	}

	else //方向左键释放
	{
		if (hero_vx < 0)
		{
			hero_vx = 0;
			//cur_positionX += shift_x(&hero_vx, TIME, FRICTION);
			//real_positionX += shift_x(&hero_vx, TIME, FRICTION);
			//real_positionX += shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);

		}
	}

	if (GetAsyncKeyState(VK_RIGHT)&&cur_positionX<=WIDTH)
	{
		if (cur_positionX >= WIDTH / 2.0 && map_position <= 4800)
		{
			map_position += shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);
			real_positionX += shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);
		}
		else 
		{
			real_positionX += shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);
			cur_positionX += shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);
		}
	
		 //设定一个加速度，改变水平坐标
		
		//real_positionX = cur_positionX; //记录真实坐标
		
		num++; //num用于实现步伐行走图
		if (num == 4)
			num = 1;

	}
	else //右键释放
	{
		if (hero_vx > 0)
		{
			if (real_positionX <= WIDTH / 2.0)
			{
				hero_vx = 0;
				//cur_positionX += shift_x(&hero_vx, TIME, -FRICTION);
				//real_positionX += shift_x(&hero_vx, TIME, FRICTION - ACCELERATION);
			}
			else
			{
				hero_vx = 0;
				//map_position += shift_x(&hero_vx, TIME, -FRICTION);
				//real_positionX += shift_x(&hero_vx, TIME, FRICTION - ACCELERATION);

			}

		}
	}

	if (GetAsyncKeyState(VK_UP) && !is_jump)
	{
		hero_vy = -22;//跳跃初速度
		is_jump = 1;//是否跳跃
		cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
	}
	else
	{
		cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
		if (cur_positionY >= 600) {//是否落地
			cur_positionY = HIGH-120;
			hero_vy = 0;
			cur_vy = 0;
			is_jump = 0;
		}
	}

	HpSleep(70);

}

double shift_x(double *v, double t, double a)
{
	double s = *v * t + 1 / 2.0*a*t*t;//位移量

	if (fabs(*v) >= 4 && a*(*v) > 0)//限制最大速度
		return s;

	*v = *v + a * t;//速度更新
	cur_vx = *v;
	return s;
}

double shift_y(double *v, double t, double a)
{
	double s = *v * t + 1 / 2.0*a*t*t;//位移量

	if (fabs(*v) >= 10 && a*(*v) > 0)//限制最大速度
		return s;

	*v = *v + a * t;//速度更新
	cur_vy = *v;
	return s;
}

void judge()
{
	block[0].begin_x = 1450;
	block[0].final_x = 1550;
	block[0].high = 540;
	block[1].begin_x = 1970;
	block[1].final_x = 2070;
	block[1].high = 490;
	block[2].begin_x = 2385;
	block[2].final_x = 2485;
	block[2].high = 440;
	block[3].begin_x = 2945;
	block[3].final_x = 3045;
	block[3].high = 440;   //初始化阻挡物

	blank[0].begin_x = 3570;
	blank[0].final_x = 3680;
	blank[1].begin_x = 4450;
	blank[1].final_x = 4610; //初始化空地

	if (real_positionX - HERO_WIDTH / 2 >= blank[0].begin_x &&real_positionX + HERO_WIDTH / 2 <= blank[0].final_x)

	{
		if (is_jump == 0)
		{
			cur_positionY += 100;
			
			//死亡特效（待添加）
		}
	}
	if (real_positionX - HERO_WIDTH / 2 >= blank[1].begin_x &&real_positionX + HERO_WIDTH / 2 <= blank[1].final_x)
	{
		if (is_jump == 0)
		{
			cur_positionY += 100;
			
			//死亡特效（待添加）
		}
	}
	

}