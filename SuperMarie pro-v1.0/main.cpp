﻿/******************************************************************
 *				       SuperMarie Pro V1.0	     	               *
  *			     By HDU_CBS Annevi ADobie Yuahwg 			   	    *
 *					 	  2018-11-26---						       *
******************************************************************/
				//									\\
               //									 \\
			  //									  \\



#include "main.h"
#pragma comment(lib,"Winmm.lib")


//全局变量
//============================================//
 int life = LIFE;
 int world = 1;

 //double acceleration_left = shift_x(&hero_vx, TIME, FRICTION - ACCELERATION);
 //double acceleration_right = shift_x(&hero_vx, TIME, ACCELERATION - FRICTION);
 //double friction = shift_x(&hero_vx, TIME, FRICTION);
// double friction_n = shift_x(&hero_vx, TIME, -FRICTION);

 double cur_positionX = 0;
 double cur_positionY = HIGH-120;
 double old_positionX = 0;
 double old_positionY = HIGH - 120;
 double real_positionX = 0;
 double real_positionY = HIGH - 120;
 double map_position = 0;
 double hero_vx = 0;
 double hero_vy = 0; //
 double cur_vx = 0; //当前水平速度记录
 double cur_vy = 0; //当前竖直方向速度记录
 double h_now = 0; //目前高度
 IMAGE img_hero[3], img_level1;
 int is_jump = 0; //是否跳跃
 int temp = 0;
 short key_get = 0; //用于记录 Getanyckeystate的返回值
 int num = 0; //实现人物的步伐动作
int main()
{
	
	if (temp == 0)
	{
		begin();
		temp++;
	}       
	if (temp)
	{
		game_show();
		preload();
		BeginBatchDraw();
		while (1)
		{
		    judge();
			hero_move();
			map_show();
			hero_show();

			FlushBatchDraw();
			EndBatchDraw();
			//HpSleep(100);
		}
	}

	
	             //背景移动
	             //人物射击（子弹发射，子弹飞行，子弹击中判定）
	             //人物射击动画与音效
	             //敌人显示，移动
	             //人物与敌人碰撞判定（人物矩形左部或右部与敌人矩形左部或右部，人物矩形下部与敌人上部）
	             //人物死亡判定
	             //人物死亡动画与音效载入
	             //如果死亡，弹出界面（重新开始或返回菜单）
	             //敌人死亡判定
	             //敌人死亡动画音效载入
	             //硬币与人物矩形接触判定
	             //吃到硬币动画与音效
	             //计分板变化
	             //人物与蘑菇接触判定
	             //吃到蘑菇动画与音效
	             //人物与终点接触判定
	             //抵达终点后动画与音效
	             //通关动画与音效
	             //返回菜单或进入下一关
	closegraph();
	system("pause");
	return 0;
}              