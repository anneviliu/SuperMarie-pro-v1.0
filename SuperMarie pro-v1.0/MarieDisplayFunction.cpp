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

////////////////////////////////////////

///////////////游戏正式开始主界面/////////
void game_show()
{
	BeginBatchDraw();
	loadimage(&img_level1, _T("res\\level_1.png"));
	putimage(map_position, 0, WIDTH, HIGH, &img_level1, 0, 0);
	putimage(cur_positionX, HIGH - 120, HERO_WIDTH, HERO_HIGH, &img_hero_right[2], 210, 80, NOTSRCERASE);
	putimage(cur_positionX, HIGH - 120, HERO_WIDTH, HERO_HIGH, &img_hero_right[1], 210, 80, SRCINVERT);
	final_show();
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
	develop_mode();
	flower_show();
	gold_show();
	score_show();
	enemy_show(0, 0);
	enemy_show(1, 0);
	between_enemy_show(2, 1555, 1978);//1546 1938   2066 2353
	between_enemy_show(3, 2481, 2962);//3670 4438
	between_enemy_show(4, 3672, 4473);
	between_enemy_show(5, 4700, 5600);
	brick_show();
	
	//final_show();

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
	
	
	FlushBatchDraw();
	EndBatchDraw();
}

void begin()
{
	mciSendString("open res\\金币.mp3 alias music_gold", NULL, 0, NULL);
	mciSendString("open res\\跳.mp3 alias music_jump", NULL, 0, NULL);
	mciSendString("open res\\踩敌人.mp3 alias music_enemy", NULL, 0, NULL);
	mciSendString("open res\\通关.mp3 alias music_success", NULL, 0, NULL);

	//mciSendString("open res\\背景音乐.mp3 alias music_back", NULL, 0, NULL);
	//mciSendString("play music_back", NULL, 0, NULL);
	HWND hwnd = GetHWnd(); //获取窗口句柄
	SetWindowText(hwnd, "超级玛丽魔改版-V1.0"); //设置窗口标题
	game_start(); //显示菜单界面

	loadimage(&img_hero_right[1], _T("res\\主角.png"));
	loadimage(&img_hero_right[2], _T("res\\主角（遮罩）.png"));
	loadimage(&img_hero_left[1], _T("res\\主角朝左.png"));
	loadimage(&img_hero_left[2], _T("res\\主角朝左（遮罩）.png"));
	loadimage(&img_level1, _T("res\\level1.png"));
	loadimage(&img_hero_die[1], _T("res\\主角.png"));
	loadimage(&img_hero_die[2], _T("res\\主角（遮罩）.png"));
	loadimage(&img_gold[1], _T("res\\地图物件.png"));
	loadimage(&img_gold[2], _T("res\\地图物件（掩码）.png"));
	loadimage(&img_enemies[1], _T("res\\enemies.png"));
	loadimage(&img_enemies[2], _T("res\\enemies(mask).png"));
	loadimage(&img_brick[1], _T("res\\tile_set.png"));
	loadimage(&img_brick[2], _T("res\\tile_set(mask).png"));
	loadimage(&img_score[1], _T("res\\ani.bmp"));
	loadimage(&img_score[2], _T("res\\ani(mask).png"));
	loadimage(&img_wh_brick[1], _T("res\\tile_set.png"));
	loadimage(&img_wh_brick[2], _T("res\\tile_set(mask).png"));
	loadimage(&img_flower[1], _T("res\\地图物件.png"));
	loadimage(&img_flower[2], _T("res\\地图物件（掩码）.png"));
	loadimage(&img_enemy_die[1], _T("res\\地图物件.png"));
	loadimage(&img_enemy_die[2], _T("res\\地图物件（掩码）.png"));
	loadimage(&img_final_step[1], _T("res\\终点.jpg"));
	loadimage(&img_final_step[2], _T("res\\终点（掩码）.png"));
	loadimage(&img_final_flag[1], _T("res\\终点.jpg"));
	loadimage(&img_final_flag[2], _T("res\\终点（掩码）.png"));
	loadimage(&img_final_home[1], _T("res\\终点.jpg"));
	loadimage(&img_final_home[2], _T("res\\终点（掩码）.png"));

	//cleardevice();
}

void preload()
{
	mciSendString("open res\\跳.mp3 alias music_jump", NULL, 0, NULL);
	mciSendString("open res\\背景音乐.mp3 alias music_back", NULL, 0, NULL);
	mciSendString("play music_back repeat", NULL, 0, NULL); //背景音乐
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
	num_hero = 0; //实现人物的步伐动作
	score = 0;
	gold[0].begin_x = 400;//初始化金币位置
	gold[0].begin_y = 430;
	gold[1].begin_x = 450;
	gold[1].begin_y = 380;
	gold[2].begin_x = 500;
	gold[2].begin_y = 430;
	gold[3].begin_x = 2600;
	gold[3].begin_y = 600;
	gold[4].begin_x = 2670;
	gold[4].begin_y = 600;
	gold[5].begin_x = 2740;
	gold[5].begin_y = 600;
	gold[6].begin_x = 4000;
	gold[6].begin_y = 375;
	gold[7].begin_x = 4070;
	gold[7].begin_y = 375;
	gold[8].begin_x = 4140;
	gold[8].begin_y = 375;
	gold[9].begin_x = 4900;
	gold[9].begin_y = 525;
	gold[10].begin_x = 4970;
	gold[10].begin_y = 525;
	for (int i = 0; i <= 10; i++)
	{
		gold[i].final_x = gold[i].begin_x + 48;
		gold[i].final_y = gold[i].begin_y + 44;
		gold[i].is_touch = 0;
		gold[i].is_first_touch = 1;
	}
//===================================================//
	enemy[0].cur_begin_x = 500;
	enemy[0].cur_begin_y = 594;
	enemy[1].cur_begin_x = 570;
	enemy[1].cur_begin_y = 594;
	enemy[2].cur_begin_x = 1800;//1546 1938   2066 2353
	enemy[2].cur_begin_y = 594;
	enemy[3].cur_begin_x = 2600;
	enemy[3].cur_begin_y = 594;
	enemy[4].cur_begin_x = 4200;
	enemy[4].cur_begin_y = 594;
	enemy[5].cur_begin_x = 5300;
	enemy[5].cur_begin_y = 594;
	for (int i = 0; i <= 5; i++) 
	{
		enemy[i].cur_final_x = enemy[i].cur_begin_x + 50;
		enemy[i].cur_final_y = enemy[i].cur_begin_y + 50;
		enemy[i].first_die_put = 0;
		enemy[i].is_exist = 1;
		enemy[i].is_die = 0;
		enemy[i].rec_x = 0;
		enemy[i].rec_y = 0;
		enemy[i].is_first_touch = 1;
		enemy[i].enemy_can_move = 1;
	}



}

void map_show()
{
	putimage(0, 0, WIDTH, HIGH, &img_level1, map_position, 0);
}

void gold_show() //显示金币
{
	if (!gold[0].is_touch)
		putimage(gold[0].begin_x - map_position, gold[0].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	if (!gold[1].is_touch)
		putimage(gold[1].begin_x - map_position, gold[1].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	if (!gold[2].is_touch)
		putimage(gold[2].begin_x - map_position, gold[2].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	if (!gold[3].is_touch)
		putimage(gold[3].begin_x - map_position, gold[3].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	if (!gold[4].is_touch)
		putimage(gold[4].begin_x - map_position, gold[4].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	if (!gold[5].is_touch)
		putimage(gold[5].begin_x - map_position, gold[5].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	if (!gold[6].is_touch)
		putimage(gold[6].begin_x - map_position, gold[6].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	if (!gold[7].is_touch)
		putimage(gold[7].begin_x - map_position, gold[7].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	if (!gold[8].is_touch)
		putimage(gold[8].begin_x - map_position, gold[8].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	if (!gold[9].is_touch)
		putimage(gold[9].begin_x - map_position, gold[9].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);
	if (!gold[10].is_touch)
		putimage(gold[10].begin_x - map_position, gold[10].begin_y, 48, 44, &img_gold[2], 0 + 50 * num_gold, 340, NOTSRCERASE);

	if (!gold[0].is_touch)
		putimage(gold[0].begin_x - map_position, gold[0].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	if (!gold[1].is_touch)
		putimage(gold[1].begin_x - map_position, gold[1].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	if (!gold[2].is_touch)
		putimage(gold[2].begin_x - map_position, gold[2].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	if (!gold[3].is_touch)
		putimage(gold[3].begin_x - map_position, gold[3].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	if (!gold[4].is_touch)
		putimage(gold[4].begin_x - map_position, gold[4].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	if (!gold[5].is_touch)
		putimage(gold[5].begin_x - map_position, gold[5].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	if (!gold[6].is_touch)
		putimage(gold[6].begin_x - map_position, gold[6].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	if (!gold[7].is_touch)
		putimage(gold[7].begin_x - map_position, gold[7].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	if (!gold[8].is_touch)
		putimage(gold[8].begin_x - map_position, gold[8].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	if (!gold[9].is_touch)
		putimage(gold[9].begin_x - map_position, gold[9].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	if (!gold[10].is_touch)
		putimage(gold[10].begin_x - map_position, gold[10].begin_y, 48, 44, &img_gold[1], 0 + 50 * num_gold, 340, SRCINVERT);
	num_gold++;
	num_gold %= 4;
	//FlushBatchDraw();

}

void enemy_show(int i, int direction) //i代表是第几个敌人，direction代表移动方向
{
	if (!enemy[i].is_die)
	{
		putimage(enemy[i].cur_begin_x - map_position, enemy[i].cur_begin_y, 50, 50, &img_enemies[2], 0, 46, NOTSRCERASE);
		putimage(enemy[i].cur_begin_x - map_position, enemy[i].cur_begin_y, 50, 50, &img_enemies[1], 0, 46, SRCINVERT);
	}
	if (!direction&&enemy[i].enemy_can_move==1)
	{
		
		enemy[i].cur_begin_x += ENEMY_SHIFT_LEFT;//敌人向左
		enemy[i].cur_final_x = enemy[i].cur_begin_x + 50;

	}
	if(direction!=0&& enemy[i].enemy_can_move ==1)
	{
		enemy[i].cur_begin_x += ENEMY_SHIFT_RIGHT;//敌人向右
		enemy[i].cur_final_x = enemy[i].cur_begin_x + 50;
	}

		if (enemy[i].is_die == 1&&enemy[i].first_die_put<=15)
		{
			
			//enemy[1].cur_begin_y = 10000;
			enemy[i].enemy_can_move = 0;
			enemy[i].first_die_put++;
			putimage(enemy[i].cur_begin_x, enemy[i].cur_begin_y, 65, 65, &img_enemy_die[2], 324, 527, NOTSRCERASE);
			putimage(enemy[i].cur_begin_x, enemy[i].cur_begin_y, 65, 65, &img_enemy_die[1], 324, 527, SRCINVERT);
			
			//enemy[1].is_die = 0;
		}			

}

void between_enemy_show(int i, double left, double right)//两个水管之间的敌人显示
{
	if (enemy[i].cur_begin_x <= left)
		cur_direction[i] = 1;
	else if (enemy[i].cur_final_x >= right)
		cur_direction[i] = 0;
	if (!enemy[i].is_die)
	{
		putimage(enemy[i].cur_begin_x - map_position, enemy[i].cur_begin_y, 50, 50, &img_enemies[2], 0, 46, NOTSRCERASE);
		putimage(enemy[i].cur_begin_x - map_position, enemy[i].cur_begin_y, 50, 50, &img_enemies[1], 0, 46, SRCINVERT);
	}
	if (!cur_direction[i]&& enemy[i].enemy_can_move == 1)
	{
		enemy[i].cur_begin_x += ENEMY_SHIFT_LEFT;
		enemy[i].cur_final_x = enemy[i].cur_begin_x + 50;
	}
	if(cur_direction[i]&&enemy[i].enemy_can_move == 1)
	{
		enemy[i].cur_begin_x += ENEMY_SHIFT_RIGHT;
		enemy[i].cur_final_x = enemy[i].cur_begin_x + 50;
	}


	if (enemy[i].is_die == 1&& enemy[i].first_die_put<=15)
	{
		enemy[i].enemy_can_move = 0;
		enemy[i].first_die_put ++;
		putimage(enemy[i].cur_begin_x-map_position, enemy[i].cur_begin_y, 65, 65, &img_enemy_die[2], 324, 527, NOTSRCERASE);
		putimage(enemy[i].cur_begin_x-map_position, enemy[i].cur_begin_y, 65, 65, &img_enemy_die[1], 324, 527, SRCINVERT);
		//enemy[3].cur_begin_y = 10000;

		//enemy[3].is_die = 0;
	}

}

void brick_show()
{
	putimage(600 - map_position, 460, 97, 48, &img_brick[2], 48, 0, NOTSRCERASE);
	putimage(600 - map_position, 460, 97, 48, &img_brick[1], 48, 0, SRCINVERT);
	putimage(697 - map_position, 460, 97, 48, &img_brick[2], 48, 0, NOTSRCERASE);
	putimage(697 - map_position, 460, 97, 48, &img_brick[1], 48, 0, SRCINVERT);
	putimage(794 - map_position, 460, 97, 48, &img_brick[2], 48, 0, NOTSRCERASE);
	putimage(794 - map_position, 460, 97, 48, &img_brick[1], 48, 0, SRCINVERT);
	putimage(891 - map_position, 400, 97, 48, &img_brick[2], 48, 0, NOTSRCERASE);
	putimage(891 - map_position, 400, 97, 48, &img_brick[1], 48, 0, SRCINVERT);

	putimage(988 - map_position, 400, 47, 47, &img_wh_brick[2], 1154 + 47, 0, NOTSRCERASE);
	putimage(988 - map_position, 400, 47, 47, &img_wh_brick[1], 1154 + 47, 0, SRCINVERT);
	putimage(2220 - map_position, 430, 97, 48, &img_brick[2], 48, 0, NOTSRCERASE);
	putimage(2220 - map_position, 430, 97, 48, &img_brick[1], 48, 0, SRCINVERT);
	wh_brick_count++;
	if (wh_brick_count == 3)
	{
		putimage(988 - map_position, 400, 47, 47, &img_wh_brick[2], 1154 + 47 * num_brick, 0, NOTSRCERASE);
		putimage(988 - map_position, 400, 47, 47, &img_wh_brick[1], 1154 + 47 * num_brick, 0, SRCINVERT);
	}
	if (wh_brick_count == 3)
	{
		wh_brick_count = 0;
		num_brick++;
	num_brick %= 4;
	}
	
	
	putimage(4000 - map_position, 420, 97, 48, &img_brick[2], 48, 0, NOTSRCERASE);
	putimage(4000 - map_position, 420, 97, 48, &img_brick[1], 48, 0, SRCINVERT);
	putimage(4097 - map_position, 420, 97, 48, &img_brick[2], 48, 0, NOTSRCERASE);
	putimage(4097 - map_position, 420, 97, 48, &img_brick[1], 48, 0, SRCINVERT);
	//FlushBatchDraw();
	
	
	if (real_positionX >= 2400)
	{
		SetWorkingImage(&img_level1);
		putimage(2550, 400, 97, 48, &img_brick[2], 48, 0, NOTSRCERASE);
		putimage(2550, 400, 97, 48, &img_brick[1], 48, 0, SRCINVERT);
		putimage(2550+97, 400, 97, 48, &img_brick[2], 48, 0, NOTSRCERASE);
		putimage(2550+97, 400, 97, 48, &img_brick[1], 48, 0, SRCINVERT);
		SetWorkingImage();
	}
	if (real_positionX >= 3410 && is_jump == 1)
	{
    	SetWorkingImage(&img_level1);
		putimage(3410, 480, 97, 48, &img_brick[2], 48, 0, NOTSRCERASE);
		putimage(3410, 480, 97, 48, &img_brick[1], 48, 0, SRCINVERT);  
		SetWorkingImage();
	}

      
}

void hero_die_show()
{
	mciSendString("close music_back", NULL, 0, NULL);
	mciSendString("open res\\death.wav alias music_die", NULL, 0, NULL);
	mciSendString("play music_die from 0", NULL, 0, NULL);
	mciSendString("setaudio music_die volume to 70", NULL, 0, NULL);

	putimage(cur_positionX, cur_positionY, HERO_DIE_WIDTH, HERO_DIE_HIGH, &img_hero_die[2], 410, 79, NOTSRCERASE);
	putimage(cur_positionX, cur_positionY, HERO_DIE_WIDTH, HERO_DIE_HIGH, &img_hero_die[1], 410, 79, SRCINVERT);
	//HpSleep(1.0 * 1000);

}

void hero_die_menu_show()
{
	IMAGE img_die_menu, img_replay, img_back_home, img_replay_icon, img_home_icon;

	int die_menu_flag = 1;

	loadimage(&img_die_menu, _T("res\\毛玻璃背景.jpg"));
	loadimage(&img_replay, _T("res\\重新开始.png"));
	loadimage(&img_back_home, _T("res\\回到主菜单.png"));
	loadimage(&img_replay_icon, _T("res\\重新开始图标.png"));
	loadimage(&img_home_icon, _T("res\\主菜单图标.png"));

	mciSendString("close music_die", NULL, 0, NULL);
	mciSendString("open res\\游戏结束.mp3 alias music_gameover", NULL, 0, NULL);
	mciSendString("play music_gameover", NULL, 0, NULL);
	mciSendString("setaudio music_gameover volume to 100", NULL, 0, NULL);

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

				game_state = 2; //游戏状态改变
				mciSendString("close music_gameover", NULL, 0, NULL);
				mciSendString("close music_back", NULL, 0, NULL);
				break;
			}
			if (click.x >= 520 && click.x <= 720 && click.y >= 400 && click.y <= 450 && die_menu_flag == 1 && is_replay == 0)
			{
				game_state = 1;
				die_menu_flag = 0;
				mciSendString("close music_gameover", NULL, 0, NULL);
				mciSendString("close music_back", NULL, 0, NULL);
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
		outtextxy(10, 150 + 20 * i, s7);
	}
	char s8[50];
	sprintf(s8, "is_get_score = %d", is_get_score);
	outtextxy(10, 210, s8);
	char s9[50];
	sprintf(s9, "touch_count = %d", touch_count);
	outtextxy(10, 230, s9);
	char s10[50];
	for (int i = 0; i < 6; i++)
	{
		sprintf(s10, "enemy[%d].is_touch = %d", i,enemy[i].is_touch);
		outtextxy(10, 250 + 20 * i, s10);
	}
	char s11[50];
	for (int i = 0; i < 11; i++)
	{
		sprintf(s11, "gold[%d].is_touch = %d", i, gold[i].is_touch);
		outtextxy(430, 0+ 20 * i, s11);
	}
	char s12[50];
	for (int i = 0; i < 6; i++)
	{
		sprintf(s12, "enemy[%d].beginX = %lf", i, enemy[i].cur_begin_x);
		outtextxy(630,  + 20 * i, s12);
	}
}

void flower_show()
{

	if (real_positionX >= 2200&&num_fw<=100)
	{
		SetWorkingImage(&img_level1);
		putimage(2410, 468 - 100, 50, -30 + 100, &img_flower[2], 0, 100, NOTSRCERASE);
		putimage(2410, 468 - 100, 50, -30 + 100, &img_flower[1], 0, 100, SRCINVERT);

		//num_fw++;
	}
	SetWorkingImage(NULL);
}

void final_show()
{  //5310,393
	SetWorkingImage(&img_level1);
	putimage(5310, 290, 347, 357, &img_final_step[2], 0, 394, NOTSRCERASE);
	putimage(5310, 290, 349, 357, &img_final_step[1], 0, 394, SRCINVERT);
	putimage(5810, 157, 200, 485, &img_final_flag[2], 565, 261, NOTSRCERASE);
	putimage(5810, 157, 200, 485, &img_final_flag[1], 565, 261, SRCINVERT);
	putimage(6100, 420, 238, 229, &img_final_home[2], 855, 520, NOTSRCERASE);
	putimage(6100, 420, 238, 229, &img_final_home[1], 855, 520, SRCINVERT);
	//FlushBatchDraw();
	SetWorkingImage();
	
	
}

void score_show()
{
		
	settextcolor(RED);
	settextstyle(35, 0, "楷体");
	setbkmode(TRANSPARENT);
	char score_txt[50];
	sprintf(score_txt, "得分 = %d", score);
	outtextxy(1000, 20, score_txt);
}

///////////////////////////////////////////////////////////////////////