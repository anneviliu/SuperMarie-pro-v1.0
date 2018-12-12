#include"MarieActionfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include "Mdefine.h"
#include <graphics.h>
#include "main.h"
#include "MarieDisplayFunction.h"

void hero_move()
{
	//用GetAsynckeyState函数解决按键延迟问题
	while (1)
	{


		if (GetAsyncKeyState(VK_LEFT))
		{
			//cur_positionX -= 10;
			cur_positionX += shift(&hero_vx, TIME, FRICTION - ACCELERATION); //设定一个加速度，改变水平坐标
			num++;
			if (num == 4)
				num = 1;
			hero_show();
		}
		else
		{
			if (hero_vx < 0)
			{
				cur_positionX += shift(&hero_vx, TIME, FRICTION);
				num++;
				if (num == 4)
					num = 1;
				hero_show();

			}
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			//cur_positionX += 10; 
			cur_positionX += shift(&hero_vx, TIME, ACCELERATION - FRICTION);//设定一个加速度，改变水平坐标
			num++;
			if (num == 4)
				num = 1;
			hero_show();

			
		}
		else
		{
			if (hero_vx > 0)
			{
				cur_positionX += shift(&hero_vx, TIME, -FRICTION);
				num++;
				if (num == 4)
					num = 1;
				hero_show();

			}
		}
		Sleep(1);
	}
	
	/*if (GetAsyncKeyState(VK_UP))
	{
		return CMD_JUMP;
	}*/
	
	/*char key = _getch();
	switch (key)
	{

	 case 'a':
	 case 'A':
		return CMD_LEFT;
		break;
		
	 case 'd':
	 case 'D':
		 return CMD_RIGHT;
		break;
	 case 'w':
	 case'W':
		 return CMD_JUMP;
	default:
		break;
	}*/
}


double shift(double *v,double t,double a){
	double s = *v * t + 1 / 2.0*a*t*t;
	if (fabs(*v) >= 10&&a*(*v)>0)
		return s;
	*v = *v + a * t;
	return s;
}