#include "MarieDisplayFunction.h"
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include "Mdefine.h"
#include <stdlib.h>
#include "main.h"
#pragma comment(lib,"Winmm.lib")


///////////////菜单界面/////////////////

void game_start()
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
				game_state = 2; //开始游戏状态
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
				game_start();

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
				game_start();
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
	if (GetAsyncKeyState(VK_F5) && develop_flag == 0)
	{
		develop_mode();
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

/////////////////////////////////////////////////////////////

///////////////游戏正式开始主界面///////////////////////
void game_show()
{
	BeginBatchDraw();
	loadimage(&img_level1, _T("res\\level_1.png"));
	putimage(map_position, 0, WIDTH, HIGH, &img_level1, 0, 0);
	putimage(cur_positionX, HIGH - 120, HERO_WIDTH, HERO_HIGH, &img_hero_right[2], 210, 80, NOTSRCERASE);
	putimage(cur_positionX, HIGH - 120, HERO_WIDTH, HERO_HIGH, &img_hero_right[1], 210, 80, SRCINVERT);
	EndBatchDraw();
	old_positionX = cur_positionX;

	if (GetAsyncKeyState(VK_F5) && develop_flag == 0)
	{
		develop_mode();
	}
}

void show()
{
	BeginBatchDraw();
	map_show();
	gold_show();
	enemy_show(0);
	//putimage(old_positionX, old_positionY, 35, 50, &img_level1, old_positionX, HERO_INIT_Y, SRCCOPY);
	if (is_right == 1)
	{
		putimage(cur_positionX, cur_positionY, HERO_WIDTH, HERO_HIGH, &img_hero_right[2], 210 + 40 * num_hero, 82, NOTSRCERASE);
		putimage(cur_positionX, cur_positionY, HERO_WIDTH, HERO_HIGH, &img_hero_right[1], 210 + 40 * num_hero, 82, SRCINVERT);

	}
	if (is_left == 1)
	{
		putimage(cur_positionX, cur_positionY, HERO_WIDTH, HERO_HIGH, &img_hero_left[2], 958 - 40 * num_hero, 82, NOTSRCERASE);
		putimage(cur_positionX, cur_positionY, HERO_WIDTH, HERO_HIGH, &img_hero_left[1], 756 - 40 * num_hero, 82, SRCINVERT);
	}

	old_positionX = cur_positionX;
	old_positionY = cur_positionY;
	if (GetAsyncKeyState(VK_F5) && develop_flag == 0)
	{
		develop_mode();
	}
	EndBatchDraw();
}

void begin()
{

	//mciSendString("open res\\背景音乐.mp3 alias music_back", NULL, 0, NULL);
	//mciSendString("play music_back", NULL, 0, NULL);
	HWND hwnd = GetHWnd(); //获取窗口句柄
	SetWindowText(hwnd, "超级玛丽魔改版-V1.0"); //设置窗口标题
	//GameStart(); //显示菜单界面

	loadimage(&img_hero_right[1], _T("res\\主角.png"));
	loadimage(&img_hero_right[2], _T("res\\主角（遮罩）.png"));
	loadimage(&img_hero_left[1], _T("res\\主角朝左.png"));
	loadimage(&img_hero_left[2], _T("res\\主角朝左（遮罩）.png"));
	loadimage(&img_level1, _T("res\\level1.jpg"));
	loadimage(&img_hero_die[1], _T("res\\主角.png"));
	loadimage(&img_hero_die[2], _T("res\\主角（遮罩）.png"));
	loadimage(&img_gold[1],_T("res\\地图物件.png"));
	loadimage(&img_gold[2], _T("res\\地图物件（掩码）.png"));
	loadimage(&img_enemies,_T("res\\enemies.png"));

	//cleardevice();
}

void preload()
{
	mciSendString("open res\\小跳跃.mp3 alias music_jump", NULL, 0, NULL);
	mciSendString("open res\\背景音乐.mp3 alias music_back", NULL, 0, NULL);
	mciSendString("play music_back", NULL, 0, NULL); //背景音乐
	mciSendString("setaudio music_back volume to 70", NULL, 0, NULL);
	cur_positionX = 0;
	cur_positionY = HIGH - 120;
	real_positionX = 0;
	cur_positionX = 0;
	cur_positionY = HIGH - 120;
	old_positionX = 0;
	old_positionY = HIGH - 120;
	real_positionX = 0;
	real_positionY = HIGH - 120;
	map_position = 0;
	hero_vx = 0;
	hero_vy = 0; //
	cur_vx = 0; //当前水平速度记录 录
	cur_vy = 0; //当前竖直方向速度记
	h_now = 0; //目前高度
	is_jump = 0; //是否跳跃
	is_die = 0;
	is_replay = 0;
	can_forward = 1;
	game_state = 1;
	num_hero = 0; //实现人物的步伐动作

	gold[0].begin_x = 400;//初始化金币位置
	gold[0].begin_y = 430;
	gold[1].begin_x = 450;
	gold[1].begin_y = 380;
	gold[2].begin_x = 500;
	gold[2].begin_y = 430;
	for (int i = 0; i <= 2; i++) 
	{
		gold[i].final_x = gold[i].begin_x + 48;
		gold[i].final_y = gold[i].begin_y + 44;
	}
	for (int i = 0; i <= 2; i++)
	{
		gold[i].is_touch = 0;
	}

	enemy[0].cur_positionX = 500;
	enemy[0].cur_positionY = 590;
}

void map_show()
{
	putimage(0, 0, WIDTH, HIGH, &img_level1, map_position, 0);
}

void gold_show() //显示金币
{
	putimage(gold[0].begin_x - map_position, gold[0].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	putimage(gold[1].begin_x - map_position, gold[1].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	putimage(gold[2].begin_x - map_position, gold[2].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	putimage(gold[0].begin_x - map_position, gold[0].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	putimage(gold[1].begin_x - map_position, gold[1].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	putimage(gold[2].begin_x - map_position, gold[2].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
//	putimage(gold[0].begin_x - map_position, gold[0].begin_y, 15, 16, &img_gold, 0, 96);
//	putimage(gold[0].begin_x - map_position, gold[0].begin_y, 15, 16, &img_gold, 0, 96);
//	putimage(gold[0].begin_x - map_position, gold[0].begin_y, 15, 16, &img_gold, 0, 96);
	num_gold++;
	num_gold %= 4;
}

void enemy_show(int i) //i代表是第几个敌人
{
	putimage(enemy[i].cur_positionX-map_position,enemy[i].cur_positionY, 50, 50, &img_enemies,0, 46);
	enemy[i].cur_positionX -= 0.3;//每次敌人位置改变
}

void hero_die_show()
{
	mciSendString("stop music_back", NULL, 0, NULL);

	mciSendString("open res\\death.wav alias music_die", NULL, 0, NULL);
	mciSendString("play music_die", NULL, 0, NULL);
	putimage(cur_positionX, cur_positionY, HERO_DIE_WIDTH, HERO_DIE_HIGH, &img_hero_die[2], 410, 79, NOTSRCERASE);
	putimage(cur_positionX, cur_positionY, HERO_DIE_WIDTH, HERO_DIE_HIGH, &img_hero_die[1], 410, 79, SRCINVERT);
	//HpSleep(1.0 * 1000);

}

void hero_die_menu_show()
{
	IMAGE img_die_menu, img_replay, img_back_home,img_replay_icon,img_home_icon;

	int die_menu_flag = 1;

	loadimage(&img_die_menu, _T("res\\毛玻璃背景.jpg"));
	loadimage(&img_replay, _T("res\\重新开始.png"));
	loadimage(&img_back_home, _T("res\\回到主菜单.png"));
	loadimage(&img_replay_icon, _T("res\\重新开始图标.png"));
	loadimage(&img_home_icon, _T("res\\主菜单图标.png"));

	mciSendString("stop music_die", NULL, 0, NULL);
	mciSendString("open res\\游戏结束.mp3 alias music_gameover", NULL, 0, NULL);
	mciSendString("play music_gameover", NULL, 0, NULL);

	putimage(220, 60, 800, 500, &img_die_menu, 0, 0, SRCCOPY);
	putimage(520, 200, 200, 50, &img_replay, 0, 0);
	putimage(520, 400, 200, 50, &img_back_home, 0, 0);

	MOUSEMSG click;
	while (die_menu_flag)
	{
		click = GetMouseMsg();
		switch (click.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (click.x >= 520 && click.x <= 720 && click.y >= 200 && click.y <= 250 && die_menu_flag == 1 && is_replay == 0)
			{
				
				is_replay = 1;
				die_menu_flag = 0;
				mciSendString("stop music_gameover", NULL, 0, NULL);
				mciSendString("stop music_back", NULL, 0, NULL);
				game_state = 2; //游戏状态改变
				break;
			}
			if (click.x >= 520 && click.x <= 720 && click.y >= 400 && click.y <= 450 && die_menu_flag == 1 && is_replay == 0)
			{
				game_state = 1;
				die_menu_flag = 0;
				mciSendString("stop music_gameover", NULL, 0, NULL);
				mciSendString("stop music_back", NULL, 0, NULL);
				//cleardevice();
				//exit(0);
				break;
			}

		case WM_MOUSEMOVE: //实现按钮效果
			if (click.x >= 520 && click.x <= 720 && click.y >= 200 && click.y <= 250 && die_menu_flag == 1 && is_replay == 0)
			{
				putimage(520, 200, 200, 50, &img_replay_icon, 0, 0);
			}
			else
			{
				putimage(520, 200, 200, 50, &img_replay, 0, 0);

			}
			if (click.x >= 520 && click.x <= 720 && click.y >= 400 && click.y <= 450 && die_menu_flag == 1 && is_replay == 0)
			{
				putimage(520, 400, 200, 50, &img_home_icon, 0, 0);
			}
			else
			{
				putimage(520, 400, 200, 50, &img_back_home, 0, 0);
			}
		default:
			break;
		}

	}
}

void mic_control()
{
	if (is_jump == 1)
	{
		
		mciSendString("play music_jump from 0", NULL, 0, NULL);
	}
}

void develop_mode()
{
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
	char s3[50];
	sprintf(s3, "is_jump = %d", is_jump);
	outtextxy(10, 70, s3);
	char s4[50];
	sprintf(s4, "can_forward = %d", can_forward);
	outtextxy(10, 90, s4);
	char s5[50];
	sprintf(s5, "hero_vx = %lf", hero_vx);
	outtextxy(10, 110, s5);
	char s6[50];
	sprintf(s6, "old_positionX = %lf", old_positionX);
	outtextxy(10, 130, s6);
	char s7[50];
	for (int i = 0; i < 3; i++)
	{
		sprintf(s7, "is_touch = %d", gold[i].is_touch);
		outtextxy(10, 150+20*i, s7);
	}
}
///////////////////////////////////////////////////////////////////////