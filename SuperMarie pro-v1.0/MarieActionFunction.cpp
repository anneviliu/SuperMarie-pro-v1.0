﻿#include"MarieActionfunction.h"
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
	if (GetAsyncKeyState(VK_LEFT) && cur_positionX > 0 && can_left == 1)
	{
		old_positionX = real_positionX;
		is_left = 1;
		is_right = 0;
		if (cur_positionX > 45)
		{
			double shift_temp = shift_x(&hero_vx, TIME, FRICTION - ACCELERATION);//使用一个变量存此次位移量
			cur_positionX += shift_temp; //设定一个加速度，改变水平坐标
			//real_positionX += shift_x(&hero_vx, TIME, FRICTION - ACCELERATION);
			real_positionX += shift_temp;
			num_hero++;
			if (num_hero == 4)
				num_hero = 1;
		}

	}

	else //方向左键释放
	{
		old_positionX = real_positionX;

		if (hero_vx < 0)
		{
			double shift_temp = shift_x(&hero_vx, TIME, FRICTION);
			cur_positionX += shift_temp;
			real_positionX += shift_temp;

		}
	}

	if (GetAsyncKeyState(VK_RIGHT) && cur_positionX <= WIDTH && can_right == 1)
	{
		old_positionX = real_positionX;

		is_right = 1;
		is_left = 0;
		if (cur_positionX >= WIDTH / 2.0 && map_position <= 5000)
		{
			double shift_temp = shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);//存此次位移量
			map_position += shift_temp;
			real_positionX += shift_temp;
		}
		else
		{
			double shift_temp = shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);//存此次位移量
			real_positionX += shift_temp;
			cur_positionX += shift_temp;
		}

		//设定一个加速度，改变水平坐标

	   //real_positionX = cur_positionX; //记录真实坐标

		num_hero++; //num_hero_hero用于实现步伐行走图
		if (num_hero == 4)
			num_hero = 1;

	}
	else //右键释放
	{
		old_positionX = real_positionX;

		if (hero_vx > 0)
		{
			if (real_positionX <= WIDTH / 2.0)
			{
				double shift_temp = shift_x(&hero_vx, TIME, -FRICTION);//存此次位移量
				cur_positionX += shift_temp;
				real_positionX += shift_temp;//该变量用于判断位置
			}
			else
			{
				double shift_temp = shift_x(&hero_vx, TIME, -FRICTION);
				map_position += shift_temp;
				real_positionX += shift_temp;

			}

		}
	}

	if (GetAsyncKeyState(VK_UP) && !is_jump)
	{
		mciSendString("play music_jump from 0", NULL, 0, NULL);//跳跃音效

		hero_vy = -23;//跳跃初速度
		is_jump = 1;//是否跳跃
		cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
	}
	else
	{
		cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
		if (cur_positionY >= 600)
		{//是否落地
			cur_positionY = HIGH - 120;
			hero_vy = 0;
			cur_vy = 0;
			is_jump = 0;
		}
	}

	HpSleep(2);

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
	int i;
	block[0].begin_x = 1450;
	block[0].final_x = 1550;
	block[0].high = 540;
	block[1].begin_x = 1970;
	block[1].final_x = 2070;
	block[1].high = 490;
	block[2].begin_x = 2385;
	block[2].final_x = 2485;
	block[2].high = 440;
	block[3].begin_x = 2953;
	block[3].final_x = 3054;
	block[3].high = 438;   //初始化阻挡物

	blank[0].begin_x = 3570;
	blank[0].final_x = 3680;
	blank[1].begin_x = 4450;
	blank[1].final_x = 4610; //初始化空地

///////////////////////////////////////////空地判定//////////////////////////////////////////////////////////////////////
	if (real_positionX - HERO_WIDTH / 2 >= blank[0].begin_x &&real_positionX + HERO_WIDTH / 2 <= blank[0].final_x)

	{
		if (is_jump == 0)
		{
			is_jump = 1;
			is_die = 1;
			can_forward = 0;
			cur_positionY += shift_y(&hero_vy, DIE_TIME, DIE_A);
		}
	}
	if (real_positionX - HERO_WIDTH / 2.0 >= blank[1].begin_x &&real_positionX + HERO_WIDTH / 2.0 <= blank[1].final_x)
	{
		if (is_jump == 0)
		{
			is_jump = 1;
			can_forward = 0;
			is_die = 1;
			cur_positionY += shift_y(&hero_vy, DIE_TIME, DIE_A);
		}
	}

////////////////////////////////水管支撑////////////////////////////////////////////////////
	for (i = 0; i < 4; i++)
	{
		if (real_positionX + HERO_WIDTH / 2.0 >= block[i].begin_x - 13
			&& real_positionX + HERO_WIDTH / 2.0 <= block[i].final_x + 5
			&& cur_positionY + HERO_HIGH >= block[i].high
			&& cur_positionY + HERO_HIGH <= block[i].high + 10)
		{
			is_jump = 0;
			cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
		}
	}

/////////////////////////////////砖块支撑////////////////////////////////////////////////////
	if (real_positionX + HERO_WIDTH / 2.0 >= 600
		&& real_positionX + HERO_WIDTH / 2.0 <= 600 + 97 * 3
		&& cur_positionY + HERO_HIGH >= 460 && cur_positionY + HERO_HIGH <= 470)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}
	if (real_positionX + HERO_WIDTH / 2.0 >= 891
		&& real_positionX + HERO_WIDTH / 2.0 <= 891 + 97 + 49
		&& cur_positionY + HERO_HIGH >= 400 && cur_positionY + HERO_HIGH <= 410)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}
	if (real_positionX + HERO_WIDTH / 2.0 >= 2550
		&& real_positionX + HERO_WIDTH / 2.0 <= 2550 + 97 * 2
		&& cur_positionY + HERO_HIGH >= 400 && cur_positionY + HERO_HIGH <= 410)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}
	if (real_positionX + HERO_WIDTH / 2.0 >= 4000
		&& real_positionX + HERO_WIDTH / 2.0 <= 4000 + 97 * 2
		&& cur_positionY + HERO_HIGH >= 420 && cur_positionY + HERO_HIGH <= 430)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 2220
		&& real_positionX + HERO_WIDTH / 2.0 <= 2220 + 97
		&& cur_positionY + HERO_HIGH >= 430 && cur_positionY + HERO_HIGH <= 440)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 3410
		&& real_positionX + HERO_WIDTH / 2.0 <= 3410 + 97
		&& cur_positionY + HERO_HIGH >= 470 && cur_positionY + HERO_HIGH <= 480)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}
	
	
///////////////////////////////////////向右障碍判定////////////////////////////////////
	for (i = 0; i < 4; i++)
	{
		if (real_positionX + HERO_WIDTH / 2.0 >= block[i].begin_x - 15
			&& real_positionX + HERO_WIDTH / 2.0 <= block[i].begin_x
			&& cur_positionY + HERO_HIGH >= block[i].high + 15
			&& is_right == 1)
		{
			hero_vx = 0;
			can_right = 0;
		} 

///////////////////////////////////////向左障碍判定///////////////////////////////////
		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_UP))
			can_right = 1;
	}
	for (i = 0; i < 4; i++)
	{
		if (real_positionX + HERO_WIDTH / 2.0 >= block[i].final_x
			&& real_positionX + HERO_WIDTH / 2.0 <= block[i].final_x + 15
			&& cur_positionY + HERO_HIGH >= block[i].high + 15
			&& is_left == 1)
		{
			hero_vx = 0;
			can_left = 0;
		}

		if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_UP))
			can_left = 1;
	} 

///////////////////////////////////////砖块左边界/////////////////////////////////////////
	if (real_positionX + HERO_WIDTH / 2.0 >= 590 && real_positionX + HERO_WIDTH / 2.0 <= 600
		&& cur_positionY + HERO_HIGH <= 460 + 48 && cur_positionY + HERO_HIGH >= 460 && is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
	{
		can_right = 1;
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 2540 && real_positionX + HERO_WIDTH / 2.0 <= 2550
		&& cur_positionY + HERO_HIGH <= 400 + 48 && cur_positionY + HERO_HIGH >= 400 && is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
	{
		can_right = 1;
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 881 && real_positionX + HERO_WIDTH / 2.0 <= 891
		&& cur_positionY + HERO_HIGH <= 460 && cur_positionY + HERO_HIGH >= 400 && is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
	{
		can_right = 1;
	}
	if (real_positionX + HERO_WIDTH / 2.0 >= 3990 && real_positionX + HERO_WIDTH / 2.0 <= 4000
		&& cur_positionY + HERO_HIGH <= 468 && cur_positionY + HERO_HIGH >= 420 && is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
	{
		can_right = 1;
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 3400 && real_positionX + HERO_WIDTH / 2.0 <= 3410
		&& cur_positionY + HERO_HIGH <= 480 + 47 && cur_positionY + HERO_HIGH >= 480 && is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
	{
		can_right = 1;
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 2220 && real_positionX + HERO_WIDTH / 2.0 <= 2230
		&& cur_positionY + HERO_HIGH <= 430 + 47 && cur_positionY + HERO_HIGH >= 430 && is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
	{
		can_right = 1;
	}
//////////////////////////////////////////////砖块右边界//////////////////////////////////////////
	if (real_positionX + HERO_WIDTH / 2.0 >= 600 + 97 * 3 && real_positionX + HERO_WIDTH / 2.0 <= 600 + 97 * 3 + 10
		&& cur_positionY + HERO_HIGH <= 460 + 48 && cur_positionY + HERO_HIGH >= 460 && is_left == 1)
	{
		hero_vx = 0;
		can_left = 0;
	}
	else
	{
		can_left = 1;
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 988 + 47 && real_positionX + HERO_WIDTH / 2.0 <= 988 + 47 + 10
		&& cur_positionY + HERO_HIGH <= 447 && cur_positionY + HERO_HIGH >= 400 && is_left == 1)
	{
		hero_vx = 0;
		can_left = 0;
	}
	else
	{
		can_left = 1;
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 2550 + 97 * 2 && real_positionX + HERO_WIDTH / 2.0 <= 2550 + 97 * 2 + 10
		&& cur_positionY + HERO_HIGH <= 447 && cur_positionY + HERO_HIGH >= 400 && is_left == 1)
	{
		hero_vx = 0;
		can_left = 0;
	}
	else
	{
		can_left = 1;
	}
	if (real_positionX + HERO_WIDTH / 2.0 >= 4000 + 2 * 97 && real_positionX + HERO_WIDTH / 2.0 <= 4000 + 2 * 97 + 10
		&& cur_positionY + HERO_HIGH <= 467 && cur_positionY + HERO_HIGH >= 420 && is_left == 1)
	{
		hero_vx = 0;
		can_left = 0;
	}
	else
	{
		can_left = 1;
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 3410 + 97 && real_positionX + HERO_WIDTH / 2.0 <= 3410 + 97 + 10
		&& cur_positionY + HERO_HIGH <= 480 + 47 && cur_positionY + HERO_HIGH >= 480 && is_left == 1)
	{
		hero_vx = 0;
		can_left = 0;
	}
	else
	{
		can_left = 1;
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 2220 + 97 && real_positionX + HERO_WIDTH / 2.0 <= 2220 + 97 + 10
		&& cur_positionY + HERO_HIGH <= 430 + 47 && cur_positionY + HERO_HIGH >= 430 && is_left == 1)
	{
		hero_vx = 0;
		can_left = 0;
	}
	else
	{
		can_left = 1;
	}
	
//////////////////////////////////////////////砖块下边界 ///////////////////////////////////////////////////
	if (real_positionX + HERO_WIDTH / 2.0 >= 600 && real_positionX + HERO_WIDTH / 2.0 <= 600 + 3 * 97
		&& cur_positionY >= 460 + 47 && cur_positionY <= 470 + 47)
	{
		hero_vy = 0;
		cur_vy = 0;
		cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
		if (cur_positionY >= 600)
		{
			cur_positionY = HIGH - 120;

			is_jump = 0;
		}
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 891 && real_positionX + HERO_WIDTH / 2.0 <= 891 + 47 + 97
		&& cur_positionY >= 400 + 47 && cur_positionY <= 410 + 47)
	{
		hero_vy = 0;
		cur_vy = 0;
		cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
		if (cur_positionY >= 600)
		{
			cur_positionY = HIGH - 120;

			is_jump = 0;
		}
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 2550 && real_positionX + HERO_WIDTH / 2.0 <= 2550 + 97 * 2
		&& cur_positionY >= 400 + 47 && cur_positionY <= 410 + 47)
	{
		hero_vy = 0;
		cur_vy = 0;
		cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
		if (cur_positionY >= 600)
		{
			cur_positionY = HIGH - 120;

			is_jump = 0;
		}
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 4000 && real_positionX + HERO_WIDTH / 2.0 <= 4000 + 97 * 2
		&& cur_positionY >= 420 + 47 && cur_positionY <= 430 + 47)
	{
		hero_vy = 0;
		cur_vy = 0;
		cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
		if (cur_positionY >= 600)
		{
			cur_positionY = HIGH - 120;

			is_jump = 0;
		}
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 3410 && real_positionX + HERO_WIDTH / 2.0 <= 3410 + 97
		&& cur_positionY >= 480 + 47 && cur_positionY <= 490 + 47)
	{
		hero_vy = 0;
		cur_vy = 0;
		cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
		if (cur_positionY >= 600)
		{
			cur_positionY = HIGH - 120;

			is_jump = 0;
		}
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 2220 && real_positionX + HERO_WIDTH / 2.0 <= 2220 + 97
		&& cur_positionY >= 430 + 47 && cur_positionY <= 440 + 47)
	{
		hero_vy = 0;
		cur_vy = 0;
		cur_positionY += shift_y(&hero_vy, TIME, GRAVITY);
		if (cur_positionY >= 600)
		{
			cur_positionY = HIGH - 120;

			is_jump = 0;
		}
	}
	
//////////////////////////////////////////////触碰金币////////////////////////////////////////////////////////////
	if (real_positionX + HERO_WIDTH >= 988 && real_positionX <= 988 + 47
		&& cur_positionY <= 460 && cur_positionY >= 370 && is_jump) 
	{
		is_touch_brick = 1;
	}


	for (i = 0; i < 11; i++)
	{
		if (real_positionX >= gold[i].begin_x
			&&real_positionX <= gold[i].final_x
			&&cur_positionY >= gold[i].begin_y
			&&cur_positionY <= gold[i].final_y)
		{
			gold[i].is_touch = 1;

			if (gold[i].is_first_touch == 1 && gold[i].is_touch == 1)
			{
				score += 10;
				gold[i].is_first_touch = 0;
				mciSendString("play music_gold from 0", NULL, 0, NULL); //吃金币音效
			}
		}

		if (real_positionX >= gold[i].begin_x
			&&real_positionX <= gold[i].final_x
			&&cur_positionY + HERO_HIGH >= gold[i].begin_y
			&&cur_positionY + HERO_HIGH <= gold[i].final_y)
		{
			gold[i].is_touch = 1;

			if (gold[i].is_first_touch == 1 && gold[i].is_touch == 1)
			{
				score += 10;
				gold[i].is_first_touch = 0;
				mciSendString("play music_gold from 0", NULL, 0, NULL); //吃金币音效
			}
		}

		if (real_positionX + HERO_WIDTH / 2.0 >= gold[i].begin_x
			&&real_positionX + HERO_WIDTH / 2.0 <= gold[i].final_x
			&&cur_positionY >= gold[i].begin_y
			&&cur_positionY <= gold[i].final_y)
		{
			gold[i].is_touch = 1;
			if (gold[i].is_first_touch == 1 && gold[i].is_touch == 1)
			{
				score += 10;
				gold[i].is_first_touch = 0;
				mciSendString("play music_gold from 0", NULL, 0, NULL); //吃金币音效
			}
		}

		if (real_positionX + HERO_WIDTH / 2.0 >= gold[i].begin_x
			&&real_positionX + HERO_WIDTH / 2.0 <= gold[i].final_x
			&&cur_positionY + HERO_HIGH >= gold[i].begin_y
			&&cur_positionY + HERO_HIGH <= gold[i].final_y)
		{
			gold[i].is_touch = 1;
			if (gold[i].is_first_touch == 1 && gold[i].is_touch == 1)
			{
				score += 10;
				gold[i].is_first_touch = 0;
				mciSendString("play music_gold from 0", NULL, 0, NULL); //吃金币音效
			}
		}
	} 

///////////////////////////////////////////////触碰敌人判定//////////////////////////////////////////////////////////////
	for (i = 0; i < 6; i++)
	{
		if (enemy[i].is_exist == 1)
		{
			if (real_positionX >= enemy[i].cur_begin_x
				&&real_positionX <= enemy[i].cur_final_x
				&&cur_positionY + HERO_HIGH >= enemy[i].cur_begin_y - 10
				&& cur_positionY + HERO_HIGH <= enemy[i].cur_begin_y)
			{
				enemy[i].is_touch = 1;

				if (enemy[i].is_first_touch == 1 && enemy[i].is_touch == 1)
				{
					enemy[i].is_exist = 0;
					enemy[i].is_die = 1;
					score += 20;
					enemy[i].is_first_touch == 0;
					mciSendString("play music_enemy from 0", NULL, 0, NULL); //踩敌人

				}

			}

			if (real_positionX + HERO_WIDTH / 2.0 >= enemy[i].cur_begin_x
				&&real_positionX + HERO_WIDTH / 2.0 <= enemy[i].cur_final_x
				&&cur_positionY + HERO_HIGH >= enemy[i].cur_begin_y - 10
				&& cur_positionY + HERO_HIGH <= enemy[i].cur_begin_y)
			{
				enemy[i].is_touch = 1;

				if (enemy[i].is_first_touch == 1 && enemy[i].is_touch == 1)
				{
					enemy[i].is_exist = 0;
					enemy[i].is_die = 1;
					score += 20;
					enemy[i].is_first_touch == 0;
					mciSendString("play music_enemy from 0", NULL, 0, NULL); //踩敌人

				}

			}

			if (real_positionX >= enemy[i].cur_final_x
				&&real_positionX <= enemy[i].cur_final_x + 10
				&& cur_positionY + HERO_HIGH >= enemy[i].cur_begin_y)
			{
				is_die = 1;
			}

			if (real_positionX + HERO_WIDTH / 2.0 >= enemy[i].cur_begin_x - 10
				&& real_positionX + HERO_WIDTH / 2.0 <= enemy[i].cur_begin_x
				&& cur_positionY + HERO_HIGH >= enemy[i].cur_begin_y)
			{
				is_die = 1;
			}

		}
	}  

	/////////////////////////触碰花判定//////////////////////////////////

	if (real_positionX + HERO_WIDTH >= 2410 && real_positionX <= 2460
		&& cur_positionY + HERO_HIGH >= 368 && cur_positionY <= 438)//2410-map_position, 468 - 100, 50, -30 + 100
	{
		is_die = 1;
	}

	if (real_positionX + HERO_WIDTH >= 987 && real_positionX <= 1037
		&& cur_positionY + HERO_HIGH >= 329 && cur_positionY <= 399
		&& is_touch_brick)
	{
		is_die = 1;
	}
	

////////////////////////////////////////////终点台阶判定///////////////////////////////////////////////////////////
	if (real_positionX + HERO_WIDTH / 2.0 >= 5290 && real_positionX + HERO_WIDTH / 2.0 <= 5300
		&& cur_positionY + HERO_HIGH >= 558 && cur_positionY + HERO_HIGH <= 558 + 2 * 44.6
		&&is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
		can_right = 1;

	if (real_positionX + HERO_WIDTH / 2.0 >= 5300 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6
		&&cur_positionY + HERO_HIGH >= 558 && cur_positionY + HERO_HIGH <= 568)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 5290 + 43.6 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 && cur_positionY + HERO_HIGH <= 558
		&& is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
		can_right = 1;

	if (real_positionX + HERO_WIDTH / 2.0 >= 5300 + 43.6 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6 * 2
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 && cur_positionY + HERO_HIGH <= 568 - 44.6)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 5290 + 43.6 * 2 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6 * 2
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 * 2 && cur_positionY + HERO_HIGH <= 558 - 44.6
		&& is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
		can_right = 1;


	if (real_positionX + HERO_WIDTH / 2.0 >= 5300 + 43.6 * 2 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6 * 3
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 * 2 && cur_positionY + HERO_HIGH <= 568 - 44.6 * 2)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 5290 + 43.6 * 3 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6 * 3
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 * 3 && cur_positionY + HERO_HIGH <= 558 - 44.6 * 2
		&& is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
		can_right = 1;

	if (real_positionX + HERO_WIDTH / 2.0 >= 5300 + 43.6 * 3 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6 * 4
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 * 3 && cur_positionY + HERO_HIGH <= 568 - 44.6 * 3)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 5290 + 43.6 * 4 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6 * 4
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 * 4 && cur_positionY + HERO_HIGH <= 558 - 44.6 * 3
		&& is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
		can_right = 1;

	if (real_positionX + HERO_WIDTH / 2.0 >= 5300 + 43.6 * 4 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6 * 5
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 * 4 && cur_positionY + HERO_HIGH <= 568 - 44.6 * 4)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 5290 + 43.6 * 5 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6 * 5
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 * 5 && cur_positionY + HERO_HIGH <= 558 - 44.6 * 4
		&& is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
		can_right = 1;

	if (real_positionX + HERO_WIDTH / 2.0 >= 5300 + 43.6 * 5 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6 * 6
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 * 5 && cur_positionY + HERO_HIGH <= 568 - 44.6 * 5)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 5290 + 43.6 * 6 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6 * 6
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 * 6 && cur_positionY + HERO_HIGH <= 558 - 44.6 * 5
		&& is_right == 1)
	{
		hero_vx = 0;
		can_right = 0;
	}
	else
		can_right = 1;

	if (real_positionX + HERO_WIDTH / 2.0 >= 5300 + 43.6 * 6 && real_positionX + HERO_WIDTH / 2.0 <= 5300 + 43.6 * 8
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 * 6 && cur_positionY + HERO_HIGH <= 568 - 44.6 * 6)
	{
		is_jump = 0;
		cur_positionY -= shift_y(&hero_vy, TIME, GRAVITY);
	}

	if (real_positionX + HERO_WIDTH / 2.0 >= 5300 + 43.6 * 8 && real_positionX + HERO_WIDTH / 2.0 <= 5310 + 43.6 * 8
		&& cur_positionY + HERO_HIGH >= 558 - 44.6 * 6 && is_left == 1)
	{
		hero_vx = 0;
		can_left = 0;
	}
	else
		can_left = 1;

////////////////////////////////////游戏通关判定//////////////////////////////////////////
	if (real_positionX + HERO_WIDTH / 2.0 >= 5967)
	{
		is_success = 1;
		game_state = 3;
	}



}
