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
		if (GetAsyncKeyState(VK_LEFT)&&(cur_positionX>45)&& is_forward==1) //方向左键处于按下状态
		{
			cur_positionX += shift(&hero_vx, TIME, FRICTION - ACCELERATION); //设定一个加速度，改变水平坐标
			real_positionX = cur_positionX;
			num++;
			if (num == 4)
				num = 1;
			//hero_show();
		}
		else
		{
			if (hero_vx < 0 && cur_vx !=0)
			{
				cur_positionX += shift(&hero_vx, TIME, FRICTION);
				real_positionX = cur_positionX;

				//num++;
				//if (num == 4)
				//	num = 1;
				//hero_show();
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) && is_forward == 1) //方向右键处于按下状态
		{
			if (cur_positionX <= WIDTH / 2) //人物当前坐标判定
			{
				cur_positionX += shift(&hero_vx, TIME, ACCELERATION - FRICTION); //设定一个加速度，改变水平坐标
				real_positionX = cur_positionX; //记录真实坐标
				//map_position += shift(&hero_vx, TIME, ACCELERATION - FRICTION);
				num++; //num用于实现步伐行走图
				if (num == 4)
					num = 1;
				//hero_show();
				

				 if ( cur_positionX >= WIDTH / 2 && real_positionX <= 5500 && is_forward == 1)
				{
					real_positionX +=shift(&hero_vx, TIME, ACCELERATION - FRICTION);
					map_position += shift(&hero_vx, TIME, ACCELERATION - FRICTION);
					//hero_show();
					num++; //num用于实现步伐行走图
					if (num == 4)
						num = 1;
				}
			}
		
		}
		else
		{
			if (hero_vx > 0 && cur_vx != 0)
			{
				//cur_positionX += shift(&hero_vx, TIME, -FRICTION);
				real_positionX += shift(&hero_vx, TIME, -FRICTION);

				//  num++;
				//  if (num == 4)
				//	num = 1;
				//hero_show();
				

			}
		}

		if (GetAsyncKeyState(VK_UP)) //跳跃
		{
			
		}
}

double shift(double *v,double t,double a)
{
	double s = *v * t + 1 / 2.0*a*t*t;

	if (fabs(*v) >= 10 && a*(*v)>0)
		return s;
	
	*v = *v + a * t;
	cur_vx = *v;
	return s;
}