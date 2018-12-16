#include"MarieActionfunction.h"
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
		if (GetAsyncKeyState(VK_LEFT) && (cur_positionX > 45))
		{
			cur_positionX += shift_x(&hero_vx, TIME, FRICTION - ACCELERATION); //设定一个加速度，改变水平坐标
			real_positionX += shift_x(&hero_vx, TIME, FRICTION - ACCELERATION);
			num++;
			if (num == 4)
				num = 1;
			//hero_show();
		}
		else
		{
			if (hero_vx < 0 && cur_vx !=0)
			{
				cur_positionX += shift_x(&hero_vx, TIME, FRICTION);
				real_positionX+= shift_x(&hero_vx, TIME, FRICTION);
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
				real_positionX += shift_x(&hero_vx, TIME, ACCELERATION - FRICTION); //记录真实坐标
				//map_position += shift(&hero_vx, TIME, ACCELERATION - FRICTION);
				num++; //num用于实现步伐行走图
				if (num == 4)
					num = 1;
				//hero_show();


				if (hero_vx > 0 && cur_positionX > WIDTH / 2 && real_positionX <= 6500)
				{
					real_positionX +=shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);
					map_position += shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);
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
				cur_positionX += shift_x(&hero_vx, TIME, -FRICTION);
				real_positionX+= shift_x(&hero_vx, TIME, -FRICTION);
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

double shift_x(double *v, double t, double a)
{
		double s = *v * t + 1 / 2.0*a*t*t;

		if (fabs(*v) >= 5 && a*(*v) > 0)
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
			cur_positionY += 10;
			real_positionY += 10;
			//死亡特效（待添加）
		}
	}
	if (real_positionX - HERO_WIDTH / 2 >= blank[1].begin_x &&real_positionX + HERO_WIDTH / 2 <= blank[1].final_x)
	{
		if (is_jump == 0)
		{
			cur_positionY += 10;
			real_positionY += 10;
			//死亡特效（待添加）
		}
	}
	
}

