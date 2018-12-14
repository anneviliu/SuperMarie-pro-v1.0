#include"MarieActionfunction.h"

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
		if (GetAsyncKeyState(VK_LEFT) && (cur_positionX > 45))
		{
			cur_positionX += shift_x(&hero_vx, TIME, FRICTION - ACCELERATION); //设定一个加速度，改变水平坐标
			num++;
			if (num == 4)
				num = 1;
			//hero_show();
//			break;
		}
		else
		{
			if (hero_vx < 0 && cur_vx != 0)
			{
				cur_positionX += shift_x(&hero_vx, TIME, FRICTION);
				//num++;
				//if (num == 4)
				//	num = 1;
				//hero_show();
//				break;
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) && (cur_positionX <= WIDTH / 2))
		{
			if (cur_positionX <= WIDTH / 2)
			{
				cur_positionX += shift_x(&hero_vx, TIME, ACCELERATION - FRICTION); //设定一个加速度，改变水平坐标
				real_positionX = cur_positionX; //记录真实坐标
				//map_position += shift(&hero_vx, TIME, ACCELERATION - FRICTION);
				num++; //num用于实现步伐行走图
				if (num == 4)
					num = 1;
				//hero_show();


				if (hero_vx > 0 && cur_positionX > WIDTH / 2 && real_positionX <= 6500)
				{
					real_positionX += shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);
					map_position += shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);
					//hero_show();
					num++; //num用于实现步伐行走图
					if (num == 4)
						num = 1;
				}
			}
//			break;
		}
		else
		{
			if (hero_vx > 0 && cur_vx != 0)
			{
				cur_positionX += shift_x(&hero_vx, TIME, -FRICTION);
				//  num++;
				//  if (num == 4)
				//	num = 1;
				//hero_show();
//				break;

			}
		}
		HpSleep(70);

		if (GetAsyncKeyState(VK_UP) && !is_jump)
		{
			hero_vy = -20;
			is_jump = 1;
			cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
//			break;
		}
		else 
		{
			cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
			if (cur_positionY >= 600) {
				cur_positionY = 600;
				hero_vy = 0;
				cur_vy = 0;
				is_jump = 0;
			}
		}
	
}

double shift_x(double *v,double t,double a)
{
	double s = *v * t + 1 / 2.0*a*t*t;

	if (fabs(*v) >= 5&& a*(*v)>0)
		return s; 
	
	*v = *v + a * t;
	cur_vx = *v;
	return s;
}

double shift_y(double *v, double t, double a)
{
	double s = *v * t + 1 / 2.0*a*t*t;

	if (fabs(*v) >= 10 && a*(*v) > 0)
		return s;

	*v = *v + a * t;
	cur_vy = *v;
	return s;
}