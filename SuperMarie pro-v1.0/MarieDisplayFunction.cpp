#include "MarieDisplayFunction.h"
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include "Mdefine.h"
#pragma comment(lib,"Winmm.lib")
 
void GameStart()
{

	
	cleardevice();

/////////////////////////////////////////////////////////////////
	
    //是否处于当前页面
	int HOME_flag = 1; 
	int INTRODUCTION_flag = 0; 

	//图片资源的声明
	IMAGE img_preplay, img_test, img_start,img_help,img_exit;

/////////////////////////////////////////////////////////////////

	initgraph(WIDTH, HIGH);

	//图片的加载
	loadimage(&img_preplay, _T("res\\level_1.png"));
	loadimage(&img_test, _T("res\\test.jpg"));
	loadimage(&img_start,_T("res\\开始游戏.png"));
	loadimage(&img_help, _T("res\\操作说明.png"));
	loadimage(&img_exit, _T("res\\退出游戏.png"));

	//音乐加载
	mciSendString("open res\\背景音乐.mp3 alias music_back", NULL, 0, NULL);
	mciSendString("play music_back", NULL, 0, NULL);
	
	//图片输出
	putimage(0, 0, WIDTH, HIGH, &img_preplay, 0, 0);
	putimage(0, y, &img_test);
	putimage(540, 235, &img_start);
	putimage(540, 300, &img_help);
	putimage(540, 365, &img_exit);

	MOUSEMSG click;
	while (HOME_flag)
	{
		BeginBatchDraw();
		click = GetMouseMsg();
		switch (click.uMsg)
		{
		case WM_LBUTTONDOWN:
			EndBatchDraw();



			if (click.x >= 540 && click.x <= 740 && click.y >= 235 && click.y <= 285 && HOME_flag==1 && INTRODUCTION_flag==0)
			{
				HOME_flag = 0;
				putimage(0, 0, &img_test);

				 
			}

		default:
			break;
		}
	}






	//清空绘图缓存
	FlushBatchDraw();
	Sleep(2);

}
