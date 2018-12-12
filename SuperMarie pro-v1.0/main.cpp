/******************************************************************
 *				       SuperMarie Pro V1.0	     	               *
  *			     By HDU_CBS Annevi ADobie Yuahwg 			   	    *
 *					 	  2018-11-26---						       *
******************************************************************/
				//									\\
               //									 \\
			  //									  \\

#include "MarieDisplayFunction.h"
#include "MarieActionFunction.h"
#include "control.h"
#include "Mdefine.h"
#include <stdbool.h>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#pragma comment(lib,"Winmm.lib")

//全局变量
int life = LIFE;
int world = 1;
extern int cur_positionX = 0;
extern int cur_positionY = 400;

double hero_vx = 0;
double here_vy = 0;


int main()
{
	float G = 7; //重力
	float H_MAX = 400;  //最大高度
	float H_NOW = 0;//目前高度
	int IS_JUMP = 0; //是否跳跃
	IMAGE Hero, Hero_mask, img_level1;
	int i=0;
	loadimage(&Hero, _T("res\\主角.png"));
	loadimage(&Hero_mask, _T("res\\主角（遮罩）"));
	loadimage(&img_level1, _T("res\\level1.png"));
	initgraph(WIDTH, HIGH);
	GameStart();
	cleardevice(); //菜单界面

	game_show(); //进入游戏
	Hero_Show(); //显示人物的初始位置
				 //设置人物可站立位置，掉落至地图外死亡位置
	             //蘑菇与硬币生成
	             //分数显示
	while (true)
	{
		if (_kbhit()) {
			switch (hero_move()) //读取移动输入，返回值
			{
			case CMD_LEFT:
				if (cur_positionX > 0)
				{
					cleardevice();
					BeginBatchDraw();
					putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
					cur_positionX += (int)shift(&hero_vx, TIME, FRICTION - ACCELERATION);
					putimage(cur_positionX, HIGH - 120, 35, 50, &Hero, 210, 80);
					EndBatchDraw();
					break;
				}
			case CMD_RIGHT:

				if (cur_positionX < (WIDTH - 35) / 2)
				{
					cleardevice();
					BeginBatchDraw();
					putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
					cur_positionX += (int)shift(&hero_vx, TIME, ACCELERATION - FRICTION);
					putimage(cur_positionX, HIGH - 120, 35, 50, &Hero, 210, 80);
					EndBatchDraw();
					break;
				}
			case CMD_JUMP:
				if (IS_JUMP == 0 && cur_positionY >= HIGH - 120)
				{
					cur_positionY +=2*G;
				}
				if (IS_JUMP == 1)
				{
                    cur_positionY -= G;
					H_NOW +=  G;
					if (H_NOW > H_MAX)
					{
						IS_JUMP = 0;
						H_NOW = 0;
					}
				}
				if (IS_JUMP == 0 && cur_positionY >= HIGH - 120)
				{
					IS_JUMP = 1;
				}
				cleardevice();
				BeginBatchDraw();
				putimage(cur_positionX, cur_positionY, 35, 50, &Hero, 210, 80);
				EndBatchDraw();
				Sleep(10);
				break;
			default:
				break;
			}
		}
		else {//没有输入操作时人物移动
			if (hero_vx > 0) {
				cleardevice();
				BeginBatchDraw();
				putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
				cur_positionX += (int)shift(&hero_vx, TIME, -FRICTION);
				putimage(cur_positionX, HIGH - 120, 35, 50, &Hero, 210, 80);
				EndBatchDraw();
			}
			else if (hero_vx < 0) {
				cleardevice();
				BeginBatchDraw();
				putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
				cur_positionX += (int)shift(&hero_vx, TIME, FRICTION);
				putimage(cur_positionX, HIGH - 120, 35, 50, &Hero, 210, 80);
				EndBatchDraw();
			}
		}
		Sleep(10);
		         
		        
				 //打印改变位置后的人物并完成清屏相关
	             	  
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
	system("pause");
	return 0;
}              