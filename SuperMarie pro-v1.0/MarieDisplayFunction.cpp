#include "MarieDisplayFunction.h"
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include "Mdefine.h"
#include <stdlib.h>
#include "main.h"
#pragma comment(lib,"Winmm.lib")

    
///////////////菜单界面/////////////////

void GameStart()
{
	initgraph(WIDTH, HIGH);
	IMAGE img_preplay, img_test, img_start, img_help, img_exit;
	IMAGE img_back;
	IMAGE img_start_I, img_help_I, img_introduction_I, img_exit_I;
	IMAGE img_level1;
	IMAGE img_introductionButton;
	loadimage(&img_preplay, _T("res\\level_1.png"));
	loadimage(&img_start, _T("res\\开始游戏按钮.png"));
	loadimage(&img_help, _T("res\\操作说明按钮.png"));
	loadimage(&img_exit, _T("res\\退出游戏按钮.png"));
	loadimage(&img_introductionButton, _T("res\\游戏介绍按钮.png"));
	loadimage(&img_start_I, _T("res\\开始游戏按钮（放上）.png"));
	loadimage(&img_help_I, _T("res\\操作说明按钮（放上）.png"));
	loadimage(&img_introduction_I, _T("res\\游戏介绍按钮（放上）.png"));
	loadimage(&img_exit_I, _T("res\\退出游戏按钮（放上）.png"));

////////////////////////////////////////////////////////////////////////////////////////////
															
    //是否处于当前页面
	int HOME_flag = 1; 
	int INTRODUCTION_flag = 0; 
	int HELP_flag = 0;
	int ESC_flag = 0;
	
////////////////////////////////////////////////////////////////////////////////////////////


	
	//图片输出
	
		putimage(0, 0, WIDTH, HIGH, &img_preplay, 0, 0);
		putimage(540, 235, &img_start);	//输出菜单界面
		putimage(540, 300, &img_help);
		putimage(540, 365, &img_introductionButton);
		putimage(540, 430, &img_exit);

		MOUSEMSG click;
		while (HOME_flag)
		{
			click = GetMouseMsg();
			switch (click.uMsg) //当前鼠标消息
			{
			case WM_LBUTTONDOWN: //表示鼠标左键单击响应

				//选择游戏开始
				if (click.x >= 540 && click.x <= 740 && click.y >= 235 && click.y <= 285 && HOME_flag == 1 && INTRODUCTION_flag == 0 && HELP_flag == 0) 
				{
					HOME_flag = 0;
					break; //终止循环，正式开始游戏，执行主函数中的下一个函数。
				}

				//选择游戏帮助
				else if (click.x >= 540 && click.x <= 740 && click.y >= 300 && click.y <= 350 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0) 
				{
					HELP_flag = 1;
					HOME_flag = 0;
					cleardevice(); //这个函数用当前背景色清空屏幕，并将当前点移至 (0, 0)
					help_page(); // 调用HelpPage函数 显示 操作说明界面；
					ESC_flag = _getch(); //显示帮助界面后，随时准备获取用户的键盘输入。
				}
				
				//当按下esc键时返回上一级（->帮助<-）
				if (ESC_flag == ESC && HOME_flag == 0 && HELP_flag == 1 && INTRODUCTION_flag == 0) 
				{
					HOME_flag = 1, HELP_flag = 0, INTRODUCTION_flag = 0;
					cleardevice(); //这个函数用当前背景色清空屏幕，并将当前点移至 (0, 0)
					//重新回到主界面
					GameStart();

				}
				
				//选择 "游戏介绍"
				 if (click.x >= 540 && click.x <= 740 && click.y >= 365 && click.y <= 415 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0)
				{

					INTRODUCTION_flag = 1;
					HOME_flag = 0;
					HELP_flag = 0;
					cleardevice();
					introduction_Page();

				    //显示介绍界面后，随时准备获取用户的键盘输入。
					ESC_flag = _getch();
				}

				 //当按下esc键时返回上一级（->介绍<-）
				if (ESC_flag == ESC && HOME_flag == 0 && HELP_flag == 0 && INTRODUCTION_flag == 1)
				{
					HOME_flag = 1, HELP_flag = 0, INTRODUCTION_flag = 0;
					cleardevice(); //这个函数用当前背景色清空屏幕，并将当前点移至 (0, 0)
					//重新回到主界面
					GameStart();
				}
				
				if (click.x >= 540 && click.x <= 740 && click.y >= 430 && click.y <= 480 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0) //点击退出游戏
					exit(0);
					
			case WM_MOUSEMOVE: //检测鼠标移动（按钮效果所在）

				if (click.x >= 540 && click.x <= 740 && click.y >= 235 && click.y <= 285 && HOME_flag == 1 && INTRODUCTION_flag == 0 && HELP_flag == 0)
					putimage(540, 235, &img_start_I);
				else
					putimage(540, 235, &img_start);

				if (click.x >= 540 && click.x <= 740 && click.y >= 300 && click.y <= 350 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0)
					putimage(540, 300, &img_help_I);
				else
					putimage(540, 300, &img_help);

				if (click.x >= 540 && click.x <= 740 && click.y >= 365 && click.y <= 415 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0)
					putimage(540, 365, &img_introduction_I);
				else
					putimage(540, 365, &img_introductionButton);
				if (click.x >= 540 && click.x <= 740 && click.y >= 430 && click.y <= 480 && HOME_flag == 1 && HELP_flag == 0 && INTRODUCTION_flag == 0) 
					putimage(540, 430, &img_exit_I);
				else
					putimage(540, 430, &img_exit);

			    default:
				break;
			}
		}
		//清空绘图缓存
	FlushBatchDraw();
	Sleep(2);
	}
	
void help_page()
{
	IMAGE img_help_page;
	loadimage(&img_help_page, _T("res\\游戏帮助.png"));
	putimage(0, 0, &img_help_page); //输出帮助页面
}

void introduction_Page()
{
	IMAGE img_introductionPage;
	loadimage(&img_introductionPage, _T("res\\游戏介绍.png"));
	putimage(0, 0, &img_introductionPage); //输出游戏介绍界面

}

///////////////////////////////////////

///////////////游戏正式开始主界面///////////////////////
void game_show()
{
	BeginBatchDraw();
	loadimage(&img_level1, _T("res\\level_1.png"));
	putimage(map_position, 0, WIDTH, HIGH, &img_level1, 0, 0);
	putimage(cur_positionX, HIGH - 120, 35, 50, &img_hero[2], 210, 80, NOTSRCERASE);
	putimage(cur_positionX, HIGH - 120, 35, 50, &img_hero[1], 210 , 80, SRCINVERT);
	EndBatchDraw();
	old_positionX = cur_positionX;

}

void show()
{
	BeginBatchDraw();
	map_show();
	//putimage(old_positionX, old_positionY, 35, 50, &img_level1, old_positionX, HERO_INIT_Y, SRCCOPY);
	putimage(cur_positionX, cur_positionY, 35, 50, &img_hero[2], 210+40*num, 82, NOTSRCERASE);
	putimage(cur_positionX, cur_positionY, 35, 50, &img_hero[1], 210+40*num, 82, SRCINVERT);
	
	old_positionX = cur_positionX;
	old_positionY = cur_positionY;

	settextcolor(YELLOW);
	settextstyle(16, 0, "宋体");
	char s[100];
	sprintf(s, "cur_positionX=%lf cur_positionY=%lf", cur_positionX, cur_positionY);
	outtextxy(10, 10, s);
	settextcolor(YELLOW);
	settextstyle(16, 0, "宋体");
	char s1[100];
	sprintf(s1, "real_positionX=%lf,real_positionY=%lf", real_positionX, real_positionY);
	outtextxy(10, 30, s1);
	settextcolor(YELLOW);
	settextstyle(16, 0, "宋体");
	char s2[100];
	sprintf(s2, "map_position = %lf", map_position);
	outtextxy(10, 50, s2);

	EndBatchDraw();
}

void begin()
{
	//mciSendString("open res\\背景音乐.mp3 alias music_back", NULL, 0, NULL);
	//mciSendString("play music_back", NULL, 0, NULL);

	HWND hwnd = GetHWnd(); //获取窗口句柄
	SetWindowText(hwnd, "超级玛丽魔改版-V1.0"); //设置窗口标题
	GameStart(); //显示菜单界面
	loadimage(&img_hero[1], _T("res\\主角.png"));
	loadimage(&img_hero[2], _T("res\\主角（遮罩）.png"));
	loadimage(&img_level1, _T("res\\level1.jpg"));
	cleardevice(); 
}

void preload()
{
	cur_positionX = 0;
	cur_positionY = HIGH - 120;
}

void map_show()
{
	putimage(0, 0, WIDTH, HIGH, &img_level1, map_position, 0);
}

///////////////////////////////////////////////////////////////////////