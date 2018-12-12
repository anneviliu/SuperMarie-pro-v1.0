/******************************************************************
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
int life = LIFE;
int world = 1;

 double cur_positionX = 0;
 double cur_positionY = HIGH-120;
 double old_positionX = 0;
 double old_positionY = HIGH - 120;
 double hero_vx = 0;
 double here_vy = 0;
 IMAGE img_hero[3], img_level1;
 int num = 0;

int main()
{
    double G = 9.8; //重力
	float h_max = 400; //最大高度
	float h_now = 0; //目前高度
	int is_jump = 0; //是否跳跃
	
	int temp = 0;

	short key_get = 0; //用于记录 Getanyckeystate的返回值
	int num = 0; //实现人物的步伐动作
	//double a_left_shift = shift(&hero_vx, TIME, FRICTION - ACCELERATION);
	//double a_right_shift = shift(&hero_vx, TIME, ACCELERATION - FRICTION);

	//

	//loadimage(&img_hero, _T("res\\主角.png"));
	//loadimage(&img_hero_mask, _T("res\\主角（遮罩）.png"));
	//loadimage(&img_level1, _T("res\\level1.jpg"));

	
	
				 //进入游戏
				 //显示人物的初始位置
				 //设置人物可站立位置，掉落至地图外死亡位置
	             //蘑菇与硬币生成
	if (temp == 0)
	{
		begin();
		temp++;
	}       
	if (temp)
	{
		game_show();
		preload();
		hero_move();
	}
	

	/*while (true)
	{					
		//putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);

		if (_kbhit()) 
		{	
			switch (hero_move()) //读取移动输入，返回值
			{
			case CMD_LEFT:
				if (cur_positionX > 0)
				{
					BeginBatchDraw();
					//putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
					//putimage(old_positionX, HIGH - 120, 35, 50, &img_hero, 210 + 50 * num, 80, SRCAND);
					//putimage(old_positionX, HIGH - 120, 35, 50, &img_hero_mask, 210 + 50 * num, 80, SRCINVERT);
					//cleardevice();	
					cur_positionX += shift(&hero_vx, TIME, FRICTION - ACCELERATION); //设定一个加速度，改变水平坐标
					//putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
					//putimage(old_positionX, HIGH - 120, 35, 50, &img_level1, old_positionX, HIGH - 120,SRCCOPY);
					//putimage(cur_positionX, HIGH - 120, 35, 50, &img_hero, 210+50*num, 80, SRCAND);
					//putimage(cur_positionX, HIGH - 120, 35, 50, &img_hero_mask, 210+50*num, 80, SRCINVERT);
					//cleardevice();
					FlushBatchDraw();
					EndBatchDraw();
					//old_positionX = cur_positionX;
					
					num++; //实现人物脚步
					if (num == 4)  
						num = 0;
					
					break;
				}
			case CMD_RIGHT:

				if (cur_positionX < (WIDTH - 35) / 2)
				{
					BeginBatchDraw();
					//putimage(cur_positionX, HIGH - 120, 35, 50, &img_level1, cur_positionX, HIGH - 120);
					//putimage(old_positionX, HIGH - 120, 35, 50, &img_level1, old_positionX, HIGH - 120, SRCCOPY);
					//clearrectangle(old_positionX, HIGH - 120 + 50, old_positionX + 35, HIGH - 120);
					//putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
					//putimage(old_positionX, HIGH - 120, 35, 50, &img_hero, 210 + 50 * num, 80, SRCAND);
					//putimage(old_positionX, HIGH - 120, 35, 50, &img_hero_mask, 210 + 50 * num, 80, SRCINVERT);
					cleardevice();					
					cur_positionX += shift(&hero_vx, TIME, ACCELERATION - FRICTION); //设定一个加速度，改变水平坐标
					//putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
					//putimage(cur_positionX, HIGH - 120, 35, 50, &img_hero, 210+50*num, 80, SRCAND);
					//putimage(cur_positionX, HIGH - 120, 35, 50, &img_hero_mask, 210+50*num, 80, SRCINVERT);
					//old_positionX = cur_positionX;
					FlushBatchDraw();
					EndBatchDraw();
					num++; //实现人物脚步
					if (num == 4)
						num = 0;
					//
					
					break;
				}	
			/*case CMD_JUMP:
				if (is_jump == 0 && cur_positionY >= HIGH - 120)
				{
					cur_positionY +=2*G;
				}
				if (is_jump == 1)
				{
                    cur_positionY -= G;
					h_now +=  G;
					if (h_now > h_max)
					{
						is_jump = 0;
						h_now = 0;
					}
				}
				if (is_jump == 0 && cur_positionY >= HIGH - 120)
				{
					is_jump = 1;
				}
				//cleardevice();
				BeginBatchDraw();
				putimage(cur_positionX, cur_positionY, 35, 50, &img_hero, 210, 80);
				EndBatchDraw();
				Sleep(10);
				break;*/
			/*case CMD_RELEASE:
				{
					if (hero_vx > 0)
					{
						//cleardevice();
						BeginBatchDraw();
						putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
						cur_positionX += shift(&hero_vx, TIME, -FRICTION);
						putimage(cur_positionX, HIGH - 120, 35, 50, &img_hero, 210, 80);
						EndBatchDraw();
					}
					else if (hero_vx < 0)
					{
						//cleardevice();
						BeginBatchDraw();
						putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
						cur_positionX += shift(&hero_vx, TIME, FRICTION);
						putimage(cur_positionX, HIGH - 120, 35, 50, &img_hero, 210, 80);
						EndBatchDraw();
					}
					break;
				}
			default:
				break;
			}
		}
		else 
		{				
			if (hero_vx > 0) 
			{
				cleardevice();
				BeginBatchDraw();
				putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
				cur_positionX += shift(&hero_vx, TIME, -FRICTION);
				putimage(cur_positionX, HIGH - 120, 35, 50, &img_hero, 210, 80);
				EndBatchDraw();
			}
			else if (hero_vx < 0) 
			{     
				cleardevice();
				BeginBatchDraw();
				putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
				cur_positionX += shift(&hero_vx, TIME, FRICTION);
				putimage(cur_positionX, HIGH - 120, 35, 50, &img_hero, 210, 80);
				EndBatchDraw();
			}
		}
		Sleep(80);
		         
		imgshow();
				 //打印改变位置后的人物并完成清屏相关
	             	  
	}*/
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