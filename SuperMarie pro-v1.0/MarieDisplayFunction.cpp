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
	int HELP_flag = 0;
	//图片资源的声明
	IMAGE img_preplay, img_test, img_start,img_help,img_exit;
	IMAGE img_help_page;
/////////////////////////////////////////////////////////////////

	initgraph(WIDTH, HIGH);

	//图片的加载
	loadimage(&img_preplay, _T("res\\level_1.png"));
	loadimage(&img_test, _T("res\\test.jpg"));
	loadimage(&img_start,_T("res\\开始游戏.png"));
	loadimage(&img_help, _T("res\\操作说明.png"));
	loadimage(&img_exit, _T("res\\退出游戏.png"));
	loadimage(&img_help_page, _T("res\\游戏帮助.png"));

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
		switch (click.uMsg) //当前鼠标消息
		{
		case WM_LBUTTONDOWN: //表示鼠标左键单击响应
			EndBatchDraw();  //结束批量绘制，并执行未完成的绘制任务

			if (click.x >= 540 && click.x <= 740 && click.y >= 235 && click.y <= 285 && HOME_flag==1 && INTRODUCTION_flag==0 && HELP_flag==0) //选择游戏开始
			{
				HOME_flag = 0;
				putimage(0, 0, &img_test); //测试按键
				break;
			}
			else if (click.x >= 540 && click.x <= 740 && click.y >= 300 && click.y <= 350 && HOME_flag == 1 && INTRODUCTION_flag == 0) //选择游戏帮助
			{
				HELP_flag = 1;
				cleardevice(); //这个函数用当前背景色清空屏幕，并将当前点移至 (0, 0)
				putimage(0, 0, &img_help_page);

			}
		default:
			break;
		}
	}
	//清空绘图缓存
	FlushBatchDraw();
	Sleep(2);

}
